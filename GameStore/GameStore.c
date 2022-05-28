#include<stdio.h>
#include <windows.h>
#include <GL/glut.h>

int graphicRow, userInput;

int m;
int i, row;
int o,n,k;
int accumulatedPoints = 0;
float profit, money;

int nr;
int ptStea;

int max , ip;

struct Steam {
	char Nume[20];
	char Rating[20];
	char Tip[20];
	float Pret;
	int nrComentari;
	char ReleseData[20];
	char Developer[20];
	int CopiiVand;
	int nrLuni;
	int nrInapoiar;
	float cost;
	int punct;
};

struct Steam  gameList[20];

void processGameInformation() {

	FILE *gamesFile;
	gamesFile = fopen("Games.txt","r");

	printf("Nume: Rating: TipulP: Pret: Nr/Comentarii: RELEASE/DATE: DEVELOPER: Nr/copii/vandute: Nr/lunii/in/magazin: Nr/Copii/inapoiate: cost: Puncte:\n\n");
	fflush(stdout);

	row = 0;
	while( fscanf(gamesFile, "%s%s%s%f%d%s%s%d%d%d%f%d", gameList[row].Nume,  gameList[row].Rating, gameList[row].Tip, &gameList[row].Pret, &gameList[row].nrComentari , gameList[row].ReleseData, gameList[row].Developer, &gameList[row].CopiiVand, &gameList[row].nrLuni, &gameList[row].nrInapoiar, &gameList[row].cost, &gameList[row].punct) != EOF)
	{
		printf("%s %s %s %.2f %d %s %s %d %d %d %.2f %d\n",gameList[row].Nume, gameList[row].Rating ,gameList[row].Tip, gameList[row].Pret, gameList[row].nrComentari , gameList[row].ReleseData, gameList[row].Developer, gameList[row].CopiiVand, gameList[row].nrLuni, gameList[row].nrInapoiar, gameList[row].cost, gameList[row].punct);
		fflush(stdout);

		if(gameList[row].Pret > 0)
		{
			money = (float)(gameList[row].Pret * gameList[row].CopiiVand) - (float)(gameList[row].Pret * gameList[row].nrInapoiar);
			printf("\nBanii optinuti sunt: %.2f\n", money);
			fflush(stdout);

			profit = (float)money - (float)gameList[row].cost;
			printf("\nProfitul optinut este: %.2f\n\n", profit);
			fflush(stdout);
		}
		else
		{
			 printf("\nJocul este 'free to play'.\n");
			 fflush(stdout);
		}


		if (gameList[row].punct > 0 && gameList[row].punct < 10)
		{
			accumulatedPoints++;
		}

		if (gameList[row].CopiiVand == gameList[row].nrInapoiar)
		{
			accumulatedPoints--;
		}

	    if (profit > gameList[row].cost)
		{
			accumulatedPoints++;
		}

        FILE *graphicsFile;
        graphicsFile = fopen("Graphics.txt","a");

		if(accumulatedPoints < 4)
		{
		   fprintf(graphicsFile,"%d -- %s\n", accumulatedPoints,gameList[row].Nume);
		}
		else
		{
		   fprintf(graphicsFile,"%d -- %s\n",accumulatedPoints / 2,gameList[row].Nume) ;
		}
		fclose(graphicsFile);


    	FILE *gameDetailsFile;
    	gameDetailsFile = fopen("GameDetails.txt","a");

    	fprintf(gameDetailsFile,"%s --- Banii: %.2f, Profitul: %.2f, %d\n ", gameList[row].Nume, money, profit, accumulatedPoints);
    	fflush(stdout);

    	fclose(gameDetailsFile);

    	row++;
	}

 	fclose(gamesFile);
}

void addMoreInformation()
{
	FILE *gamesFile;
	gamesFile = fopen("Games.txt","a");

	fscanf(gamesFile,"%d",&i);
	printf("\n Adaugati : Numele\n");
   	fflush(stdout);

   	scanf("%s",gameList[i + o].Nume);

	printf("\n Adaugati : Rating jocului (Ex : VeriPozitiv ,Avrege ,Negative ) \n");
	fflush(stdout);
	scanf("%s", gameList[i + o].Rating);

	printf("\n Adaugati :  Tip-ul jocului\n");
   	fflush(stdout);
	scanf("%s", gameList[i + o].Tip);

 	printf("\n Adaugati : Pretul\n");
	fflush(stdout);
	scanf("%f", &gameList[i + o].Pret);

 	printf("\n Adaugati :   Nr de Comentari\n");
	fflush(stdout);
	scanf("%d", &gameList[i + o]. nrComentari);

 	printf("\n Adaugati :Relese Data\n");
	fflush(stdout);
	scanf("%s", gameList[i + o].ReleseData);

  	printf("\n Adaugati :  Scrieti Developer-ul \n");
	fflush(stdout);
	scanf("%s", gameList[i + o].Developer);

  	printf("\n Adaugati :   Nr de Copii Vand\n");
	fflush(stdout);
	scanf("%d", &gameList[i + o]. CopiiVand);

  	printf("\n Adaugati :   Nr de Luni in magazin\n");
	fflush(stdout);
	scanf("%d", &gameList[i + o]. nrLuni);

  	printf("\n Adaugati :   Nr de inapoieri in magazin\n");
	fflush(stdout);
	scanf("%d", &gameList[i + o]. nrInapoiar);

  	printf("\n Adaugati :   Scrieti costul pt construirea produsului\n");
	fflush(stdout);
	scanf("%f", &gameList[i + o].cost);

	printf("\n Adaugati :   Scrieti punctajul (1->10)\n");
	fflush(stdout);
	scanf("%d", &gameList[i + o].punct);

	fprintf(gamesFile,"\n%s %s %s %.2f %d %s %s %d %d %d %.2f %d", gameList[i+o].Nume, gameList[i+o].Rating, gameList[i+o].Tip, gameList[i+o].Pret, gameList[i+o].nrComentari, gameList[i+o].ReleseData, gameList[i+o].Developer, gameList[i+o].CopiiVand, gameList[i+o].nrLuni, gameList[i+o].nrInapoiar, gameList[i+o].cost, gameList[i + o].punct);
	fflush(stdout);

	printf("Doriti saw mai adaugati alte informati : 1 = Da , 2 = Nu\n");
	fflush(stdout);

    scanf("%d",&userInput);
	fclose(gamesFile);

	if(userInput == 1)
	{
		o = o + 1;
		addMoreInformation();
	}
	else
	{
		printf("Sunteti sigur ca nu mai doriti sa puneti informatii? 1 = Da , 2 = Nu\n:");
		fflush(stdout);
		scanf("%d",&userInput);

		if(userInput == 1)
		{
			processGameInformation();
		}
		else if (userInput != 1)
		{
			o = o + 1;
			addMoreInformation();
		}
	}
}

void displayStar() {
	FILE *graphicsFile;
	graphicsFile = fopen("Graphics.txt", "r");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	fscanf(graphicsFile, "%d", &graphicRow);

	for(m = 0 ; m < graphicRow ; m++) {

		glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);

		glColor3f(1, 1, 0);
		glVertex3f(-0.60 + m * 0.5  , 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.42 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.58 + m * 0.5, 0.68, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.64 + m * 0.5, 1, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.68 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.60 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.68 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.7 + m * 0.5, 0.68, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.86 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.64 + m * 0.5, 0.63, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.7 + m * 0.5, 0.68, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.82 + m * 0.5, 0.43, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.64 + m * 0.5, 0.63, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.58 + m * 0.5, 0.68, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.51 + m * 0.5, 0.43, 0);

		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		glVertex3f(-0.68 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.60 + m * 0.5, 0.77, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.7 + m * 0.5, 0.68, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.64 + m * 0.5, 0.63, 0);

		glColor3f(1, 1, 0);
		glVertex3f(-0.4 + m * 0.5, 0.77, 0);

		glEnd();

		glFlush();
	}

	fclose(graphicsFile);
}

void displaySquare()
{
	for(i = 0; i < 6; i++){
		glBegin(GL_QUADS);
		glColor3f(0.0f, i/5.0f, 1.0f);

		glVertex2f(-0.8 + i * 0.25, -0.5);
		glVertex2f(-0.8 + i * 0.25 + 0.22, -0.5);
		glVertex2f(-0.8 + i * 0.25 + 0.22, -0.5 + row / 10.0);
		glVertex2f(-0.8 + i * 0.25, -0.5 + row / 10. );
		glEnd();
	}

	glFlush();
}

void showGraphics(int userInput){
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(300, 300);


	if(userInput == 1)
	{
		glutCreateWindow("Star view ");
		glutDisplayFunc(displayStar);
	}
	else if(userInput == 2)
	{
		glutCreateWindow("Bar Chart view");
		glutDisplayFunc(displaySquare);
	}
	else if (userInput == 3)
	{

	}

	glutMainLoop();
}

int main(int argc, char** argv) {
	printf("Ati dori sa mai adacugati continut in fisier :  1 = DA  ,2 = NU \n");
	fflush(stdout);

	scanf("%d",&userInput);

	if(userInput == 1) {
		addMoreInformation();
	}
	else {
		processGameInformation();
	}

	printf("In ce mod ati dori sa vizionati datele? (1, 2, 3)\n");
	fflush(stdout);

	scanf("%d",&userInput);

	if(userInput > 0 && userInput < 3)
	{
		glutInit(&argc, argv);
		showGraphics(userInput);
	}
	else
	{
		printf("Nu ati ales un Mod Grafic. Programul se va inchide.\n");
		fflush(stdout);
	}

	return 0;
}






