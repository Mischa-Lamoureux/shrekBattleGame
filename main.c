#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define ShrekDamage 7
#define DonkeyDamage 6
#define GingerDamage 5
#define FionaDamage 4
#define DragonDamage 7
#define PrinceDamage 6
#define LordDamage 5
#define RumpDamage 6
#define FairyDamage 5
#define WitchDamage 4

#define ShrekSDamage 8
#define DonkeySDamage 7
#define GingerSDamage 6
#define FionaSDamage 6
#define DragonSDamage 8
#define PrinceSDamage 7
#define LordSDamage 6
#define RumpSDamage 8
#define FairySDamage 6
#define WitchSDamage 6

#define ShrekHealth 21
#define DonkeyHealth 16
#define GingerHealth 19
#define FionaHealth 15
#define DragonHealth 20
#define PrinceHealth 15
#define LordHealth 21
#define RumpHealth 15
#define FairyHealth 20
#define WitchHealth 15

#define ShrekHeals 2
#define DonkeyHeals 3
#define GingerHeals 3
#define FionaHeals 4
#define DragonHeals 2
#define PrinceHeals 3
#define LordHeals 2
#define RumpHeals 3
#define FairyHeals 3
#define WitchHeals 3

#define ShrekColour 10
#define DonkeyColour 8
#define GingerColour 6
#define FionaColour 5
#define DragonColour 4
#define PrinceColour 13
#define LordColour 12
#define RumpColour 14
#define FairyColour 11
#define WitchColour 2


void delay(unsigned int mseconds)//for delays
{
clock_t goal = mseconds + clock();
while (goal > clock());
}

struct character//Kai
{
    int Name, Magic, Speed, Healsremain, Defaulthealth, Health, Damage, Specialdamage, Roundssincespecial, Roundwins;
};

void SetColor(int ForgC)  //code for changing colour taken from
                          //http://www.codeincodeblock.com/2011/03/changing-text-color-in-codeblock.html
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                     //Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void Welcome() //Reid
               //text generator used: http://patorjk.com/software/taag/#p=display&f=Big&t=
{
     printf(" _____ _            _____       _        ____        _   _   _               __  ");
     SetColor(10);
     printf(" ____  _              _    ");
     SetColor(15);
     printf("                 _   _____     _                _     _ \n");
     printf("|_   _| |__   ___  | ____|_ __ (_) ___  | __ )  __ _| |_| |_| | ___    ___  / _| ");
     SetColor(10);
     printf("/ ___|| |__  _ __ ___| | __");
     SetColor(15);
     printf("  __ _ _ __   __| | |  ___| __(_) ___ _ __   __| |___| |\n");
     printf("  | | | '_ \\ / _ \\ |  _| | '_ \\| |/ __| |  _ \\ / _` | __| __| |/ _ \\  / _ \\| |_  ");
     SetColor(10);
     printf("\\___ \\| '_ \\| '__/ _ \\ |/ /");
     SetColor(15);
     printf(" / _` | '_ \\ / _` | | |_ | '__| |/ _ \\ '_ \\ / _` / __| |\n");
     printf("  | | | | | |  __/ | |___| |_) | | (__  | |_) | (_| | |_| |_| |  __/ | (_) |  _| ");
     SetColor(10);
     printf(" ___) | | | | | |  __/   < ");
     SetColor(15);
     printf("| (_| | | | | (_| | |  _|| |  | |  __/ | | | (_| \\__ \\_|\n");
     printf("  |_| |_| |_|\\___| |_____| .__/|_|\\___| |____/ \\__,_|\\__|\\__|_|\\___|  \\___/|_|   ");
     SetColor(10);
     printf("|____/|_| |_|_|  \\___|_|\\_\\");
     SetColor(15);
     printf(" \\__,_|_| |_|\\__,_| |_|  |_|  |_|\\___|_| |_|\\__,_|___(_)\n");
     printf("                         |_|                                                     ");
     printf("                                                        \n");
}

void WinScreen(int player) //Reid
                           //text generator used: http://patorjk.com/software/taag/#p=display&f=Big&t=
{
    if(player==2)
    {
        SetColor(15);
        SetColor(12);
        printf(" _____    ___     ");
        SetColor(15);
        printf("     __          _______ _   _  _____ _   _   _ \n");
        SetColor(12);
        printf("|  __ \\  |__ \\  ");
        SetColor(15);
        printf("       \\ \\        / /_   _| \\ | |/ ____| | | | | |\n");
        SetColor(12);
        printf("| |__) |    ) |   ");
        SetColor(15);
        printf("      \\ \\  /\\  / /  | | |  \\| | (___ | | | | | |\n");
        SetColor(12);
        printf("|  ___/    / /    ");
        SetColor(15);
        printf("       \\ \\/  \\/ /   | | | . ` |\\___ \\| | | | | |\n");
        SetColor(12);
        printf("| |       / /_    ");
        SetColor(15);
        printf("        \\  /\\  /   _| |_| |\\  |____) |_| |_| |_|\n");
        SetColor(12);
        printf("|_|      |____|   ");
        SetColor(15);
        printf("         \\/  \\/   |_____|_| \\_|_____/(_) (_) (_)\n");
    }

    else if(player==1)
    {
        SetColor(11);
        printf(" _____    __   ");
        SetColor(15);
        printf("      __          _______ _   _  _____ _   _   _ \n");
        SetColor(11);
        printf("|  __ \\  /_ |");
        SetColor(15);
        printf("        \\ \\        / /_   _| \\ | |/ ____| | | | | |\n");
        SetColor(11);
        printf("| |__) |  | | ");
        SetColor(15);
        printf("        \\ \\  /\\  / /  | | |  \\| | (___ | | | | | |\n");
        SetColor(11);
        printf("|  ___/   | | ");
        SetColor(15);
        printf("         \\ \\/  \\/ /   | | | . ` |\\___ \\| | | | | |\n");
        SetColor(11);
        printf("| |       | | ");
        SetColor(15);
        printf("          \\  /\\  /   _| |_| |\\  |____) |_| |_| |_|\n");
        SetColor(11);
        printf("|_|       |_| ");
        SetColor(15);
        printf("           \\/  \\/   |_____|_| \\_|_____/(_) (_) (_)\n");
    }
}


void Shrek() //Reid
{
    SetColor(ShrekColour);
    printf("Shrek");
    SetColor(15);
}
void Donkey()//Reid
{
    SetColor(DonkeyColour);
    printf("Donkey");
    SetColor(15);
}
void Ginger()//Reid
{
    SetColor(GingerColour);
    printf("Giant Gingerbread Man");
    SetColor(15);
}
void Fiona()//Reid
{
    SetColor(FionaColour);
    printf("Fiona");
    SetColor(15);
}
void Dragon() //Reid
{
    SetColor(DragonColour);
    printf("Dragon");
    SetColor(15);
}
void Prince()//Reid
{
    SetColor(PrinceColour);
    printf("Prince Charming");
    SetColor(15);
}
void Lord()//Reid
{
    SetColor(LordColour);
    printf("Lord Farquaad");
    SetColor(15);
}
void Rump()//Reid
{
    SetColor(RumpColour);
    printf("Rumplestiltskin");
    SetColor(15);
}
void Fairy()//Reid
{
    SetColor(FairyColour);
    printf("Fairy Godmother");
    SetColor(15);
}
void Witch()//Reid
{
    SetColor(WitchColour);
    printf("Witch");
    SetColor(15);
}

int Crit(int magic)//Reid
{
    int r=0;
    if(magic==1)
    {
        r=rand() % 5;
    }
        if(r==1)
    {
        r=1;
    }
    else
    {
        r=0;
    }
    return r;
}

int Dodge(int speed)//Reid
{
    int r=0;
    if(speed==1)
    {
        r=rand() % 3;
    }
        if(r==1)
    {
        r=1;
    }
    else
    {
        r=0;
    }
    return r;
}

int IfHeal(int HealsRemain)//Reid
{
    int Heal;
    if(HealsRemain>0)
    {
        Heal=1;
    }
    else
    {
        Heal=0;
    }
    return Heal;
};

int IfSpecial(int RoundCountSinceSpecial)//Reid
{
    int Special;
    if(RoundCountSinceSpecial>=3)
    {
        Special=1;
    }
    else
    {
        Special=0;
    }
    return Special;
};

void RuleScreen()//Mischa - This function displays all of the rules and allows players to view more in-depth rules by pressing 1.
{
    char Input1, Input2;

    SetColor(15);//Set the colour to white.
    printf("How to play -\n\n");
    //(The line breaks are to change the colour of each character/player.)
    printf("1. Each player picks one out of the ten characters available. (Players are not allowed to be the same character.)\n");//1
    printf("2. After the players choose their characters, the game will begin.\n");//2
    printf("3. ");
    Player1();
    printf("will start the battle by choosing one out of the 3 choices (");
    SetColor(14);
    printf("Attack");
    SetColor(15);
    printf(", ");
    SetColor(13);
    printf("Special Attack");
    SetColor(15);
    printf(", and ");
    SetColor(11);
    printf("Heal");
    SetColor(15);
    printf(").\n");//3
    printf("4. After ");
    Player1();
    printf("has gone, the turn will be passed onto ");
    SetColor(12);
    printf("Player 2");
    SetColor(15);
    printf(".\n");//4
    printf("5. Once a players ");
    SetColor(12);
    printf("Health ");
    SetColor(15);
    printf("reaches 0, the round will end and the player who is still alive will be the victor.\n");//5
    printf("6. The loser will choose a new character first and the victor will do the same after.\n");//6
    printf("7. This process will continue until a player has won more than half of the total rounds.\n");//7
    printf("8. Once this occurs, that player will be awarded victor of the game!\n");//8
    printf("9. Have fun!\n\n");//9

    printf("Press 1 to learn more, press any other key to continue to the game.\n");

         Input1 = getch();//Get input.

    if(Input1==49)//In-depth rules if input equals 1
        {
            system("cls");

            SetColor(14);
            printf("Attack");
            SetColor(15);
            printf(" - Can be used every round.\n");
            SetColor(13);
            printf("Special Attack");
            SetColor(15);
            printf(" - Can be used every third turn. (Can be used when the battle first begins)\n");
            SetColor(13);
            printf("     *");
            SetColor(15);
            printf("If a player achieves a critical hit on a special attack, the other players health will instantly drop to 0, resulting in death.\n");
            SetColor(11);
            printf("Heal");
            SetColor(15);
            printf(" - Heals your health back to full. Can be used until the player runs out of healing. (Can be used multiple rounds in a row)\n\n");

            printf("If character has...\n\n");

            printf("Girth - More health. (");
            SetColor(14);
            printf("5 ");
            SetColor(15);
            printf("Damage, ");
            SetColor(13);
            printf("7 ");
            SetColor(15);
            printf("Special Damage, ");
            SetColor(12);
            printf("20 ");
            SetColor(15);
            printf("Health, ");
            SetColor(11);
            printf("2 ");
            SetColor(15);
            printf("Heals)\n");
            SetColor(15);

            printf("Strength - More damage. (");
            SetColor(14);
            printf("7 ");
            SetColor(15);
            printf("Damage, ");
            SetColor(13);
            printf("8 ");
            SetColor(15);
            printf("Special Damage, ");
            SetColor(12);
            printf("15 ");
            SetColor(15);
            printf("Health, ");
            SetColor(11);
            printf("3 ");
            SetColor(15);
            printf("Heals)\n");
            SetColor(15);

            printf("Magic - The random ability to perform a critical attack. (");
            SetColor(14);
            printf("5 ");
            SetColor(15);
            printf("Damage, ");
            SetColor(13);
            printf("6 ");
            SetColor(15);
            printf("Special Damage, ");
            SetColor(5);
            printf("7 ");
            SetColor(15);
            printf("Random Critical Damage, ");
            SetColor(12);
            printf("15 ");
            SetColor(15);
            printf("Health, ");
            SetColor(11);
            printf("3 ");
            SetColor(15);
            printf("Heals)\n");
            SetColor(15);

            printf("Speed - The random ability to dodge the opponents attacks. (");
            SetColor(14);
            printf("4 ");
            SetColor(15);
            printf("Damage, ");
            SetColor(13);
            printf("6 ");
            SetColor(15);
            printf("Special Damage, ");
            SetColor(4);
            printf("10 ");
            SetColor(15);
            printf("Dodge Health Buffer, ");
            SetColor(12);
            printf("15 ");
            SetColor(15);
            printf("Health, ");
            SetColor(11);
            printf("3 ");
            SetColor(15);
            printf("Heals)\n\n");
            SetColor(15);

        printf("Please press any key to countinue.\n");
        while (1)//Scans for any key input.
        {
            if (kbhit)
            {
                Input2 = getch();
                break;
            }
        }
    }
   SetColor(15);//Set the colour of the text to white.
};

int DisplayOptions(int Special, int Health)//Mischa - This function allows the player to pick to attack, special attack, or heal. It will tell players if they are out of healing or if their special attack is on cooldown.
{
    int Choice;

    printf("\nOptions: \n1 = Attack \n2 = Special Attack \n3 = Heal\n");

    while (1)
    {
        Choice=getch();//Get input.

        if (Choice==50)//Special Attack
        {
            if (Special==1)//Player is able to use special attack.
            {
                return 2;
            }
            else//Player is unable to use special attack.
            {
                printf("Your special attack is on cooldown! Please pick a different option.\n");
                delay(3000);
                return 0;
            }
        }
        else if (Choice==51)//Heal
        {
            if (Health==1)//Player is able to use heal.
            {
                return 3;
            }
            else//Player is unable to use heal.
            {
                printf("You are out of healing! Please pick a different option.\n");
                return 0;
                delay(3000);
            }
        }
        else if(Choice==49)//Attack
        {
            return 1;
        }
        else //Invalid input
        {
            printf("You have entered an invalud input!");
            delay(3000);//Delay for 3 seconds before allowing the character to enter a different input.
            return 0;
        }
    }
};

int RoundSelection()//Mischa - This function allows the player to choose how many rounds of the game they would like to play.
{
    int InvalidRound=0, RoundNumber;

    do
        {
        printf("How many rounds would you like to play? (Best out of 1, 3, or 5.)\n");//How many rounds?
            if (kbhit)
            {
                RoundNumber = getch();
                if ((int)RoundNumber==49||(int)RoundNumber==51||(int)RoundNumber==53)//If user inputs a "1", "2", or "3"
                    {
                        InvalidRound=0;
                        break;
                    }
                    else
                    {
                    printf("You have entered an invalid input! Please input a 1, 3, or 5.\n");//Invalid Input.
                    InvalidRound=1;
                    }
            }
        }
        while(InvalidRound==1);

    if(RoundNumber==49)//1 round.
    {
        return 1;
    }
    else if (RoundNumber==51)//3 rounds.
    {
        return 3;
    }
    else//5 rounds.
    {
        return 5;
    }
};

int CharacterSelect(int OtherPlayer, int Player)//Mischa - This function allows the player to pick which character they would like to use during the battle. It doesn't allow the player to choose the same character as the other player.
{
    int MainMenu, CharacterSelect, ConfirmInput;
    do
    {
        if(Player==1)//If Player 1 is choosing the character.
        {
            SetColor(11);
            printf("Player 1 ");
            SetColor(15);//sets color to white
            printf("select your character -\n\n");
        }
        else//If Player 2 is choosing the character.
        {
            SetColor(12);
            printf("Player 2 ");
            SetColor(15);//sets color to white
            printf("select your character -\n\n");
        }
        //Character options
        SetColor(15);
        printf("1 - ");
        Shrek();
        printf("\n2 - ");
        Donkey();
        printf("\n3 - ");
        Ginger();
        printf("\n4 - ");
        Fiona();
        printf("\n5 - ");
        Dragon();
        printf("\n6 - ");
        Prince();
        printf("\n7 - ");
        Lord();
        printf("\n8 - ");
        Rump();
        printf("\n9 - ");
        Fairy();
        printf("\n0 - ");
        Witch();
        printf("\n");

        while (1)
        {
                CharacterSelect=getch();

                if (CharacterSelect==OtherPlayer)//If choosen character equals the other players character.
                {
                    printf("You cannot pick the same character as the other player! Please pick a new character.\n");
                    CharacterSelect=100;
                    delay(5000);
                    system("cls");
                    break;
                }
                else if ((int)CharacterSelect>57||(int)CharacterSelect<48)//Invalid input
                {
                    system("cls");
                    printf("You have entered an invalid input! Please enter a number between 0 and 9.\n");
                    delay(2000);
                    break;
                }
                else
                {
                    break;
                }
            }

            system("cls");

            switch(CharacterSelect)//Decide which character the player choose.
            {
                case 49://1 - Shrek

                    SetColor(15);
                    printf("You have picked ");
                    Shrek();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(12);
                    printf("Disabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(12);
                    printf("Disabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", ShrekHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", ShrekDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", ShrekSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", ShrekHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Shrek();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Shrek();
                            printf("!\n");
                            return 49;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else //Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 50://2 - Donkey

                    SetColor(15);
                    printf("You have picked ");
                    Donkey();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(12);
                    printf("Disabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(10);
                    printf("Enabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", DonkeyHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", DonkeyDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", DonkeySDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", DonkeyHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Donkey();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Donkey();
                            printf("!\n");
                            return 50;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 51://3 - Giant Gingerbread Man

                    SetColor(15);
                    printf("You have picked ");
                    Ginger();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(10);
                    printf("Enabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(12);
                    printf("Disabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", GingerHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", GingerDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", GingerSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", GingerHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Ginger();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Ginger();
                            printf("!\n");
                            return 51;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 52://4 - Fiona

                    SetColor(15);
                    printf("You have picked ");
                    Fiona();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(10);
                    printf("Enabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(10);
                    printf("Enabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", FionaHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", FionaDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", FionaSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", FionaHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Fiona();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Fiona();
                            printf("!\n");
                            return 52;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 53://5 - Dragon

                    SetColor(15);
                    printf("You have picked ");
                    Dragon();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(12);
                    printf("Disabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(12);
                    printf("Disabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", DragonHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", DragonDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", DragonSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", DragonHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Dragon();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Dragon();
                            printf("!\n");
                            return 53;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 54://6 - Prince Charming

                    SetColor(15);
                    printf("You have picked ");
                    Prince();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(12);
                    printf("Disabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(10);
                    printf("Enabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", PrinceHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", PrinceDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", PrinceSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", PrinceHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Prince();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Prince();
                            printf("!\n");
                            return 54;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 55://7 - Lord Farquaad

                    SetColor(15);
                    printf("You have picked ");
                    Lord();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(12);
                    printf("Disabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(10);
                    printf("Enabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", LordHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", LordDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", LordSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", LordHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Lord();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Lord();
                            printf("!\n");
                            return 55;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 56://8 - Rumplestiltskin

                    SetColor(15);
                    printf("You have picked ");
                    Rump();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(10);
                    printf("Enabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(12);
                    printf("Disabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", RumpHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", RumpDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", RumpSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", RumpHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Rump();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Rump();
                            printf("!\n");
                            return 56;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 57://9 - Fairy Godmother

                    SetColor(15);
                    printf("You have picked ");
                    Fairy();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(10);
                    printf("Enabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(12);
                    printf("Disabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", FairyHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", FairyDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", FairySDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", FairyHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Fairy();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Fairy();
                            printf("!\n");
                            return 57;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                case 48://0 - Witch

                    SetColor(15);
                    printf("You have picked ");
                    Witch();
                    printf("! Please read through his stats:\n\n");
                    SetColor(15);
                    printf("Magic - ");
                    SetColor(10);
                    printf("Enabled\n");
                    SetColor(15);
                    printf("Speed - ");
                    SetColor(10);
                    printf("Enabled\n\n");
                    SetColor(15);
                    printf("Health - ");
                    SetColor(12);
                    printf("%d\n", WitchHealth);
                    SetColor(15);
                    printf("Damage - ");
                    SetColor(14);
                    printf("%d\n", WitchDamage);
                    SetColor(15);
                    printf("Special Damage - ");
                    SetColor(13);
                    printf("%d\n", WitchSDamage);
                    SetColor(15);
                    printf("Number of Heals - ");
                    SetColor(11);
                    printf("%d\n\n", WitchHeals);
                    SetColor(15);
                    printf("Press 1 to continue with ");
                    Witch();
                    printf(", press 0 to pick a different character.\n");

                    while (1)
                    {
                        ConfirmInput=getch();//Get input.

                        if (ConfirmInput==49)//"You have picked *character*!" text.
                        {
                            system("cls");
                            printf("You have picked ");
                            Witch();
                            printf("!\n");
                            return 48;
                        }
                        else if (ConfirmInput==48)//Loop so player can pick a different character.
                        {
                            system("cls");
                            MainMenu=1;
                            break;
                        }
                        else//Invalid input.
                        {
                            printf("You have entered an invalid input! Please enter a 1 or 0.\n");
                        }
                    }

                    break;

                default:

                    MainMenu=1;

                    }
    }
    while(MainMenu==1);//Loop function
    return 0;
};

struct character AssignStats (int playerselect) //Kai: assigns the variable values for each character
{
    struct character pstat;
    switch (playerselect) //determines which character stats to assign
    {
    case 49: //Shrek
        pstat.Damage=ShrekDamage;
        pstat.Specialdamage=ShrekSDamage;
        pstat.Healsremain=ShrekHeals;
        pstat.Health=ShrekHealth;
        pstat.Defaulthealth=ShrekHealth;
        pstat.Magic=0;
        pstat.Name=49;
        pstat.Speed=0;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 50: //Donkey
        pstat.Damage=DonkeyDamage;
        pstat.Specialdamage=DonkeySDamage;
        pstat.Healsremain=DonkeyHeals;
        pstat.Health=DonkeyHealth;
        pstat.Defaulthealth=DonkeyHealth;
        pstat.Magic=0;
        pstat.Name=50;
        pstat.Speed=1;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 51://Giant Gingerbread Man
        pstat.Damage=GingerDamage;
        pstat.Healsremain=GingerHeals;
        pstat.Specialdamage=GingerSDamage;
        pstat.Health=GingerHealth;
        pstat.Defaulthealth=GingerHealth;
        pstat.Magic=1;
        pstat.Name=51;
        pstat.Speed=0;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 52://Fiona
        pstat.Damage=FionaDamage;
        pstat.Healsremain=FionaHeals;
        pstat.Specialdamage=FionaSDamage;
        pstat.Health=FionaHealth;
        pstat.Defaulthealth=FionaHealth;
        pstat.Magic=1;
        pstat.Name=52;
        pstat.Speed=1;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 53://Dragon
        pstat.Damage=DragonDamage;
        pstat.Healsremain=DragonHeals;
        pstat.Specialdamage=DragonSDamage;
        pstat.Health=DragonHealth;
        pstat.Defaulthealth=DragonHealth;
        pstat.Magic=0;
        pstat.Name=53;
        pstat.Speed=0;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 54://Prince Charming
        pstat.Damage=PrinceDamage;
        pstat.Healsremain=PrinceHeals;
        pstat.Specialdamage=PrinceSDamage;
        pstat.Health=PrinceHealth;
        pstat.Defaulthealth=PrinceHealth;
        pstat.Magic=0;
        pstat.Name=54;
        pstat.Speed=1;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 55: //Lord Farquaad
        pstat.Damage=LordDamage;
        pstat.Healsremain=LordHeals;
        pstat.Specialdamage=LordSDamage;
        pstat.Health=LordHealth;
        pstat.Defaulthealth=LordHealth;
        pstat.Magic=0;
        pstat.Name=55;
        pstat.Speed=1;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 56://Rumplestiltskin
        pstat.Damage=RumpDamage;
        pstat.Healsremain=RumpHeals;
        pstat.Specialdamage=RumpSDamage;
        pstat.Health=RumpHealth;
        pstat.Defaulthealth=RumpHealth;
        pstat.Magic=1;
        pstat.Name=56;
        pstat.Speed=0;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 57://Fairy godmother
        pstat.Damage=FairyDamage;
        pstat.Healsremain=FairyHeals;
        pstat.Specialdamage=FairySDamage;
        pstat.Health=FairyHealth;
        pstat.Defaulthealth=FairyHealth;
        pstat.Magic=1;
        pstat.Name=57;
        pstat.Speed=0;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;

    case 48://Witch
        pstat.Damage=WitchDamage;
        pstat.Healsremain=WitchHeals;
        pstat.Specialdamage=WitchSDamage;
        pstat.Health=WitchHealth;
        pstat.Defaulthealth=WitchHealth;
        pstat.Magic=1;
        pstat.Name=48;
        pstat.Speed=1;
        pstat.Roundssincespecial=3;
        pstat.Roundwins=0;
        break;
    }
    return pstat;
};

int Attack(int Damage, int Health, int Ifdodge, int Ifcrit)//Kai: determines amount of damage inflicted on player based on damage, crit, and dodge
{

    if (Ifcrit==1)//determines if crit and changes damage accordingly
    {
        Damage=Damage+7;
    }
    if (Ifdodge==1)//determines if dodge and changes health accordingly
    {
        Damage=Damage-10;
    }
    if (Damage>=0)//determines if any damage actually occuring and does calculations accordingly
    {
        Health=Health-Damage;
        return Health;
    }
    else
    {
        return Health;
    }
}

int Ifdefeat(int Healthremain1, int Healthremain2)//Kai: determines if player is defeated after turn set
{
    if ((Healthremain1<=0)||(Healthremain2<=0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IfWinner (int Roundcount, int P1Roundwins, int P2Roundwins)//Kai: determines if a player has won the game
                                                               //based on number of rounds won and number of
                                                               //rounds selected
{
    int answer;
        if ((Roundcount/2)<P1Roundwins)//determines if Player 1 won
        {
            answer=1;
        }
        else if ((Roundcount/2)<P2Roundwins)//determins if player 2 won
        {
            answer=2;
        }
    else//no one won
    {
        answer=0;
    }
    return answer;
}

void Printstats (struct character Player, int Special, int Heal)//Displays stats before action taken: Kai
{
    char Input;
    SetColor(15);//sets color to white
    switch (Player.Name)//determines which player and prints name to screen
        {
        case 48://witch
            Witch();
            printf("'s current stats and options -");
            break;

        case 49://Shrek
            Shrek();
            printf("'s current stats and options -");
            break;
        case 50://Donkey
            Donkey();
            printf("'s current stats and options -");
            break;

        case 51://Gingerbread man
            Ginger();
            printf("'s current stats and options -");
            break;

        case 52://Fiona
            Fiona();
            printf("'s current stats and options -");
            break;

        case 53://Dragon
            Dragon();
            printf("'s current stats and options -");
            break;

        case 54://Prince Charming
            Prince();
            printf("'s current stats and options -");
            break;

        case 55://Lord Farquaad
            Lord();
            printf("'s current stats and options -");
            break;
        case 56://Rumplestiltskin
            Rump();
            printf("'s current stats and options -");
            break;

        case 57://Fairygod Mother
            Fairy();
            printf("'s current stats and options -");
            break;
        }
    if (Player.Magic==0)
    {
        SetColor(15);
        printf("\n\nMagic - ");
        SetColor(12);
        printf("Disabled\n");
        SetColor(15);
    }
    else
    {
        printf("\n\nMagic - ");
        SetColor(10);
        printf("Enabled\n\n");
        SetColor(15);
    }
    if (Player.Speed==0)
    {
        SetColor(15);
        printf("Speed - ");
        SetColor(12);
        printf("Disabled\n\n");
        SetColor(15);
    }
    else
    {
        printf("Speed - ");
        SetColor(10);
        printf("Enabled\n\n");
        SetColor(15);
    }
    printf("\nHealth - ");
    SetColor(12);//health color
    printf("%d\n", Player.Health);
    SetColor(15);//reset to white

    printf("Standard Attack - ");
    SetColor(14);//damage color
    printf("%d\n", Player.Damage);//damage color
    SetColor(15);//reset to white

    if (Special==1)
    {
        printf("Special Attack Damage - ");
        SetColor(13);//special damage color
        printf("%d\n", Player.Specialdamage);
        SetColor(15);//reset to white
    }
    else
    {
        printf("Special Attack Damage - ");
        SetColor(13);//special damage color
        printf("Unavailable\n");
        SetColor(15);//reset to white
        printf("Will be available in - ");
        SetColor(13);//special damage color
        printf("%d", 3-Player.Roundssincespecial);
        SetColor(15);//reset to white
        printf(" more turns.\n");
    }
    if (Heal==1)
    {
        printf("Heals - ");
        SetColor(11);//heal color
        printf("%d\n", Player.Healsremain);
        SetColor(15);//reset to white
    }
    else
    {
         printf("Heals - ");
        SetColor(11);//heal color
        printf("0\n");
        SetColor(15);//reset to white
    }
}

void Player1()//Reid
{
    SetColor(11);//player 1 color
    printf("Player 1 ");
    SetColor(15);
}

void Player2()//Reid
{
    SetColor(12);//player 2 color
    printf("Player 2 ");
    SetColor(15);
}

void CritandDodgeprint (int crit, int dodge)//Kai
{
    if(crit==1)
    {
        printf("Critical hit occured. \nDamage increased by ");
        SetColor(14);
        printf("7\n\n");
        SetColor(15);
    }
    if (dodge==1)
    {
        printf("Dodge has occured. \nDamage decreased by ");
        SetColor(14);
        printf("10\n\n");
        SetColor(15);
    }

}


int main()//unless otherwise specified, work in main done by Kai
{
    struct character P1, P2;//p1 and p2 character stats being held
    int Roundcount, Count, Countcheck, Winner, Defeated, Special, Heal, Choice, Ifcrit, Ifdodge, temp, i;

    SetColor(15);//sets color to white
    Welcome();
    delay(6000);
    system("cls");
    RuleScreen();//prints rules and introduces game: Mischa
    system("cls");
    Roundcount=RoundSelection();//determines amount of rounds in game: Mischa
    system("cls");//clears screen


    P1.Name=CharacterSelect(1, 1);//selects character for player1: Mischa
    delay(3000);
    system("cls");//clears screen after 2 seconds

    P2.Name=CharacterSelect(P1.Name, 2);//selects character for player2 (can't be same as player1): Mischa
    delay(3000);
    system("cls");


    P1=AssignStats(P1.Name);//gets stats for p1character based on selection:Kai
    P2=AssignStats(P2.Name);//gets stats for p2character based on selection:Kai
    Winner=0;//initializes Winner so enters action loop
    while(Winner==0)//round action loops till a player has more wins than total rounds/2
    {
        srand((int)time(NULL));
        Count=0;
        do //action selection for round loop until 1 player defeated
        {
            SetColor(15);//sets color to white
            Countcheck=Count%2;//determines if even or odd round
            Count++;

//p1 turn
            if(0==Countcheck)//if even round then p1 actions occure
            {
               Special=IfSpecial(P1.Roundssincespecial);//calculates if able to do special based on the number of rounds since special used (1=yes, 0=no)
               Heal=IfHeal(P1.Healsremain);//checks if able to heal based on number of heals remain (1 if yes, 0 if no)
               do//gets user to determine action for round, 1=attack, 2=special attack, 3=heal
               {
                  Printstats (P1, Special, Heal);//Kai
                  SetColor(15);//sets color to white
                  Choice=DisplayOptions(Special, Heal);//Mischa - Figures out if the player would like to attack, special attack, or heal.
                  system("cls");
               }while(Choice==0);
               P1.Roundssincespecial++;//Increases number of round since special

//actions for player 1: Kai
               switch(Choice)//select action for P1
                {

//Player 1 attack function: Kai
                case 1://attack
                    Ifcrit=Crit(P1.Magic);//determines if critical bonus is applied:Reid
                    Ifdodge=Dodge(P2.Speed);//determines if extra health from dodge is applied:Reid
                    CritandDodgeprint(Ifcrit, Ifdodge);//displays message regarding crit and dodge status if applicable
                    if ((Ifcrit==1)&(Ifdodge==1))//determines amount of time needed to display message regarding crit and dodge status
                    {
                        delay(8000);
                    }
                    else if (Ifcrit==1)//determines amount of time needed to display message regarding crit and dodge status
                    {
                        delay(4500);
                    }
                    else if (Ifdodge==1)//determines amount of time needed to display message regarding crit and dodge status
                    {
                        delay(4500);
                    }
                    system("cls");
                    Player2();
                    printf("Health - ");
                    SetColor(12);//health color
                    printf("%d", P2.Health);//test initial health print
                    SetColor(15);//sets color to white
                    printf(" --> ");

                    P2.Health=Attack(P1.Damage, P2.Health, Ifdodge, Ifcrit);//returns new health of player 2

                    SetColor(12);//health color
                    if (P2.Health<0)
                    {
                        P2.Health=0;
                    }
                    printf("%d\n", P2.Health);
                    SetColor(15);//sets color to white
//prints amount of damage inflicted by player:Kai
                    if (Ifcrit==1)//prints amount of damage inflicted if critical hit occured
                    {
                        if (Ifdodge==1)//determines if dodge occured and applies the resulting damage to player
                        {
                            printf("Total Damaged Dealt - ");
                            SetColor(14);//damage color
                            printf("%d\n", P1.Damage+7-10);
                            SetColor(15);//sets color to white
                        }
                        else//if only critical hit occured
                        {
                            printf("Total Damaged Dealt - ");
                            SetColor(14);//damage color
                            printf("%d \n", P1.Damage+7);
                            SetColor(15);//sets color to white
                        }
                    }
                    else if (Ifdodge==1)//determines if dodge occured and applies the resulting damage to player
                    {
                      if ((P1.Damage-10)>0)//if more damage dealt than dodge buffer then damage applied
                      {
                          printf("Total Damaged Dealt - ");
                          SetColor(14);//damage color
                          printf("%d \n", P1.Damage-10);
                          SetColor(15);//sets color to white
                      }
                      else//if dodge buffer is greater than damage
                      {
                          printf("Total Damaged Dealt - ");
                          SetColor(14);//damage color
                          printf("0\n");
                          SetColor(15);//sets color to white
                      }
                    }
                    else//no crit or dodge status
                    {
                        printf("Total Damaged Dealt - ");
                        SetColor(14);//damage color
                        printf("%d \n",P1.Damage);
                        SetColor(15);//sets color to white
                    }
                    delay(4000);
                    break;

//Player 1 Special attack:Kai
                case 2://special attack: Kai
                    Ifcrit=Crit(P1.Magic);//determines if critical bonus is applied:Reid
                    Ifdodge=Dodge(P2.Speed);//determines if extra health from dodge is applied:Reid
                    if (Ifcrit==1)//if critical hit occures durring special move then instantly kills player
                    {
                        //Kai
                        printf("Critical hit occured durring special attack resulting in... ");
                        delay(3500);
                        for (i=0; i<=5; i++)
                        {
                            system("cls");
                            SetColor(15);
                            printf("Critical hit occured durring special attack resulting in... ");
                            SetColor(12);
                            printf("Total annihilation!!!");
                            delay(150);
                            system("cls");
                            SetColor(15);
                            printf("Critical hit occured durring special attack resulting in... ");
                            SetColor(14);
                            printf("Total annihilation!!!");
                            delay(150);
                        }
                        system("cls");

                        //assci art for bomb comes from https://www.asciiart.eu/weapons/explosives editted by Kai
                        system("COLOR 04");
                        SetColor(12);//sets color to white
                        printf("                 .      \n");
                        printf("                 .       :   \n");
                        printf("                 :      .     \n");
                        printf("        :..   :  : :  .       \n");
                        printf("           ..  ; :: .           \n");
                        printf("              ... .. :..    \n");
                        printf("             ::: :...         \n");
                        printf("         ::.:.:...;; .....      \n");
                        printf("      :..     .;.. :;     .. \n");
                        printf("            . :. .  ;.         \n");
                        printf("             .: ;;: ;.           \n");
                        SetColor(8);
                        printf("            :; .BRRRV;       \n");
                        printf("               YB BMMMBR       \n");
                        printf("              ;BVIMMMMMt    \n");
                        printf("        .=YRBBBMMMMMMMB       \n");
                        printf("      =RMMMMMMMMMMMMMM;         \n");
                        printf("    ;BMMR=VMMMMMMMMMMMV.     \n");
                        printf("   tMMR::VMMMMMMMMMMMMMB:      \n");
                        printf("  tMMt ;BMMMMMMMMMMMMMMMB.       \n");
                        printf(" ;MMY ;MMMMMMMMMMMMMMMMMMV   \n");
                        printf(" XMB .BMMMMMMMMMMMMMMMMMMM:    \n");
                        printf(" BMI +MMMMMMMMMMMMMMMMMMMMi      \n");
                        printf(".MM= XMMMMMMMMMMMMMMMMMMMMY  \n");
                        printf(" BMt YMMMMMMMMMMMMMMMMMMMMi    \n");
                        printf(" VMB +MMMMMMMMMMMMMMMMMMMM:      \n");
                        printf(" ;MM+ BMMMMMMMMMMMMMMMMMMR    \n");
                        printf("  tMBVBMMMMMMMMMMMMMMMMMB.      \n");
                        printf("   tMMMMMMMMMMMMMMMMMMMB:        \n");
                        printf("    ;BMMMMMMMMMMMMMMMMY       \n");
                        printf("      +BMMMMMMMMMMMBY:          \n");
                        printf("        :+YRBBBRVt;\n");

                        delay(3000);
                        system("cls");
                        //assci art for bomb comes from https://www.clipart.email/clipart/mushroom-cloud-clipart-9384.html editted by Reid and Mischa
                        system("COLOR 0C");
                        printf("                                        # ###### ##     ##      ###        # #     ##                                  \n");
                        printf("                                      #    #######      ###     ##          ###  # #   ###                             \n");
                        printf("                            # #  ####   #                             ###            ##         ###                    \n");
                        printf("                        ##    #########                                                       # #   #                  \n");
                        printf("                    # #    ##                                                                     ##  #                \n");
                        printf("                 ##     ###                                                                        #  #                \n");
                        printf("             #     ##                                                                               #  #               \n");
                        printf("          ##    #                                                                                     ##   #           \n");
                        printf("              ##                                                                                         #   #         \n");
                        printf("       #                                                                                                   #  #        \n");
                        printf("    #                                                                                                       # #        \n");
                        printf("   #                                                                                                        ##   #     \n");
                        printf("  #    #                                                                                                          #    \n");
                        printf(" #   ##                                                                                                         ##  #  \n");
                        printf(" #   #                                                                                                            #  # \n");
                        printf("  #  ##                                                                                                            # # \n");
                        printf(" #     #                                                 #                                                        #  # \n");
                        printf(" #      ##                               #             ##    #            #### #            ###  #               # #   \n");
                        printf(" #        #                             #  # #       #            #####          ##      ###        ######    ##   ##  \n");
                        printf("  ##           ###   ##           # ##                                                                                 \n");
                        printf("                                                                                                                     # \n");
                        printf("  #                                                                                                                    \n");
                        printf("  #                                                                                                                    \n");
                        printf("  #                                                                                                           #        \n");
                        printf("   #                                                                                                          #        \n");
                        printf("     # # #                                                                                                    #        \n");
                        printf("         #                                                                                                 ##          \n");
                        printf("          #                                                                                           ####             \n");
                        printf("             #  ##                                                                                  #                  \n");
                        printf("                   #       ###             ### ##                     #   ##   ####        ##    #                     \n");
                        printf("                               # #####          #                    #                                                 \n");
                        printf("                                                #                    #                                                 \n");
                        printf("                                                #                    #                                                 \n");
                        printf("                                                #                   ##                                                 \n");
                        printf("                                                #                   ##                                                 \n");
                        printf("                                               #                    #                                                  \n");
                        printf("                                ###     #      #                     #     ##### ###                                   \n");
                        printf("                           #    ### #####    #        #             ### ## #     ## ####                               \n");
                        printf("                      #####    #  ##       ##    ##        #####                      #  #                             \n");
                        printf("                      #               ###  ## ##  #      #####  ##  ###     ###### ###### #                            \n");
                        printf("                      ###                                                                ##                            \n");
                        printf("                           #    #     ##      #                             ###                                        \n");
                        printf("                                              #                       #                                                \n");
                        printf("                                              #                       #                                                \n");
                        printf("                                             #                                                                         \n");
                        printf("                                            #                         #                                                \n");
                        printf("                                           #                          #                                                \n");
                        printf("                   #       ##              ##                         #            ##      ######                      \n");
                        printf("                    #     #   ####         #                          #       ##### ##     ## # # # #                  \n");
                        printf("             ####          ## ### ### #   #                            #### ##  ##              ####  #                \n");
                        printf("           ##      #                   # #       ## #                 #   # ## #                      # #              \n");
                        printf("           #######                           # #      # ######  #                                    ##  #             \n");
                        printf("          #                                                                                              # #           \n");
                        printf("     ##       ## ###                                                                           #            #          \n");
                        printf("        #                 ###      ## ##           #            #      ##    ### ######  ##                 #          \n");
                        printf("        #                               # #  ###### #####  ####  ######                                     #          \n");
                        printf("       ##                                                                                                              \n");
                        printf("          #####                                                                ####                   #                \n");
                        printf("                # # ## #######    ##       ######  #  ##########   ### #######     ##  ##  ###      ##                 \n");


                            for (i=0; i<=5; i++)
                            {
                                system("COLOR 0C");
                                delay(300);
                                system("COLOR 0E");
                                delay(300);
                            }

                        system("cls");
                        system("COLOR 0F");

                        Player2();
                        printf("Health - ");
                        SetColor(12);//health color
                        printf("%d", P2.Health);//initial health print
                        SetColor(15);//sets color to white
                        printf(" --> ");
                        P2.Health=0;
                        SetColor(12);//health color
                        printf("%d\n", P2.Health);
                        SetColor(15);//sets color to white
                        delay(4000);
                    }
                    else
                    {
                        CritandDodgeprint(Ifcrit, Ifdodge);//determines if printing dodge notification
                        if (Ifdodge==1)
                        {
                            delay(4500);
                        }
                        system("cls");
                        Player2();
                        printf("Health - ");
                        SetColor(12);//health color
                        printf("%d", P2.Health);//test initial health print
                        SetColor(15);//sets color to white
                        printf(" --> ");

                        P2.Health=Attack(P1.Specialdamage, P2.Health, Ifdodge, Ifcrit);//retruns new health of player 2
                        P1.Roundssincespecial=0;

                        SetColor(12);//health color
                        if (P2.Health<0)
                        {
                            P2.Health=0;
                        }
                        printf("%d\n", P2.Health);
                        SetColor(15);//sets color to white

                        //prints amount of damage inflicted by player:Kai
                        if (Ifdodge==1) //determines if dodge occured and applies the resulting damage to player
                        {
                          if ((P1.Damage-10)>0)//if more damage dealt than dodge buffer then damage applied
                          {
                              printf("Total Damaged Dealt - ");
                              SetColor(14);//damage color
                              printf("%d \n", P1.Specialdamage-10);
                              SetColor(15);//sets color to white
                          }
                          else//if dodge buffer is greater than damage
                          {
                              printf("Total Damaged Dealt - ");
                              SetColor(14);//damage color
                              printf("0\n");
                              SetColor(15);//sets color to white
                          }
                        }
                        else//no crit or dodge status
                        {
                            printf("Total Damaged Dealt - ");
                            SetColor(14);//damage color
                            printf("%d \n",P1.Specialdamage);
                            SetColor(15);//sets color to white
                        }
                        delay(3500);
                    }
                        break;


//Player 1 heal action: Kai
                case 3://heal
                   system("cls");
                   Player1();
                   printf("Health - ");
                    SetColor(12);//health color
                    printf("%d", P1.Health);//test initial health print
                    SetColor(15);//sets color to white
                    printf(" --> ");
                   P1.Health=P1.Defaulthealth;//returns new health for p1
                   P1.Healsremain=P1.Healsremain-1;//reduces number of heals by 1
                   SetColor(12);//health color
                   printf("%d\n", P1.Health);
                   SetColor(15);//sets color to white
                   delay(3500);
                   break;
                }
                system("cls");
            }
//p2 turn: Kai
            else
            {
               Special=IfSpecial(P2.Roundssincespecial);//calculates if able to do special based on the number
                                                        //of rounds since special used (1=yes, 0=no): Reid
               Heal=IfHeal(P2.Healsremain);//checks if able to heal based on number
                                           //of heals remain (1 if yes, 0 if no):Reid

               do//gets user to determine action for round, 1=attack, 2=special attack, 3=heal
               {
                   SetColor(15);//sets color to white
                   Printstats(P2, Special, Heal);//Kai
                   Choice=DisplayOptions(Special, Heal);//Mischa
                   system("cls");
               }while(Choice==0);

               P2.Roundssincespecial++;//Increases number of round since special
//actions for player 2:Kai
               switch(Choice)//select action for P1
                {
                case 1://attack:Kai
                    Ifcrit=Crit(P2.Magic);//determines if critical bonus is applied:Reid
                    Ifdodge=Dodge(P1.Speed);//determines if extra health from dodge is applied:Reid
                    CritandDodgeprint(Ifcrit, Ifdodge);
                    if ((Ifcrit==1)&(Ifdodge==1))//determines amount of time needed to display message indicating crit and/or dodge
                    {
                        delay(8000);
                    }
                    else if (Ifcrit==1)//determines amount of time needed to display message indicating crit
                    {
                        delay(4500);
                    }
                    else if (Ifdodge==1)//determines amount of time needed to display message indicating dodge
                    {
                        delay(4500);
                    }
                    system("cls");
                    Player1();
                    printf("Health - ");
                    SetColor(12);//health color
                    printf("%d", P1.Health);//initial health print
                    SetColor(15);//sets color to white
                    printf(" --> ");
                    P1.Health=Attack(P2.Damage, P1.Health, Ifdodge, Ifcrit);//returns new health of player 1:Kai
                    SetColor(12);//health color

                    if (P1.Health<0)
                    {
                        P1.Health=0;
                    }
                    printf("%d\n", P1.Health);
                    SetColor(15);//sets color to white
//prints amount of damage inflicted by player:Kai
                    if (Ifcrit==1)//if crit occures
                    {
                        if (Ifdodge==1)//if dodge stacks with critical attack damage inflicted calculated and applied
                        {
                            printf("Total Damaged Dealt - ");
                            SetColor(14);//damage color
                            printf("%d\n", P2.Damage+7-10);
                            SetColor(15);//sets color to white
                        }
                        else//amount of damage inflicted if only crit occures calculated and applied
                        {
                            printf("Total Damaged Dealt - ");
                            SetColor(14);//damage color
                            printf("%d \n", P2.Damage+7);
                            SetColor(15);//sets color to white
                        }
                    }
                    else if (Ifdodge==1)//if only dodge occures
                    {
                          if ((P1.Damage-10)>0)//if dodge buffer is less than attack damage
                          {
                              printf("Total Damaged Dealt - ");
                              SetColor(14);//damage color
                              printf("%d \n", P2.Damage-10);
                              SetColor(15);//sets color to white
                          }
                          else//if dodge buffer is greater than attack damage
                          {
                              printf("Total Damaged Dealt - ");
                              SetColor(14);//damage color
                              printf("0\n");
                              SetColor(15);//sets color to white
                          }
                    }
                    else//normal attack with no crit or dodge
                    {
                        printf("Total Damaged Dealt - ");
                        SetColor(14);//damage color
                        printf("%d \n",P2.Damage);
                        SetColor(15);//sets color to white
                    }

                    delay(3500);
                    break;

//Player 2 Special attack:Kai
                case 2://special attack
                    Ifcrit=Crit(P2.Magic);//determines if critical bonus is applied:Reid
                    Ifdodge=Dodge(P1.Speed);//determines if extra health from dodge is applied:Reid
                    if (Ifcrit==1)//special case if critical hit occures
                    {
                        //Kai
                        printf("Critical hit occured durring special attack resulting in... ");
                        delay(3500);
                        for (i=0; i<=5; i++)
                        {
                            system("cls");
                            SetColor(15);
                            printf("Critical hit occured durring special attack resulting in... ");
                            SetColor(12);
                            printf("Total annihilation!!!");
                            delay(150);
                            system("cls");
                            SetColor(15);
                            printf("Critical hit occured durring special attack resulting in... ");
                            SetColor(14);
                            printf("Total annihilation!!!");
                            delay(150);
                        }
                        system("cls");

                        //assci art for bomb comes from https://www.asciiart.eu/weapons/explosives editted by Kai
                        system("COLOR 04");
                        SetColor(12);//sets color to white
                        printf("                 .      \n");
                        printf("                 .       :   \n");
                        printf("                 :      .     \n");
                        printf("        :..   :  : :  .       \n");
                        printf("           ..  ; :: .           \n");
                        printf("              ... .. :..    \n");
                        printf("             ::: :...         \n");
                        printf("         ::.:.:...;; .....      \n");
                        printf("      :..     .;.. :;     .. \n");
                        printf("            . :. .  ;.         \n");
                        printf("             .: ;;: ;.           \n");
                        SetColor(8);
                        printf("            :; .BRRRV;       \n");
                        printf("               YB BMMMBR       \n");
                        printf("              ;BVIMMMMMt    \n");
                        printf("        .=YRBBBMMMMMMMB       \n");
                        printf("      =RMMMMMMMMMMMMMM;         \n");
                        printf("    ;BMMR=VMMMMMMMMMMMV.     \n");
                        printf("   tMMR::VMMMMMMMMMMMMMB:      \n");
                        printf("  tMMt ;BMMMMMMMMMMMMMMMB.       \n");
                        printf(" ;MMY ;MMMMMMMMMMMMMMMMMMV   \n");
                        printf(" XMB .BMMMMMMMMMMMMMMMMMMM:    \n");
                        printf(" BMI +MMMMMMMMMMMMMMMMMMMMi      \n");
                        printf(".MM= XMMMMMMMMMMMMMMMMMMMMY  \n");
                        printf(" BMt YMMMMMMMMMMMMMMMMMMMMi    \n");
                        printf(" VMB +MMMMMMMMMMMMMMMMMMMM:      \n");
                        printf(" ;MM+ BMMMMMMMMMMMMMMMMMMR    \n");
                        printf("  tMBVBMMMMMMMMMMMMMMMMMB.      \n");
                        printf("   tMMMMMMMMMMMMMMMMMMMB:        \n");
                        printf("    ;BMMMMMMMMMMMMMMMMY       \n");
                        printf("      +BMMMMMMMMMMMBY:          \n");
                        printf("        :+YRBBBRVt;\n");

                        delay(3000);
                        system("cls");
                        //assci art for bomb comes from https://www.clipart.email/clipart/mushroom-cloud-clipart-9384.html editted by Mischa and Reid
                        system("COLOR 0C");
                        printf("                                        # ###### ##     ##      ###        # #     ##                                  \n");
                        printf("                                      #    #######      ###     ##          ###  # #   ###                             \n");
                        printf("                            # #  ####   #                             ###            ##         ###                    \n");
                        printf("                        ##    #########                                                       # #   #                  \n");
                        printf("                    # #    ##                                                                     ##  #                \n");
                        printf("                 ##     ###                                                                        #  #                \n");
                        printf("             #     ##                                                                               #  #               \n");
                        printf("          ##    #                                                                                     ##   #           \n");
                        printf("              ##                                                                                         #   #         \n");
                        printf("       #                                                                                                   #  #        \n");
                        printf("    #                                                                                                       # #        \n");
                        printf("   #                                                                                                        ##   #     \n");
                        printf("  #    #                                                                                                          #    \n");
                        printf(" #   ##                                                                                                         ##  #  \n");
                        printf(" #   #                                                                                                            #  # \n");
                        printf("  #  ##                                                                                                            # # \n");
                        printf(" #     #                                                 #                                                        #  # \n");
                        printf(" #      ##                               #             ##    #            #### #            ###  #               # #   \n");
                        printf(" #        #                             #  # #       #            #####          ##      ###        ######    ##   ##  \n");
                        printf("  ##           ###   ##           # ##                                                                                 \n");
                        printf("                                                                                                                     # \n");
                        printf("  #                                                                                                                    \n");
                        printf("  #                                                                                                                    \n");
                        printf("  #                                                                                                           #        \n");
                        printf("   #                                                                                                          #        \n");
                        printf("     # # #                                                                                                    #        \n");
                        printf("         #                                                                                                 ##          \n");
                        printf("          #                                                                                           ####             \n");
                        printf("             #  ##                                                                                  #                  \n");
                        printf("                   #       ###             ### ##                     #   ##   ####        ##    #                     \n");
                        printf("                               # #####          #                    #                                                 \n");
                        printf("                                                #                    #                                                 \n");
                        printf("                                                #                    #                                                 \n");
                        printf("                                                #                   ##                                                 \n");
                        printf("                                                #                   ##                                                 \n");
                        printf("                                               #                    #                                                  \n");
                        printf("                                ###     #      #                     #     ##### ###                                   \n");
                        printf("                           #    ### #####    #        #             ### ## #     ## ####                               \n");
                        printf("                      #####    #  ##       ##    ##        #####                      #  #                             \n");
                        printf("                      #               ###  ## ##  #      #####  ##  ###     ###### ###### #                            \n");
                        printf("                      ###                                                                ##                            \n");
                        printf("                           #    #     ##      #                             ###                                        \n");
                        printf("                                              #                       #                                                \n");
                        printf("                                              #                       #                                                \n");
                        printf("                                             #                                                                         \n");
                        printf("                                            #                         #                                                \n");
                        printf("                                           #                          #                                                \n");
                        printf("                   #       ##              ##                         #            ##      ######                      \n");
                        printf("                    #     #   ####         #                          #       ##### ##     ## # # # #                  \n");
                        printf("             ####          ## ### ### #   #                            #### ##  ##              ####  #                \n");
                        printf("           ##      #                   # #       ## #                 #   # ## #                      # #              \n");
                        printf("           #######                           # #      # ######  #                                    ##  #             \n");
                        printf("          #                                                                                              # #           \n");
                        printf("     ##       ## ###                                                                           #            #          \n");
                        printf("        #                 ###      ## ##           #            #      ##    ### ######  ##                 #          \n");
                        printf("        #                               # #  ###### #####  ####  ######                                     #          \n");
                        printf("       ##                                                                                                              \n");
                        printf("          #####                                                                ####                   #                \n");
                        printf("                # # ## #######    ##       ######  #  ##########   ### #######     ##  ##  ###      ##                 \n");


                            for (i=0; i<=5; i++)
                            {
                                system("COLOR 0C");
                                delay(300);
                                system("COLOR 0E");
                                delay(300);
                            }

                        system("cls");
                        system("COLOR 0F");
                        Player1();
                        printf("Health - ");
                        SetColor(12);//health color
                        printf("%d", P1.Health);//initial health print
                        SetColor(15);//sets color to white
                        printf(" --> ");
                        P1.Health=0;
                        SetColor(12);//health color
                        if (P1.Health<0)
                        {
                            P1.Health=0;
                        }
                        printf("%d\n", P1.Health);
                        SetColor(15);//sets color to white
                        delay(4000);
                    }
                    else//if no crit occures: Kai
                    {
                        CritandDodgeprint(Ifcrit, Ifdodge);//displays dodge message if applicable
                        if (Ifdodge==1)
                        {
                            delay(4500);
                        }
                        system("cls");
                        Player1();
                        printf("Health - ");
                        SetColor(12);//health color
                        printf("%d", P1.Health);//test initial health print
                        SetColor(15);//sets color to white
                        printf(" --> ");

                        P1.Health=Attack(P2.Specialdamage, P1.Health, Ifdodge, Ifcrit);//retruns new health of player 2
                        P2.Roundssincespecial=0;

                        SetColor(12);//health color
                        printf("%d\n", P1.Health);
                        SetColor(15);//sets color to white
    //amount of damage inflicted by player calculated:Kai
                        if (Ifdodge==1)//if dodge occures then special cases applied
                        {
                          if ((P2.Damage-10)>0)//if dodge occures and damage is greater than buffer
                          {
                              printf("Total Damaged Dealt - ");
                              SetColor(14);//damage color
                              printf("%d \n", P2.Specialdamage-10);
                              SetColor(15);//sets color to white
                          }
                          else//if dodge buffer greater than damage
                          {
                              printf("Total Damaged Dealt - ");
                              SetColor(14);//damage color
                              printf("0\n");
                              SetColor(15);//sets color to white
                          }
                        }
                        else//standard special attack
                        {
                            printf("Total Damaged Dealt - ");
                            SetColor(14);//damage color
                            printf("%d \n",P2.Specialdamage);
                            SetColor(15);//sets color to white
                        }
                        delay(4000);
                    }
                    break;

//Player 2 heal: Kai
                case 3://heal:Kai
                    system("cls");
                    Player2();
                    printf("Health - ");
                    SetColor(12);//health color
                    printf("%d", P2.Health);//test initial health print
                    SetColor(15);//sets color to white
                    printf(" --> ");
                   P2.Health=P2.Defaulthealth;//returns new health for p2 based on old health
                   P2.Healsremain=P2.Healsremain-1;//reduces number of heals by 1
                   SetColor(12);//health color
                   printf("%d\n", P2.Health);
                   SetColor(15);//sets color to white
                   delay(4000);
                   break;
                }
                system("cls");

            }
            Defeated=Ifdefeat(P1.Health, P2.Health);//check is 1 character is defeated:Kai
        }while(Defeated==0);

//check who won round
        if(Countcheck==0)//checks if p1 or p2 won round:Kai
        {
            P1.Roundwins++;//p1 wins round
            printf("Congradulations ");
            SetColor(11);
            printf("Player 1,");
            SetColor(15);
            printf(" you won the round!!!");
            delay(5000);
            system("cls");
            SetColor(15);//sets color to white
        }
        else
        {
            P2.Roundwins++;//p2 wins round
            printf("Congradulations ");
            SetColor(11);
            printf("Player 2,");
            SetColor(15);
            printf("you won the round!!!");
            delay(5000);
            system("cls");
            SetColor(15);//sets color to white
        }

//Checks if game won:Kai
        Winner=IfWinner(Roundcount, P1.Roundwins, P2.Roundwins);//checks if p1 or p2 won game:Kai


//if game not won reasigns characters: Kai and Mischa
        if (Winner==0)//reasign characters if round not won
        {
            SetColor(15);//sets color to white
            if (Countcheck==0)//if P1 won P2 chooses 1st
            {
                P2.Name=CharacterSelect(1, 2);//selects character for player2 (can't be same as player1):Mischa
                delay(2000);
                system("cls");

                P1.Name=CharacterSelect(P2.Name, 1);//selects character for player1:Mischa
                delay(2000);
                system("cls");//clears screen after 2 seconds
            }
            else//if P2 won P1 chooses first
            {
                P1.Name=CharacterSelect(1, 1);//selects character for player1: Mischa
                delay(2000);
                system("cls");//clears screen after 2 seconds

                P2.Name=CharacterSelect(P1.Name, 2);//selects character for player2 (can't be same as player1):Mischa
                delay(2000);
                system("cls");
            }
            temp=P1.Roundwins;
            P1=AssignStats(P1.Name);//gets stats for p1character based on selection:Kai
            P1.Roundwins=temp;
            temp=P2.Roundwins;
            P2=AssignStats(P2.Name);//gets stats for p2character based on selection:Kai
            P2.Roundwins=temp;
        }
    }

//If won, print winner screens: Reid
    if (Winner==1)//checks if p1 won game: Reid
    {
        WinScreen(1);//screen for p1 win
    }
    else if(Winner==2)//checks if p2 won game:Reid
    {
        WinScreen(2);//screen for p2 win
    }
    return 0;
}
