/***************************************************************************************
	Group Name            :    	TooMuchBlackjack
	1st Member Name       :   	TOK LIK YANG 
	1st Matric            :     	22011276
	2nd Member Name       :     JONATHAN VOON YEN JIE
	2nd Matric            :     	22011091

	Semester              :       	Sep 2024

-Command to compile the project (modify and include additional files if exist):

gcc TooMuchBlackjack.c gfx.c -o TooMuchBlackjack -lX11 -lm

- Use command below to run the program
        ./TooMuchBlackjack
***********************************************************************************/



#include <stdio.h>
#include "gfx.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include<string.h>

#define Cards 52
#define Characteristics 3
#define hand 11
double darken = 1;
void newgfx_color(int,int,int);
void Hit_button_first_frame();
void Hit_button_second_frame();
void Hit_button_third_frame();
void Hit_Text(int );
void Hit_Button_animation();

void Stand_button_first_frame();
void Stand_button_second_frame();
void Stand_button_third_frame();
void Stand_Text(int y9);
void Stand_Button_animation();
int  click_stand_button();

int Startscreen();
void Replay();
void Exit_Text(int y10);
void Play_Again_Text(int y11);
void Help(int);
void HelpScreen();


void remaining_cards(int,int,int);
void deckcard();

void Pixel(double,double,double,double);
void JiePixel(double xp,double yp,double wide, double high);

void dealer_body();
void dealer_arm_1st();
void dealer_arm_2nd();
void dealer_arm_3rd();
void dealer_arm_4th();
void card(char suit,char facevalue);
void suits(char check);

void dealer();

void redefine(int);
void redefine2();
void animate_deal(int);


int count = 0;
//dealer_guy
double scale ;
double displace_x ;
double displace_y ;
int click_hit_button();
int click_hit;
int click_PlayAgain();

int px,py;

int deckcardnum = 0;
int retry = 0;
int ending = 0;

int blur;
int zxc;

int previous_values[10];
int display_values[10];
int display_values_1;
int display_values_2;
int display_values_3;
int display_values_4;

const char Suit[4] = {'D', 'C', 'H', 'S'};
const char Face[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const char CardV[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'T', 'T', 'T'};   

void card_deck();
void deck_Shuffle();

void Card_Dealing(char[hand][Characteristics]);
void Total_Card_Value(char[hand][Characteristics],int*);

void Dealer_TURN(int*);
void Deck_print();

void display_hands();
const char* display_hands_part2(char,char);
void PlayerTotal();
void DealerTotal();
void help_me();
void initialize_to_zero();

void GameInProgress();
int Win_Condition();

void deck_count();
char InitialDeck[Cards][Characteristics]; 
char Final_deck[Cards][Characteristics];
char display_text[100];

int previous_values_1;
int previous_values_2;

//char Final_deck[4][3] = {{'D','A','1'},{'C','A','1'},{'H','A','1'},{'S','A','1'}};
void DisplayWin();
int a;
int card_sum;

char Player_deck[hand][Characteristics];
char Dealer_deck[hand][Characteristics];

char dealing_deck[hand][Characteristics];


int player_total[2];
int dealer_total[2];
int checklist[6] = {0};
int choice;
int just_another_variable;
char another_round;
int card_sum;
int win_lose;



int countingvar = 0;


//win = 1  		You WIN!!
//lose = 2 		Dealer WINS
//tie = 3 		TIE GAME
//both went bust = 4 	YOU BOTH WENT BUST, YOU BOTH LOSE
//Dealer went bust = 5 	DEALER WENT BUST YOU WIN
//YOU = 6		YOU WENT BUST DEALER WINS

int main(){
	Player_deck[10][0] = '1';
	Dealer_deck[10][0] = '0';
	int ysize = 800;
	int xsize = 1300;
	char c;
	int r,g,b,x,y=0;	
	
	gfx_open(xsize,ysize,"TOO MUCH BLACKJACK!!");
	gfx_clear_color(128,128,128);
	gfx_clear();
	initialize_to_zero();
	just_another_variable = 1;
	if(just_another_variable == 1){
		card_deck(); 
		srand(time(NULL));       
		deck_Shuffle();
		just_another_variable = 0;
		Deck_print();
		}
	
	while(1){
	
		Startscreen();
		
		if(ending == 2){
			HelpScreen();
			ending = 0;
			continue;
			}
		if(ending == 3){
			break;
			}
		
		while(1){
			initialize_to_zero();
			
			if(just_another_variable == 1){
				card_deck(); 
				srand(time(NULL));       
				deck_Shuffle();
				just_another_variable = 0;
				Deck_print();
				}
			for (a=1; a<=2; a++){
				Card_Dealing(Player_deck);
			  }
			for (a=1; a<=2; a++){
				Card_Dealing(Dealer_deck);
			 }
				
				display_hands();
				PlayerTotal();
				DealerTotal();
				checklist[5] = 1;
				GameInProgress();
				Win_Condition();
				DisplayWin();
				display_values_1 = 0;
				display_values_2 = 0;
				display_values_3 = 0;
				display_values_4 = 0;
				Replay();
				if (retry ==1){
					if(card_sum < 10){
						just_another_variable =1;
						}
					continue;
					}
				else if (retry== 0){
					break;
					}

				}
		}
}



int Startscreen(){
	darken = 1;
	scale = 0.5;
	displace_x = 0;
	displace_y = -50;
	newgfx_color(161*darken,102*darken,47*darken);//light brown
	Pixel(0,55,2000,2);
	newgfx_color(113*darken,72*darken,33*darken);//dark brown
	Pixel(0,58,2000,2);
	newgfx_color(1*darken,50*darken,32*darken);//dark green
	Pixel(0,60,2000,3);
	newgfx_color(6*darken,121*darken,1*darken);//light green
	Pixel(0,63,2000,1000);
	
	gfx_color(0,0,0);
	char *a = "WELCOME TO BLACKJACK!";
	gfx_text(a,525,100,2);

	
	displace_x = 450;
	displace_y = 150;
	Play_Again_Text(0);
	darken = 1;
	scale = 0.6;
	
	//Play Button
	newgfx_color(192,192,192);//silver
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);

	newgfx_color(128,128,128);//grey
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(65,65,65);//darkest grey
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);

	newgfx_color(19,122,99);//green
	gfx_fillrectangle(100*scale+ displace_x,100*scale + displace_y,436*scale,181*scale);//x+68,y+99
	

	newgfx_color(15,95,77);//dark green
	gfx_fillrectangle(100*scale+ displace_x,280*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(11,69,56);//darkest green
	gfx_fillrectangle(100*scale+ displace_x,290*scale + displace_y,436*scale,25*scale);
	Play_Again_Text(0);
	
	
	displace_y = 350;
	//Help Button
	newgfx_color(192,192,192);//silver
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);

	newgfx_color(128,128,128);//grey
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(65,65,65);//darkest grey
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(255,255,50);//light yellow
	gfx_fillrectangle(100*scale+ displace_x,100*scale + displace_y,436*scale,181*scale);//x+68,y+99
	
	darken = 1;
	newgfx_color(255, 235, 0);//yellow
	gfx_fillrectangle(100*scale+ displace_x,280*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(255,215,0);//gold
	gfx_fillrectangle(100*scale+ displace_x,290*scale + displace_y,436*scale,25*scale);
	Help(0);
	
	displace_x = 450;
	displace_y = 550;
	
	
	
	//Exit Button
	newgfx_color(192,192,192);//silver
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);

	newgfx_color(128,128,128);//grey
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(65,65,65);//darkest grey
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(168,0,0);//maroon
	gfx_fillrectangle(100*scale+ displace_x,100*scale + displace_y,436*scale,181*scale);//x+68,y+99
	
	newgfx_color(105, 0, 0);//dark maroon
	gfx_fillrectangle(100*scale+ displace_x,280*scale + displace_y,436*scale,15*scale);
	
	newgfx_color(74,0, 0);//darkest maroon
	gfx_fillrectangle(100*scale+ displace_x,290*scale + displace_y,436*scale,25*scale);
	displace_x = 460;
	Exit_Text(0);
	
	displace_x = 450;
	
	while (1){
		if(gfx_event_waiting()){
			char c = gfx_wait();
			if(c == 0x01){
				px = gfx_xpos();	
				py = gfx_ypos();
				}
			}
		if (px > 520 && px < 830 && py > 220 && py < 350){
			ending = 1;
			gfx_flush();
			break;
			}
		if (px > 520 && px < 830 && py > 420 && py < 550){
			ending = 2;
			break;
			}
		if (px > 520 && px < 830 && py > 620 && py < 750){
			ending = 3;
			break;
			}
		
	}
	px = 0;
	py = 0;
	return ending;
}


void HelpScreen(){
	char *text1 = "How to Play?";
	char *text2 = "The objective of the game is to achieve a total card value of BLACKJACK (21) ";
	char *text3 = "or have a hand value higher than the dealer's without exceeding 21.";
	char *text4 = "If the total value of cards exceeds 21, it is called a 'Bust,' and you lose immediately.";
	char *text5 = "____________________________________________________________________________________________________";
	char *text6 = "1. At the start of the game, the dealer deals two cards each to the player and themselves.";
	char *text7 = "2. The player can choose to 'Hit' or 'Stand': 'Hit' gives the player another card, while ";
	char *text8 = "  'Stand' passes the turn to the dealer.";
	char *text9 = "  The goal is to increase your card total without exceeding 21, or forcing the dealer to exceed it.";
	char *text10 = "3. The player can continue to 'Hit' multiple times until they either choose to";
	char *text11 ="  'Stand' or go 'Bust' (total exceeds 21).";
	char *text12 = "4. If the player goes 'Bust,' the dealer wins automatically. Conversely,";
	char *text13 = "  if the dealer goes 'Bust,' the player wins.";
	char *text14 = "5. On the dealer's turn, they must keep 'Hitting' until their total value";
	char *text15 = "  reaches at least 17, but they risk going 'Bust' as well.";
	char *text16 = "6. Once both the player and dealer complete their turns, the total values are compared.";
	char *text17 = "  The one with the higher value wins, provided neither has exceeded 21.";
	char *text18 = "7. If either the player or dealer gets exactly 21 on their first two cards,";
	char *text19 = "  it is called 'Blackjack,' and they win instantly!";
	char *text20 = "  This is the highest achievement in the game and an automatic victory!";
	int x, y;
	char c;

	gfx_clear_color(128, 128, 128);
	gfx_clear();
	darken = 1;
	scale = 0.5;
	displace_x = 0;
	displace_y = -50;
	newgfx_color(161*darken,102*darken,47*darken);//light brown
	Pixel(0,55,2000,2);
	newgfx_color(113*darken,72*darken,33*darken);//dark brown
	Pixel(0,58,2000,2);
	newgfx_color(1*darken,50*darken,32*darken);//dark green
	Pixel(0,60,2000,3);
	newgfx_color(6*darken,121*darken,1*darken);//light green
	Pixel(0,63,2000,1000);
	
	gfx_color(230, 230,230); // Faded Background
	gfx_fillrectangle(140, 150, 1000, 550);
	gfx_text(text1,580,100,2);

	gfx_color(0, 0, 0); // Black text
	gfx_text(text2,145, 170,1);
	gfx_text(text3,145, 200,1);
	gfx_text(text4,145, 230,1);
	gfx_text(text5,145, 245,1);	
	gfx_text(text6,145, 290,1);
	gfx_text(text7,145, 320,1);
	gfx_text(text8,145, 350,1);
	gfx_text(text9,145, 380,1);
	gfx_text(text10,145, 410,1);
	gfx_text(text11,145, 440,1);	
	gfx_text(text12,145, 470,1);
	gfx_text(text14,145, 500,1);
	gfx_text(text15,145, 530,1);
	gfx_text(text16,145, 560,1);
	gfx_text(text17,145, 590,1);
	gfx_text(text18,145, 620,1);
	gfx_text(text19,145, 650,1);
	gfx_text(text20,145, 680,1);
	
	displace_x = 870;
	displace_y = 550;
	scale = 0.5;
	newgfx_color(192,192,192);//silver
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);

	newgfx_color(128,128,128);//grey
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(65,65,65);//darkest grey
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(144,0,0);//maroon
	gfx_fillrectangle(100*scale+ displace_x,100*scale + displace_y,436*scale,181*scale);//x+68,y+99
	
	newgfx_color(113, 0, 0);//dark maroon
	gfx_fillrectangle(100*scale+ displace_x,280*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(84,0, 0);//darkest maroon
	gfx_fillrectangle(100*scale+ displace_x,290*scale + displace_y,436*scale,25*scale);
	displace_x = 875;
	Exit_Text(0);
	
	

	while (1) {
		if (gfx_event_waiting()){
			c = gfx_wait();
			x = gfx_xpos();
			y = gfx_ypos();

			if ((x > 920 && x < 1140) && (y > 590 && y < 700)) {
				break;
           		 }
        		}
		}
	gfx_clear();
}


void Help(int b){
	newgfx_color(0,0,0);//black
	gfx_fillrectangle(140*scale+ displace_x,130*scale + displace_y+b,10*scale,130*scale);
	gfx_fillrectangle(140*scale+ displace_x,180*scale + displace_y+b,70*scale,10*scale);
	gfx_fillrectangle(210*scale+ displace_x,130*scale + displace_y+b,10*scale,130*scale);
	//H
	
	displace_x = 460;
	gfx_fillrectangle(230*scale+ displace_x,130*scale + displace_y+b,10*scale,130*scale);
	gfx_fillrectangle(230*scale+ displace_x,130*scale + displace_y+b,70*scale,10*scale);
	gfx_fillrectangle(230*scale+ displace_x,180*scale + displace_y+b,70*scale,10*scale);
	gfx_fillrectangle(230*scale+ displace_x,250*scale + displace_y+b,70*scale,10*scale);
	//E
	
	gfx_fillrectangle(320*scale +displace_x, 130*scale + displace_y+b, 10*scale, 130*scale);
	gfx_fillrectangle(320*scale +displace_x, 250*scale + displace_y+b, 70*scale, 10*scale);
	//L
	
	gfx_fillrectangle(410*scale+ displace_x, 130*scale + displace_y+b, 10*scale, 130*scale);
	gfx_fillrectangle(410*scale+ displace_x, 130*scale + displace_y+b, 70*scale, 10*scale);
	gfx_fillrectangle(410*scale+ displace_x, 190*scale + displace_y+b, 70*scale, 10*scale);
	gfx_fillrectangle(480*scale+ displace_x, 140*scale + displace_y+b, 10*scale, 50*scale);
	//P
	
}



void redefine(int b)
{		

		scale = 0.5;
		displace_x = 0;
		displace_y = -100;
		newgfx_color(161,102,47);//light brown
		Pixel(0,55,2000,2);
		newgfx_color(113,72,33);//dark brown
		Pixel(0,58,2000,2);
		newgfx_color(1,50,32);//dark green
		Pixel(0,60,2000,3);
		newgfx_color(6,121,1);//light green
		Pixel(0,63,2000,1000);


		scale = 0.7;
		displace_x = 0;
		displace_y = 450;
		
		
		if(count == 7 && click_stand_button() == 1){
			Stand_button_first_frame();
			Stand_Text(0);
		}
		
		if(click_stand_button() == 1){
			displace_y = 200;
			Hit_button_first_frame();
			Hit_Text(0);
		
		}
		else{
			Stand_button_first_frame();
			Stand_Text(0);
		}
		
		displace_y = 200;
		if(count == 7 && click_hit_button() == 1){
			Hit_button_first_frame();
			Hit_Text(0);
		}
		
		
		if(count%6 == 2 && click_hit_button() == 1){
			displace_y = 200;
			scale = 0.7;
			displace_x = 0;
			Hit_button_second_frame();
			Hit_Text(40);
		}
		if(click_hit_button() == 1){
			displace_y = 450;
			Stand_button_first_frame();
			Stand_Text(0);
		}
		
		else{
			Hit_button_first_frame();
			Hit_Text(0);
		}
		
		scale = 0.5;

		//center deck
		displace_x = 1100;
		displace_y = 60;
		blur = 0;
		
		displace_x = 0;
		displace_y = -100;
		deckcard();
		
		displace_x = 1100;
		displace_y = 60;
		
		int x2 = 1100;
		int y2 = 60;
		int x1;
		int y1 ;
		char suit_V;
		char Face_value;
		
		PlayerTotal();
		DealerTotal();


		
		if(b == 1){
			for(int i = 0;i < 10; i++){
				if (Player_deck[i][2]!=0) 
			    	{
					suit_V = Player_deck[i][0];
					Face_value = Player_deck[i][1];
					x1 = 540;
					y1 = 240;
					for(int j = 0; j < i;j++){
						x1 = x1 + 60;
						y1 = y1 + 10;
				
					}
					double dist_x = abs(x1 - x2)/10;
					double dist_y = abs(y1 - y2)/10;
					displace_x = x2;
					displace_y = y2;
					double lastx;
					double lasty;
					lastx = displace_x;
					lasty = displace_y;
					suit_V = Player_deck[i][0];
					
					for(int z = 0; z < 10; z++){
						
							displace_x = lastx - dist_x;
							displace_y = lasty - dist_y;
							lastx = lastx - dist_x;
							
							if(Player_deck[10][0] == '0')
								lasty = lasty - dist_y;
							else if(Player_deck[10][0] == '1')
								lasty = lasty + dist_y;
						}
					blur = 0;
					card(suit_V,Face_value);
					

				}
			}
			
			//dealer first
			for(int i = 0;i < 10; i++){
				if (Dealer_deck[i][2]!=0) 
			    	{
					suit_V = Dealer_deck[i][0];
					Face_value = Dealer_deck[i][1];
					x1 = 540;
					y1 = -125;
					for(int j = 0; j < i;j++){
						x1 = x1 + 60;
						y1 = y1 + 10;
				
					}
					double dist_x = abs(x1 - x2)/10;
					double dist_y = abs(y1 - y2)/10;
					displace_x = x2;
					displace_y = y2;
					double lastx;
					double lasty;
					lastx = displace_x;
					lasty = displace_y;
					suit_V = Dealer_deck[i][0];
					
					for(int z= 0; z < 10; z++){
						
							displace_x = lastx - dist_x;
							displace_y = lasty - dist_y;
							lastx = lastx - dist_x;
							
							if(Dealer_deck[10][0] == '0')
								lasty = lasty - dist_y;
							else if(Dealer_deck[10][0] == '1')
								lasty = lasty + dist_y;
						}
					blur = 0;
					card(suit_V,Face_value);
					
				}
			}
			
		PlayerTotal();	
		}
		
	else{
		// printing the cards before the last card
		int p;
		int d;
		for(int i = 0;i < 10; i++){
			if(Player_deck[i+1][2]==0 && dealing_deck[10][0] == '1')
			{
				p = i;
				break;
			}
			
			if (Player_deck[i][2]!=0) 
		    	{
				suit_V = Player_deck[i][0];
				Face_value = Player_deck[i][1];
				x1 = 540;
				y1 = 240;
				for(int j = 0; j < i;j++){
					x1 = x1 + 60;
					y1 = y1 + 10;
			
				}
				double dist_x = abs(x1 - x2)/10;
				double dist_y = abs(y1 - y2)/10;
				displace_x = x2;
				displace_y = y2;
				double lastx;
				double lasty;
				lastx = displace_x;
				lasty = displace_y;
				suit_V = Player_deck[i][0];
				
				for(int z = 0; z < 10; z++){
					
						displace_x = lastx - dist_x;
						displace_y = lasty - dist_y;
						lastx = lastx - dist_x;
						
						if(Player_deck[10][0] == '0')
							lasty = lasty - dist_y;
						else if(Player_deck[10][0] == '1')
							lasty = lasty + dist_y;
					}
				blur = 0;
				card(suit_V,Face_value);
				
				
			}
		}
		
		//dealer first
		for(int i = 0;i < 10; i++){
		
			if (Dealer_deck[i+1][2]==0 && dealing_deck[10][0] == '0') 
			{
				break;
			}
			
			if (Dealer_deck[i][2]!=0) 
		    	{
				suit_V = Dealer_deck[i][0];
				Face_value = Dealer_deck[i][1];
				x1 = 540;
				y1 = -125;
				for(int j = 0; j < i;j++){
					x1 = x1 + 60;
					y1 = y1 + 10;
			
				}
				double dist_x = abs(x1 - x2)/10;
				double dist_y = abs(y1 - y2)/10;
				displace_x = x2;
				displace_y = y2;
				double lastx;
				double lasty;
				lastx = displace_x;
				lasty = displace_y;
				suit_V = Dealer_deck[i][0];
				
				for(int z= 0; z < 10; z++){
					
						displace_x = lastx - dist_x;
						displace_y = lasty - dist_y;
						lastx = lastx - dist_x;
						
						if(Dealer_deck[10][0] == '0')
							lasty = lasty - dist_y;
						else if(Dealer_deck[10][0] == '1')
							lasty = lasty + dist_y;
					}
				blur = 0;
				card(suit_V,Face_value);
				
				
			}
			
		}
		
		
		PlayerTotal();
		
		}
		deck_count();
		
}
		
		

void Card_Dealing(char deck[hand][Characteristics])
{ 
	int x2 = 1100;
	int y2 = 60;
        int i,deck_index;
        int x1;
	int y1 ;
	
        for (i = 0; i < 10;i++)
        {
            if (deck[i][2]==0) 
            {
                deck_index = i;
                break;
            }
        }
        
        if(deck[10][0]  == '0'){
		x1 = 540;
		y1 = -125;
		for(i = 0; i < deck_index;i++){
			x1 = x1 + 60;
			y1 = y1 + 10;
			
		}
	}
	else if(deck[10][0] == '1'){
		x1 = 540;
		y1 = 240;

		for(i = 0; i< deck_index;i++){
			x1 = x1 + 60;
			y1 = y1 + 10;
		}
	}
	
	
     double dist_x = abs(x1 - x2)/10;
	double dist_y = abs(y1 - y2)/10;
	displace_x = x2;
	displace_y = y2;
	double lastx;
	double lasty;
	lastx = displace_x;
	lasty = displace_y;
	
        for(i = 0; i<52;i++)
        {
            if(Final_deck[i][2] != 0)
            {
                deck[deck_index][0] = Final_deck[i][0];
                deck[deck_index][1] = Final_deck[i][1];
                deck[deck_index][2] = Final_deck[i][2];
                Final_deck[i][2] = 0;
                break;
            }
        }
        char suit_determinant = deck[deck_index][0];
        char face_value = deck[deck_index][1];
		for(int c = 0 ; c < 11; c++){
			dealing_deck[c][0] = deck[c][0];
			dealing_deck[c][1] = deck[c][1];
			dealing_deck[c][2] = deck[c][2];
		}
		
			
        for(i = 0; i < 10; i++){
			countingvar++;
			redefine(0);
			displace_x = lastx - dist_x;
			displace_y = lasty - dist_y;
			lastx = lastx - dist_x;
			
			if(deck[10][0] == '0')
				lasty = lasty - dist_y;
			else if(deck[10][0] == '1')
				lasty = lasty + dist_y;
				
			blur = 1;
			
			card(suit_determinant,face_value);

			
			gfx_flush();
			usleep(100000);	
			gfx_clear();
			redefine(0);
			
		}
	deckcardnum++;
	blur = 0;
	redefine(1);
	deck_count();
	gfx_flush();
	usleep(50000);	
	gfx_clear();
	redefine(1);
	
        

}










void Hit_button_first_frame()
{

	newgfx_color(161,66,0);//wood
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);

	newgfx_color(127,52,0);//dark wood
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(101,41,0);//darkest wood
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(0,182,255);//blue
	gfx_fillrectangle(100*scale+ displace_x,100*scale + displace_y,436*scale,181*scale);//x+68,y+99
	
	newgfx_color(0, 160, 224);//dark blue
	gfx_fillrectangle(100*scale+ displace_x,280*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(0, 116, 162);//darkest blue
	gfx_fillrectangle(100*scale+ displace_x,290*scale + displace_y,436*scale,25*scale);
}

void Hit_button_second_frame()//50 y-axis displace for text
{

	newgfx_color(130,53,0);//wood
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);
	
	newgfx_color(96,39,0);//dark wood
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(70,29,0);//darkest wood
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(0, 160, 224);//blue
	gfx_fillrectangle(100*scale+ displace_x,170*scale + displace_y,436*scale,140*scale);//x+68,y+99
	
	newgfx_color(0, 138, 193);//dark blue
	gfx_fillrectangle(100*scale+ displace_x,310*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(0, 94, 131);//darkest blue
	gfx_fillrectangle(100*scale+ displace_x,320*scale + displace_y,436*scale,25*scale);
}

void Hit_button_third_frame()//40 y-axis displacement
{


	newgfx_color(130,53,0);//wood
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);
	
	newgfx_color(96,39,0);//dark wood
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(70,29,0);//darkest wood
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(0, 160, 224);//blue
	
	gfx_fillrectangle(100*scale+ displace_x,150*scale + displace_y,436*scale,160*scale);//x+68,y+99
	
	newgfx_color(0, 138, 193);//dark blue
	
	gfx_fillrectangle(100*scale+ displace_x,310*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(0, 94, 131);//darkest blue
	
	gfx_fillrectangle(100*scale+ displace_x,320*scale + displace_y,436*scale,25*scale);
}

void Hit_Text(int y9)
{
	newgfx_color(0,0,0);//black
	gfx_fillrectangle(140*scale+ displace_x,130*scale + displace_y+y9,10*scale,100*scale);
	gfx_fillrectangle(140*scale+ displace_x,170*scale + displace_y+y9,100*scale,10*scale);
	gfx_fillrectangle(230*scale+ displace_x,130*scale + displace_y+y9,10*scale,100*scale);
	//H
	
	gfx_fillrectangle(280*scale+ displace_x,130*scale + displace_y+y9,90*scale,10*scale);
	gfx_fillrectangle(320*scale+ displace_x,130*scale + displace_y+y9,10*scale,100*scale);
	gfx_fillrectangle(280*scale+ displace_x,220*scale + displace_y+y9,90*scale,10*scale);
	//I
	

	gfx_fillrectangle(400*scale+ displace_x,130*scale + displace_y+y9,90*scale,10*scale);
	gfx_fillrectangle(440*scale+ displace_x,130*scale + displace_y+y9,10*scale,105*scale);
	//T
}



void Stand_button_first_frame()
{
	newgfx_color(161,66,0);//wood
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);

	newgfx_color(127,52,0);//dark wood
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(101,41,0);//darkest wood
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(144, 0, 0);//red
	gfx_fillrectangle(100*scale+ displace_x,100*scale + displace_y,436*scale,181*scale);//x+68,y+99
	
	newgfx_color(113, 0, 0);//dark red
	gfx_fillrectangle(100*scale+ displace_x,280*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(84, 0, 0);//darkest red
	gfx_fillrectangle(100*scale+ displace_x,290*scale + displace_y,436*scale,25*scale);
}

void Stand_button_second_frame()//50 y-axis displace for text
{
	newgfx_color(130,53,0);//wood
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);
	
	newgfx_color(96,39,0);//dark wood
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(70,29,0);//darkest wood
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(113, 0, 0);//red
	gfx_fillrectangle(100*scale+ displace_x,170*scale + displace_y,436*scale,140*scale);//x+68,y+99
	
	newgfx_color(82, 0, 0);//dark red
	gfx_fillrectangle(100*scale+ displace_x,310*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(51, 0, 0);//darkest red
	gfx_fillrectangle(100*scale+ displace_x,320*scale + displace_y,436*scale,25*scale);
}

void Stand_button_third_frame()//40 y-axis displacement
{

	newgfx_color(130,53,0);//wood
	gfx_fillrectangle(70*scale+ displace_x,170*scale + displace_y,495*scale,185*scale);
	
	newgfx_color(96,39,0);//dark wood
	gfx_fillrectangle(70*scale+ displace_x,355*scale + displace_y,495*scale,9*scale);
	
	newgfx_color(70,29,0);//darkest wood
	gfx_fillrectangle(70*scale+ displace_x,363*scale + displace_y,495*scale,25*scale);
	
	newgfx_color(113, 0, 0);//red
	
	gfx_fillrectangle(100*scale+ displace_x,150*scale + displace_y,436*scale,160*scale);//x+68,y+99
	
	newgfx_color(82, 0, 0);//dark red
	
	gfx_fillrectangle(100*scale+ displace_x,310*scale + displace_y,436*scale,10*scale);
	
	newgfx_color(51, 0, 0);//darkest red
	
	gfx_fillrectangle(100*scale+ displace_x,320*scale + displace_y,436*scale,25*scale);
}


void Pixel(double x_p,double y_p,double width, double height )
{
	x_p = (x_p) *10.4;
	y_p = y_p *10.4;
	width =  (width + 1)*10.4;
	height = (height + 1)*10.4;
	gfx_fillrectangle(x_p*scale+ displace_x, y_p*scale + displace_y ,width*scale ,height*scale );
}






void suits(char check){
	float x = 0;
	float y = 0;
	switch (check){
		case 'D':
			newgfx_color(255,0,0);
			x = 98;
			y = 400;
			for(int i = 0; i < 26;i+= 2){	
				gfx_fillrectangle(x-i+displace_x, y+i+displace_y,(1+i)*scale,3*scale);
				gfx_fillrectangle(x+displace_x, y+i+displace_y,(1+i)*scale,3*scale);
				y +=1;
				}
			x = 98;
			y = 465;
			for(int i = 26; i > 0;i-=2){	
				gfx_fillrectangle(x-i+1+displace_x, y-i+displace_y,(i-1)*scale,3*scale);
				gfx_fillrectangle(x-1+displace_x, y-i+displace_y,(i-1)*scale,3*scale);
				y +=1;
				}
			break;
			
		case 'S':
			gfx_fillcircle(83+displace_x,446+displace_y,25*scale);
			gfx_fillcircle(112+displace_x,446+displace_y,25*scale);
			x = 98;
			y = 405;
			for(int i = 0; i < 27;i+= 2){	
				gfx_fillrectangle(x-i+displace_x, y+i+displace_y,(1+i)*scale,3*scale);
				gfx_fillrectangle(x+displace_x, y+i+displace_y,(1+i)*scale,3*scale);
				y +=1;
				
				}
			gfx_fillrectangle(97+displace_x,445+displace_y,3*scale,22*scale);
			gfx_fillrectangle(95+displace_x,455+displace_y,7*scale,15*scale);
			break;
			
		case 'H':
			newgfx_color(255,0,0);
			gfx_fillcircle(82+displace_x,430+displace_y,32*scale);
			gfx_fillcircle(111+displace_x,430+displace_y,32*scale);
			x = 97;
			y = 466;	
			for(int i = 28; i > 0;i-=2){	
				gfx_fillrectangle(x-i+displace_x, y-i+displace_y,(1+i)*scale,4*scale);
				gfx_fillrectangle(x-1+displace_x, y-i+displace_y,(1+i)*scale,4*scale);
				y +=1;
				}
			break;
			
		case 'C':
			gfx_fillcircle(97+displace_x,425+displace_y,32*scale);
			gfx_fillcircle(82+displace_x,450+displace_y,32*scale);
			gfx_fillcircle(112+displace_x,450+displace_y,32*scale);
			gfx_fillrectangle(93+displace_x,435+displace_y,7*scale,40*scale);
			gfx_fillrectangle(95+displace_x,435+displace_y,7*scale,40*scale);
			break;				
		}
}



void initialize_to_zero()
{
	int i;
	for (i = 0; i < 10;i++)
        {
        	Player_deck[i][0] = 0;
        	Player_deck[i][1] = 0;
            	Player_deck[i][2] = 0;
            	Dealer_deck[i][0] = 0;
        	Dealer_deck[i][1] = 0;
            	Dealer_deck[i][2] = 0;
        }
        win_lose = 0;
        for (i = 0; i < 6;i++)
        {
        	checklist[i] = 0;
        }
        
}



void card_deck(){
	int z = 0;
	for (int index = 0; index < 4; index++){
		for (int joke = 0; joke < 13; joke++){
			InitialDeck[z][0] = Suit[index];
			InitialDeck[z][1] = Face[joke];
			InitialDeck[z][2] = CardV[joke];	
			z = z+1;
		}
	}
}
  
 void deck_Shuffle()// ヽ( ´￢`)ﾉ ﾜ～ｲ
  {
        int i = 0, Shuffle_Index,placeholder,index;
        int duplic[52] = {[ 0 ...51]=53};
        int sum = 0;
        
            while(1)
                {
                    
                    sum = 0;
                    index = index + rand();
                    srand(index);
                    placeholder =(int) rand()%52;

	                for(Shuffle_Index =0;Shuffle_Index < 52; Shuffle_Index++)
	                {
                                if (duplic[Shuffle_Index] == placeholder){
                                    sum = sum + 1; 
                            }
                        }
                          
                       if( sum == 0)
                       {
                          duplic[i] = placeholder;
                          Final_deck[placeholder][0] = InitialDeck[i][0];
                          Final_deck[placeholder][1] = InitialDeck[i][1];
                          Final_deck[placeholder][2] = InitialDeck[i][2];
                          if(i == 51)
                              break;
                          else
                              i = i + 1;
                        }
                    	
                        
                 }
  }



void deck_count()
{
	int i;
	card_sum = 1;
	for(i = 0; i < 52; i++){
		if(Final_deck[i][2] != 0){
			card_sum = card_sum + 1;
		}
	}
	card_sum = card_sum - 1;
	printf("\nThere are %d cards remaining in the deck.\n",card_sum);
	remaining_cards(1100,240,card_sum);
}





void Deck_print()
{
	FILE *fp = fopen("NewDeck.txt","w+");
	int test1;
	
	for(a = 0; a < 52;a++)
	    {     
		  if (InitialDeck[a][2]== '1'){
		      fprintf(fp,"%c\t%c\t1 or 11\n",InitialDeck[a][0],InitialDeck[a][1]);
		    }
		    
		  else if(InitialDeck[a][1]== 'J'||InitialDeck[a][1]== 'Q'||InitialDeck[a][1]== 'K'||InitialDeck[a][1]== 'T')
		      fprintf(fp,"%c\t%c\t10\n",InitialDeck[a][0],InitialDeck[a][1]);
		      
		  else{
		      int num =0;
		      num = InitialDeck[a][2] - '0' ;
		      fprintf(fp,"%c\t%c\t%d\n",InitialDeck[a][0],InitialDeck[a][1],num);
		      }
	    }
	   	fclose(fp);
		FILE *fq = fopen("ShuffledDeck.txt","w+");
		for(a=0;a < 52;a++)
		{
		  if (Final_deck[a][2]== '1'){
		      fprintf(fq,"\t%c\t%c\t1 or 11\n",Final_deck[a][0],Final_deck[a][1]);
		    }
		    
		  else if(Final_deck[a][1]== 'J'||Final_deck[a][1]== 'Q'||Final_deck[a][1]== 'K'||Final_deck[a][1]== 'T')
		      fprintf(fq,"\t%c\t%c\t10\n",Final_deck[a][0],Final_deck[a][1]);
		      
		  else{
		      int num =0;
		      num = Final_deck[a][2] - '0';
		      fprintf(fq,"\t%c\t%c\t%d\n",Final_deck[a][0],Final_deck[a][1],num);
		      }
		}
		fclose(fq);
}

void GameInProgress()
{
	char thing;
	char c;
	while(1){
		redefine(1);
		if(dealer_total[0] == 21 && player_total[0] == 21){
                      checklist[1] = 1;
                      checklist[3] = 1;
                      checklist[5] = 0;
                      win_lose = 9;
                      printf("ITS A DRAW!!! BOTH BLACKJACKS");
                      break;
                        }
		if(dealer_total[0] == 21||dealer_total[1] == 21){
			checklist[3] = 1;
			checklist[5] = 0;
			printf("\t\t\tBLACKJACK!");
			win_lose = 8;
			break;
               }
		if(player_total[0] == 21||player_total[1] == 21){
			checklist[1] = 1;
			checklist[5] = 0;
			printf("\t\t\tBLACKJACK!");
			win_lose = 7;
			break;
               }
     		break;
            }
	while(checklist[5]){
		if(gfx_event_waiting())
			{
				c =gfx_wait();
				printf("%d , %d \n", gfx_xpos(),gfx_ypos());
				if(c == 0x01)
				{
					px = gfx_xpos();	
					py = gfx_ypos();
				}
				
			} 
				
		if(player_total[0] == 21||player_total[1] == 21){
			checklist[1] = 1;
			checklist[4] = 1;
			break;
			}
          
            if(player_total[0] == player_total[1]){
                if(player_total[0]>21){
                    checklist[0] = 1;
                    checklist[4] = 1;
                    break;
                    }
                  }
            else{
                if(player_total[0]>21 && player_total[1]>21 ){
                    checklist[0] = 1;
                    checklist[4] = 1;
                    break;
            }
		}

		
		if (click_hit_button() == 1)
		{
			Hit_Button_animation();

			//display_hands();
			//PlayerTotal(0);
			//DealerTotal();
			py = 0;
			px = 0;
			
		}
		if(click_stand_button() == 1){
			Stand_Button_animation();
			checklist[4] = 1;
			py = 0;
			px = 0;
			break;
		}
		
            
         
                      
          
          gfx_flush();
		usleep(100000);
		gfx_clear();
		redefine(1);
		py = 0;
		px = 0;
			

      }
   
      while(checklist[4])
                      {

                        if(dealer_total[0] == 21||dealer_total[1] == 21)
                          {
                            checklist[3] = 1;
                            break;
                              }
                            
                                  if(dealer_total[0] == dealer_total[1]){
                                      if(dealer_total[0]>21){
                                          checklist[2] = 1;
                                          break;
                                          }
                                      }
                                  else{
                                      if(dealer_total[0]>21 && dealer_total[1]>21 ){
                                          checklist[2] = 1;
                                          break;
                                          }
                                      }
                                                
                              if(dealer_total[0] < 17 )
                                {
                                  
                                  Card_Dealing(Dealer_deck);
                                  printf("\nDealer is drawing...\n");
                                  
                                  display_hands();
                                  //PlayerTotal(0);
                                  //DealerTotal();
                                  
                                    }
                              else if(dealer_total[0] != dealer_total[1]){
                                  if (dealer_total[0] < 17){
                                        Card_Dealing(Dealer_deck);
                                        display_hands();
                                        //PlayerTotal(0);
                                        //DealerTotal();
                                        }
                                  else
                                        break;
                                }
                              else
                                  break;
                 }

}

void Hit_Button_animation()
{
	int x,y;
	double s;
	x = 0;
	y = 200;
	s = 0.7;
	

	
	if(click_hit_button() == 1){
		
		for(count = 0 ; count < 7; count++)
		{
			redefine(1);
			displace_y = y;
			scale = s;
			displace_x = x;
			if(count%6 >= 0 && count%6 <= 1){
					
					Hit_button_first_frame();
					Hit_Text(0);
					}
			else if (count%6 == 2){
					Card_Dealing(Player_deck);
					displace_y = y;
					scale = s;
					displace_x = x;
					Hit_button_second_frame();
					Hit_Text(40);
					
				}
			else{
					Hit_button_third_frame();
					Hit_Text(30);

					}
			gfx_flush();
			usleep(167000);	
			gfx_clear();
			
			}
		redefine(1);
		displace_y = y;
		scale = s;
		displace_x = x;
		Hit_button_first_frame();
		Hit_Text(0);
		}
	else{
		redefine(1);
		displace_y = y;
		scale = s;
		displace_x = x;
		Hit_button_first_frame();
		Hit_Text(0);
	}
		
	
		
}



		
int click_hit_button()
{
	if(px>70 && px<380 && py>270 && py<400 ){
		return 1;
	}
	else
		return 0;
}



void Stand_Button_animation()
{
	int y,x;
	double s;
	y = 450;
	x = 0;
	s = 0.7;
	
	if(click_stand_button() == 1){
		
		for(count = 0 ; count<7; count++)
		{
			redefine(1);
			displace_y = y;
			scale = s;
			displace_x = x;
			if(count%6 >= 0 && count%6 <= 1){
					Stand_button_first_frame();
					Stand_Text(0);
					}
					
				else if (count%6 == 2){
					Stand_button_second_frame();
					Stand_Text(30);
				}
				
				else{
					Stand_button_third_frame();
					Stand_Text(20);
					}
			gfx_flush();
			usleep(167000);	
			gfx_clear();
			
			}
		redefine(1);
		displace_y = y;
		displace_x = x;
		scale = s;
		Stand_button_first_frame();
		Stand_Text(0);
		}
	else{
		redefine(1);
		displace_y = y;
		displace_x = x;
		scale = s;
		Stand_button_first_frame();
		Stand_Text(0);
	}
		
		
}

int click_stand_button()
{
	if(px>70 && px<380 && py>520 && py<650 ){
		return 1;
	}
	else
		return 0;
}




int click_PlayAgain(){

	if(px>70 && px<380 && py>270 && py<400){
		return 1;
		}
	else{
		return 0;
		}
}





int click_Exitgame(){

	if(px>70 && px<380 && py>520 && py<650){
		return 1;
		}
	else{
		return 0;
		}
}

int Win_Condition()//PEAK EFFICIENCY ヾ(￣∇￣=ﾉ 
{

//win = 1  		You WIN!!
//lose = 2 		Dealer WINS
//tie = 3 		TIE GAME
//both went bust = 4 	YOU BOTH WENT BUST, YOU BOTH LOSE
//Dealer went bust = 5 	DEALER WENT BUST YOU WIN
//YOU BUST = 6		YOU WENT BUST DEALER WINS
//YOU BLACKJACK = 7     BLACKJACK!!YOU GOT BLACKJACK
//Dealer blakcjack = 8  BLACKJACK!! DEALER GOT BLACKACJ
//double blackjack = 9 
    printf("\n\t\t\t");
    if(win_lose == 7 || win_lose == 8 || win_lose == 9)
    {
    return 0;
    }
    if(checklist[0] == 1){
          if(checklist[2] == 1){
          	win_lose = 4;
                printf("You BOth Lose\n");
                return 0;
                }
                
          else {
                printf("YOU WENT BUST!! DEALER WINS\n");
                win_lose = 6;
                return 0;
                }
    
          }
    if(checklist[1] == 1){
          if(checklist[3] == 1){
                printf("TIE GAME\n");
                win_lose = 3;
                return 0;
                }
                
          else{
                printf("\n\t\t\tYOU WIN Ｏ(≧∇≦)Ｏ \n");
                win_lose = 1;
                return 0;
                }
              }
              
    if(checklist[2] == 1){
          if(checklist[0] == 1){
          	win_lose = 4;
                printf("You BOth Lose\n");
                return 0;
                }
                
          else{
                printf("DEALER WENT BUST!!\nYOU WIN\n");
                win_lose = 5;
                return 0;
                }
              } 
    if(checklist[3] == 1){
          if(checklist[1] == 1){
                printf("TIE GAME\n");
                win_lose = 3;
                return 0;
                }
                
          else{
                printf("DEALER WINS\n");
                 win_lose = 2;
                return 0;
                }
              } 
    for(a = 0; a < 6;a++){
          checklist[a] = 0;
          }

    if(player_total[0] > 21){
          if(player_total[1] > dealer_total[0]||player_total[1] > dealer_total[1]){
                printf("YOU WIN\n");
                win_lose = 1;
                return 0;
                }
              
          else if(player_total[1] == dealer_total[0]||player_total[1] == dealer_total[1]){
                printf("TIE GAME\n");
                win_lose = 3;
                return 0;
                }
          else{
                printf("YOU WENT BUST!!! DEALER WINS\n");
                win_lose = 6;
                return 0;
          } 
    }
    else{
        if(dealer_total[0] == dealer_total[1]){
                
                    if(player_total[0] > dealer_total[0]){
                        printf("YOU WIN\n");
                        win_lose = 1;
                        return 0;
                    }
                    else if(player_total[0] == dealer_total[0]){
                        printf("TIE GAME\n");
                        win_lose = 3;
                        return 0;
                    }
                    else{
                        printf("Dealer Wins\n");
                        win_lose = 2;
                        return 0;
                       }
                    }
                    
                           
          
        else{
                  if(dealer_total[0] > 21){
                          if(player_total[0] > dealer_total[1]){
                              printf("YOU WIN\n");
                              win_lose = 1;
                              return 0;
                          }
                          else if(player_total[0] == dealer_total[1]){
                              printf("Both players have the same value. TIE GAME\n");
                              win_lose = 3;
                              return 0;
                            }
                          else{
                              printf("Dealer Wins\n");
                              win_lose = 2;
                              return 0;
                          }
                    }
                  else{
                          if(player_total[0] > dealer_total[0]){
                              printf("YOU WIN\n");
                              win_lose = 1;
                              return 0;
                          }
                          else if(player_total[0] == dealer_total[0]){
                              printf("TIE GAME\n");
                              win_lose = 3;
                              return 0;
                          }
                          else{
                              printf("Dealer Wins\n");
                              win_lose = 2;
                              return 0;
                             }
                    } 
              }             
          }
  	//win = 1  		You WIN!!
//lose = 2 		Dealer WINS
//tie = 3 		TIE GAME
//both went bust = 4 	YOU BOTH WENT BUST, YOU BOTH LOSE
//Dealer went bust = 5 	DEALER WENT BUST YOU WIN
//YOU BUST = 6		YOU WENT BUST DEALER WINS
//YOU BLACKJACK = 7     BLACKJACK!!YOU GOT BLACKJACK
//Dealer blakcjack = 8  BLACKJACK!! DEALER GOT BLACKACJ
//double blackjack = 9 
	
          
  }
  
  
void DisplayWin()
{
while(1){
	switch(win_lose)
          {
          	case 1:
          		strcpy(display_text,"YOU WIN !!");
                        break;
                case 2:
          		strcpy(display_text,"DEALER WINS");
                        break;
                case 3:
          		strcpy(display_text,"TIE GAME");
                        break;
                case 4:
          		strcpy(display_text,"YOU BOTH WENT BUST! YOU BOTH LOSE");
                        break;
                case 5:
          		strcpy(display_text,"DEALER WENT BUST! YOU WINS");
                        break;
                case 6:
          		strcpy(display_text,"YOU WENT BUST! DEALER WINS");
                        break;
                case 7:
                	strcpy(display_text,"BLACKJACK!!YOU GOT BLACKJACK");
                        break;
                case 8:
                	strcpy(display_text,"BLACKJACK!! DEALER GOT BLACKJACK");
                        break;
        	case 9:
        		strcpy(display_text,"DOUBLE BLACKJACK!! ITS A TIE");
                        break;
          }
          
          
          
          
          
          redefine2();
          
          newgfx_color(255,255,255);
          gfx_text(display_text,550,450,2);
          gfx_flush();
          char *ask_user = "Do you wish to play another round?";
          gfx_text(ask_user, 550, 500,2);
        
          gfx_flush();
          
          
          
          break;
          
          }
}

void Replay(){
	displace_x = 0;
	displace_y = 200;
	scale = 0.7;
	Hit_button_first_frame();
	Play_Again_Text(0);

	
	displace_y = 450;
	Stand_button_first_frame();
	Exit_Text(0);
	
	gfx_flush();
	usleep(1000000);
	while (1){
		if (gfx_event_waiting()){
			char test =gfx_wait();
			if(test == 0x01)
				{
					px = gfx_xpos();	
					py = gfx_ypos();
				}
			if(click_PlayAgain() ==1){
				retry = 1;
				usleep(1000000);	
				break;
				}
			else if(click_Exitgame() == 1){
				retry = 0;
				break;
			}
		}
	}
	px = 0;
	py = 0;	
		
}
	
void redefine2()
{
		int b = 1;
		darken = 0.5;
		scale = 0.5;
		displace_x = 0;
		displace_y = -100;
		newgfx_color(161*darken,102*darken,47*darken);//light brown
		Pixel(0,55,2000,2);
		newgfx_color(113*darken,72*darken,33*darken);//dark brown
		Pixel(0,58,2000,2);
		newgfx_color(1,50,32);//dark green
		Pixel(0,60,2000,3);
		newgfx_color(6,121,1);//light green
		Pixel(0,63,2000,1000);

		
		scale = 0.7;
		displace_x = 0;
		displace_y = 450;
		
		
		
		scale = 0.5;

		//center deck
		displace_x = 0;
		displace_y = -100;
		deckcard();
		blur = 0;
		int x2 = 1100;
		int y2 = 60;
		int x1;
		int y1 ;
		char suit_V;
		char Face_value;
	
		
		if(b == 1){
		for(int i = 0;i < 10; i++){
			if (Player_deck[i][2]!=0) 
		    	{
				suit_V = Player_deck[i][0];
				Face_value = Player_deck[i][1];
				x1 = 540;
				y1 = 240;
				for(int j = 0; j < i;j++){
					x1 = x1 + 60;
					y1 = y1 + 10;
			
				}
				double dist_x = abs(x1 - x2)/10;
				double dist_y = abs(y1 - y2)/10;
				displace_x = x2;
				displace_y = y2;
				double lastx;
				double lasty;
				lastx = displace_x;
				lasty = displace_y;
				suit_V = Player_deck[i][0];
				
				for(int z = 0; z < 10; z++){
					
						displace_x = lastx - dist_x;
						displace_y = lasty - dist_y;
						lastx = lastx - dist_x;
						
						if(Player_deck[10][0] == '0')
							lasty = lasty - dist_y;
						else if(Player_deck[10][0] == '1')
							lasty = lasty + dist_y;
					}
				blur = 0;
				card(suit_V,Face_value);
				
			}
		}
		
		//dealer first
		for(int i = 0;i < 10; i++){
			if (Dealer_deck[i][2]!=0) 
		    	{
				suit_V = Dealer_deck[i][0];
				Face_value = Dealer_deck[i][1];
				x1 = 540;
				y1 = -125;
				for(int j = 0; j < i;j++){
					x1 = x1 + 60;
					y1 = y1 + 10;
			
				}
				double dist_x = abs(x1 - x2)/10;
				double dist_y = abs(y1 - y2)/10;
				displace_x = x2;
				displace_y = y2;
				double lastx;
				double lasty;
				lastx = displace_x;
				lasty = displace_y;
				suit_V = Dealer_deck[i][0];
				
				for(int z= 0; z < 10; z++){
					
						displace_x = lastx - dist_x;
						displace_y = lasty - dist_y;
						lastx = lastx - dist_x;
						
						if(Dealer_deck[10][0] == '0')
							lasty = lasty - dist_y;
						else if(Dealer_deck[10][0] == '1')
							lasty = lasty + dist_y;
					}
				blur = 0;
				card(suit_V,Face_value);
				
			}
		}
	}
	else{
		// printing the cards before the last card
		int p;
		int d;
		for(int i = 0;i < 10; i++){
			if(Player_deck[i+1][2]==0 && dealing_deck[10][0] == '1')
			{
				p = i;
				break;
			}
			
			if (Player_deck[i][2]!=0) 
		    	{
				suit_V = Player_deck[i][0];
				Face_value = Player_deck[i][1];
				x1 = 540;
				y1 = 240;
				for(int j = 0; j < i;j++){
					x1 = x1 + 60;
					y1 = y1 + 10;
			
				}
				double dist_x = abs(x1 - x2)/10;
				double dist_y = abs(y1 - y2)/10;
				displace_x = x2;
				displace_y = y2;
				double lastx;
				double lasty;
				lastx = displace_x;
				lasty = displace_y;
				suit_V = Player_deck[i][0];
				
				for(int z = 0; z < 10; z++){
					
						displace_x = lastx - dist_x;
						displace_y = lasty - dist_y;
						lastx = lastx - dist_x;
						
						if(Player_deck[10][0] == '0')
							lasty = lasty - dist_y;
						else if(Player_deck[10][0] == '1')
							lasty = lasty + dist_y;
					}
				blur = 0;
				card(suit_V,Face_value);
				
			}
		}
		
		//dealer first
		for(int i = 0;i < 10; i++){
		
			if (Dealer_deck[i+1][2]==0 && dealing_deck[10][0] == '0') 
			{
				break;
			}
			
			if (Dealer_deck[i][2]!=0) 
		    	{
				suit_V = Dealer_deck[i][0];
				Face_value = Dealer_deck[i][1];
				x1 = 540;
				y1 = -125;
				for(int j = 0; j < i;j++){
					x1 = x1 + 60;
					y1 = y1 + 10;
			
				}
				double dist_x = abs(x1 - x2)/10;
				double dist_y = abs(y1 - y2)/10;
				displace_x = x2;
				displace_y = y2;
				double lastx;
				double lasty;
				lastx = displace_x;
				lasty = displace_y;
				suit_V = Dealer_deck[i][0];
				
				for(int z= 0; z < 10; z++){
					
						displace_x = lastx - dist_x;
						displace_y = lasty - dist_y;
						lastx = lastx - dist_x;
						
						if(Dealer_deck[10][0] == '0')
							lasty = lasty - dist_y;
						else if(Dealer_deck[10][0] == '1')
							lasty = lasty + dist_y;
					}
				blur = 0;
				card(suit_V,Face_value);
				
			}
			
		}
		}
		
		darken = 1;
}

void newgfx_color(int one, int two, int three)
{
	gfx_color(one*darken,two*darken,three*darken);
}



void card(char suit,char facevalue){
	scale = 1;
	newgfx_color(255,255,255);
	gfx_fillrectangle(48+displace_x,370+displace_y,100*scale,140*scale);
	
	char *test1 = "K";
	if (suit =='D' || suit =='H'){
		newgfx_color(198,0,0);
		}
	else{
		newgfx_color(0,0,0);
		}
	
	
	//SPADE
	if(blur == 0){
		suits(suit);
		//FOUR LINES 
		gfx_fillrectangle(50+displace_x,373+displace_y,3*scale,135*scale);
		gfx_fillrectangle(143+displace_x,373+displace_y,3*scale,135*scale);
		gfx_fillrectangle(50+displace_x,373+displace_y,95*scale,3*scale);
		gfx_fillrectangle(50+displace_x,505+displace_y,95*scale,3*scale);
		
		//FOUR RECTANGLES INSIDE
		gfx_fillrectangle(51+displace_x,375+displace_y,6*scale,6*scale);
		gfx_fillrectangle(51+displace_x,500+displace_y,6*scale,6*scale);
		gfx_fillrectangle(139+displace_x,375+displace_y,6*scale,6*scale);
		gfx_fillrectangle(139+displace_x,500+displace_y,6*scale,6*scale);

		//FOUR RECTANGLES OUTSIDE
		gfx_fillrectangle(47+displace_x,505+displace_y,5*scale,5*scale);
		gfx_fillrectangle(47+displace_x,370+displace_y,5*scale,5*scale);
		gfx_fillrectangle(144+displace_x,505+displace_y,5*scale,5*scale);
		gfx_fillrectangle(144+displace_x,370+displace_y,5*scale,5*scale);
	
		switch(facevalue)
		{
			case 'A':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			break;
			
			case '2':
			gfx_fillrectangle(60+displace_x,385+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(73+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,5*scale,15*scale);//|
			gfx_fillrectangle(60+displace_x,410+displace_y,18*scale,5*scale);//-
			break;
			
			case'3':
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case '4':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,23*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			break;
			
			case '5':
			gfx_fillrectangle(60+displace_x,382+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,382+displace_y,5*scale,8*scale);//|
			gfx_fillrectangle(60+displace_x,390+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,392+displace_y,5*scale,15*scale);//|
			gfx_fillrectangle(60+displace_x,407+displace_y,20*scale,5*scale);//-
			break;
			
			case '6':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,20*scale);//|
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case '7':
			gfx_fillrectangle(72+displace_x,385+displace_y,5*scale,22*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,17*scale,5*scale);//-
			break;
			
			case '8':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|			
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,10*scale);//|			
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-			
			gfx_fillrectangle(62+displace_x,395+displace_y,16*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,397+displace_y,5*scale,8*scale);//|
			gfx_fillrectangle(75+displace_x,397+displace_y,5*scale,8*scale);//|			
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case '9':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			break;
			
			case 'T':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(70+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(85+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(70+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(70+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case 'J':
			gfx_fillrectangle(60+displace_x,400+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(68+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(62+displace_x,385+displace_y,16*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,405+displace_y,10*scale,5*scale);//-
			break;
			
			case 'Q':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(70+displace_x,400+displace_y,5*scale,5*scale);//-
			gfx_fillrectangle(76+displace_x,406+displace_y,7*scale,7*scale);//-
			break;
			
			case 'K':
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(70+displace_x,397+displace_y,5*scale,13*scale);//|
			
			gfx_fillrectangle(60+displace_x,395+displace_y,15*scale,5*scale);//-
			
			gfx_fillrectangle(65+displace_x,390+displace_y,5*scale,5*scale);//|
			gfx_fillrectangle(68+displace_x,388+displace_y,5*scale,5*scale);//|
			gfx_fillrectangle(70+displace_x,385+displace_y,5*scale,5*scale);//|
			break;
			
			default:
			
			
			break;
		}
	}
		
	//gfx_text(test1,57+displace_x,380+displace_y,2);	
	//gfx_text(test1,127+displace_x,476+displace_y,2);
	
	
}


void Stand_Text(int y9)
{
	newgfx_color(0,0,0);//black
	int justmove = -15;
	gfx_fillrectangle(140*scale+ displace_x+justmove,130*scale + displace_y+y9,60*scale,10*scale);//-
	gfx_fillrectangle(140*scale+ displace_x+justmove,130*scale + displace_y+y9,10*scale,60*scale);//|
	gfx_fillrectangle(140*scale+ displace_x+justmove,190*scale + displace_y+y9,60*scale,10*scale);//-
	gfx_fillrectangle(190*scale+ displace_x+justmove,190*scale + displace_y+y9,10*scale,60*scale);//|
	gfx_fillrectangle(140*scale+ displace_x+justmove,250*scale + displace_y+y9,60*scale,10*scale);//-
	//s
	
	gfx_fillrectangle(210*scale+ displace_x+justmove,130*scale + displace_y+y9,80*scale,10*scale);//-
	gfx_fillrectangle(245*scale+ displace_x+justmove,130*scale + displace_y+y9,10*scale,130*scale);//|
	//T
	justmove = -35;
	gfx_fillrectangle(350*scale+ displace_x+justmove,130*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(340*scale+ displace_x+justmove,156*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(360*scale+ displace_x+justmove,156*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(330*scale+ displace_x+justmove,182*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(370*scale+ displace_x+justmove,182*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(320*scale+ displace_x+justmove,208*scale + displace_y+y9,10*scale,28*scale);//|
	gfx_fillrectangle(380*scale+ displace_x+justmove,208*scale + displace_y+y9,10*scale,28*scale);//|
	gfx_fillrectangle(320*scale+ displace_x+justmove,208*scale + displace_y+y9,60*scale,13*scale);//-
	gfx_fillrectangle(310*scale+ displace_x+justmove,234*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(390*scale+ displace_x+justmove,234*scale + displace_y+y9,10*scale,26*scale);//|
	//A
	
	gfx_fillrectangle(410*scale+ displace_x+justmove,130*scale + displace_y+y9,10*scale,130*scale);//|
	gfx_fillrectangle(420*scale+ displace_x+justmove,143*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(430*scale+ displace_x+justmove,165*scale + displace_y+y9,10*scale,14*scale);//|
	gfx_fillrectangle(440*scale+ displace_x+justmove,178*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(450*scale+ displace_x+justmove,204*scale + displace_y+y9,10*scale,14*scale);//|
	gfx_fillrectangle(460*scale+ displace_x+justmove,217*scale + displace_y+y9,10*scale,26*scale);//|
	gfx_fillrectangle(470*scale+ displace_x+justmove,130*scale + displace_y+y9,10*scale,130*scale);//|
	//N
	
	justmove = -30;
	gfx_fillrectangle(490*scale+ displace_x+justmove,130*scale + displace_y+y9,10*scale,130*scale);//|
	gfx_fillrectangle(490*scale+ displace_x+justmove,130*scale + displace_y+y9,40*scale,13*scale);//-
	gfx_fillrectangle(490*scale+ displace_x+justmove,250*scale + displace_y+y9,40*scale,13*scale);//-
	gfx_fillrectangle(530*scale+ displace_x+justmove,143*scale + displace_y+y9,10*scale,14*scale);//-
	gfx_fillrectangle(533*scale+ displace_x+justmove,233*scale + displace_y+y9,10*scale,16*scale);//-
	gfx_fillrectangle(539*scale+ displace_x+justmove,156*scale + displace_y+y9,10*scale,78*scale);//|
	//D
}


void PlayerTotal()
{
 	Total_Card_Value(Player_deck,player_total);
 	
 	
	if(countingvar %10 == 0  && countingvar >=1){	
 		display_values_1 = player_total[0];
 		display_values_2 = player_total[1];

 		}
  	
      	printf("\n\nTotal \t\t\t\t\t\tTotal \n");   	
      	
	if (display_values_1 == display_values_2){
		printf("%d        ",display_values_1); 
		remaining_cards(440,240,display_values_1);
		}
	else if(display_values_1 >21){
		printf("%d        ",display_values_2); 	
		remaining_cards(440,240,display_values_2);
		}
	else if(display_values_1 ==21){
		printf("%d        ",display_values_1); 
		remaining_cards(440,240,display_values_1);
		}
	else{
		printf("%d or %d   ",display_values_1,display_values_2);
		remaining_cards(440,240,display_values_1);
		//display an or here
		remaining_cards(440,300,display_values_2);
		}
	printf("\t\t\t\t\t");

}


void DealerTotal()
{
	Total_Card_Value(Dealer_deck,dealer_total);
	
	if(countingvar %10 == 0 && countingvar >=1){
 		display_values_3  = dealer_total[0];
 		display_values_4 = dealer_total[1];
 		countingvar = 0;
 		}

      
      if (display_values_3 == display_values_4){
		printf("%d\n",display_values_3);
		remaining_cards(440,-125,display_values_3);
		}
      else if(display_values_3 >21){
		printf("%d\n",display_values_3);
		remaining_cards(440,-125,display_values_3);
		}
      else if(display_values_3 ==21){
		printf("%d\n",display_values_3);
		remaining_cards(440,-125,display_values_3);
		}
      else{
		printf("%d or %d\n",display_values_3,display_values_4);     
		remaining_cards(440,-125,display_values_3);
		remaining_cards(440,-65,display_values_4);
		}

}

void remaining_cards(int x6,int y6,int sum)
{	
	int x = displace_x;
	int y = displace_y;
	displace_x = x6;
	displace_y = y6;
	int unit10;
	unit10 = sum/10;
	int unit1;
	unit1 = sum%10;
	newgfx_color(255,255,255);
	
	
	switch(unit10)
		{
			case 1: 
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			break;
			
			case 2:
			gfx_fillrectangle(60+displace_x,385+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(73+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,5*scale,15*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,18*scale,5*scale);//-
			break;
			
			case 3:
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case 4:
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			break;
			
			case 5:
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,15*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			

			
			
			
			
			
		}
		displace_x = x6 + 30;
		switch(unit1)
		{
			case 1: 
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			break;
			
			case 2:
			gfx_fillrectangle(60+displace_x,385+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(73+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,5*scale,15*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,18*scale,5*scale);//-
			break;
			
			case 3:
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case 4:
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			break;
			
			case 5:
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,15*scale);//|
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case 6:
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,20*scale);//|
			gfx_fillrectangle(75+displace_x,395+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,18*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case 7:
			gfx_fillrectangle(72+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,17*scale,5*scale);//-
			break;
			
			case 8:
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|			
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,10*scale);//|			
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-			
			gfx_fillrectangle(62+displace_x,395+displace_y,16*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,397+displace_y,5*scale,8*scale);//|
			gfx_fillrectangle(75+displace_x,397+displace_y,5*scale,8*scale);//|			
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
			case 9:
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,10*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,395+displace_y,20*scale,5*scale);//-
			break;
			
			
			case 0:
			gfx_fillrectangle(60+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(75+displace_x,385+displace_y,5*scale,25*scale);//|
			gfx_fillrectangle(60+displace_x,385+displace_y,20*scale,5*scale);//-
			gfx_fillrectangle(60+displace_x,405+displace_y,20*scale,5*scale);//-
			break;
			
		}
		displace_x = x;
		displace_y = y;
	
}


const char* display_hands_part2(char DS,char FV)
{ 
    char D_Suit[10] ={};
    char D_FV[10]={};
    char BIG_D[20]={};
    
    switch(FV){
          case 'A':
                  strcpy(D_FV,"Ace");
                          break;
          case '2':
                  strcpy(D_FV,"Two");
                          break;
          case '3':
                  strcpy(D_FV,"Three");
                          break;
          case '4':
                  strcpy(D_FV,"Four");
                          break;
          case '5':
                  strcpy(D_FV,"Five");
                          break;
          case '6':
                  strcpy(D_FV,"Six");
                          break;
          case '7':
                  strcpy(D_FV,"Seven");
                          break;
          case '8':
                  strcpy(D_FV,"Eight");
                          break;
          case '9':
                  strcpy(D_FV,"Nine");
                          break;
          case 'T':
                  strcpy(D_FV,"Ten");
                          break;
          case 'J':
                  strcpy(D_FV,"Jack");
                          break;
          case 'Q':
                  strcpy(D_FV,"Queen");
                          break;
          case 'K':
                  strcpy(D_FV,"King");
                          break;

    }
    strcat(BIG_D,D_FV);
    strcat(BIG_D," of ");
    
    switch(DS)
    {
          case 'H':
                  strcpy(D_Suit,"Hearts   ");
                  break;
          case 'D':
                  strcpy(D_Suit,"Diamonds ");
                  break;
          case 'C':
                  strcpy(D_Suit,"Clubs    ");
                  break;  
          case 'S':
                  strcpy(D_Suit,"Spades   ");
                  break;          
    }
    strcat(BIG_D,D_Suit);
    char* card = BIG_D;
    return card;
    
}



void display_hands()
{
    printf("\nPlayer's hand\t\t\t\t\tDealer's hand\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    char* cards;
    		
    for (a =0; a<=9; a++){
        if(Player_deck[a][1]!= 0){
                printf("%s\t\t",display_hands_part2(Player_deck[a][0],Player_deck[a][1]));
                }
        if(Dealer_deck[a][1] != 0 && Player_deck[a][1] == 0){
		printf("\t\t\t\t");
		}
	
        if(Dealer_deck[a][1] != 0){
                printf("\t\t%s\n",display_hands_part2(Dealer_deck[a][0],Dealer_deck[a][1]));
                }
        if(Dealer_deck[a][1] == 0 && Player_deck[a+1][1]!= 0){
                printf("\n");
                }
    }
}






void Total_Card_Value(char deck[hand][Characteristics],int *hand_total)
{
      int i,total = 0,total2=0,x;
      char term;
      int ace_count =0;
      for(i = 0; i < 10; i++)
      {
        term = deck[i][2];
        switch(term){
            case 'J':
            case 'Q':
            case 'K':
            case 'T':
                  total = total + 10;    
                  total2 = total2 + 10;
                  break;
            case '1':
                  ace_count++;
                  if(ace_count>1){
                        total = total + 1;
                        total2 = total2 + 1;
                        break;
                        }
                  else{
                        total = total + 11;
                        total2 = total2 + 1;
                        break;
                        }
            case 0:
                  total = total + 0;
                  total2 = total2 + 0;
                  break;
            default:
                  x = term - '0';
                  total = total + x;
                  total2 = total2 + x;
                  break;
        }

      }
      hand_total[0]= total;
      hand_total[1]= total2;
}


void JiePixel(double xp,double yp,double wide, double high){
	xp = (xp);
	yp = yp;
	wide = wide + 1;
	high = high + 1;
	gfx_fillrectangle(xp*scale+ displace_x, yp*scale + displace_y ,wide*scale ,high*scale );
}



void deckcard(){
	scale = 1;
	for(int i = 0; i < 52-deckcardnum; i+= 2){	
		displace_x +=0.2;
		displace_y -=5;
		gfx_color(225*darken,225*darken,225*darken);
		JiePixel(1048,550,180,120);
		
		
		
		
		//EMPAT LINES
		gfx_color(0*darken,0*darken,0*darken);
		JiePixel(1051,552,174,3);
		JiePixel(1051,552,3,115);
		JiePixel(1223,552,3,115);
		JiePixel(1051,665,174,3);
		if(deckcardnum >42){
			deckcardnum = 0;
			}

		}
		
		gfx_color(0,0,0);
		JiePixel(1063,569,150,3);
		JiePixel(1063,569,3,80);
		JiePixel(1210,569,3,80);
		JiePixel(1063,648,150,3);
		

		gfx_color(0,0,0);
		int x1 = 1137;
		int y1 = 553;
		for(float i = 0; i < 70;i+=2){	
			JiePixel( x1-i, y1+20, 2+i, 3);
			JiePixel( x1, y1+20, 2+i, 3);
			y1 +=1;
			}
		x1 = 1137;
		y1 = 623;
		for(float i = 70; i > 0;i-=2){	
			JiePixel( x1-i+1, y1-15, 2+i, 3);
			JiePixel( x1-1, y1-15, 2+i, 3);
			y1 +=1;
			}
}

void Play_Again_Text(int y11){
	newgfx_color(0,0,0);
	gfx_fillrectangle(140*scale+ displace_x, 130*scale + displace_y+y11, 10*scale, 130*scale);
	gfx_fillrectangle(140*scale+ displace_x, 130*scale + displace_y+y11, 70*scale, 10*scale);
	gfx_fillrectangle(140*scale+ displace_x, 190*scale + displace_y+y11, 70*scale, 10*scale);
	gfx_fillrectangle(210*scale+ displace_x, 140*scale + displace_y+y11, 10*scale, 50*scale);
	//P
	
	gfx_fillrectangle(240*scale +displace_x, 130*scale + displace_y+y11, 10*scale, 130*scale);
	gfx_fillrectangle(240*scale +displace_x, 250*scale + displace_y+y11, 70*scale, 10*scale);
	//L
	
	gfx_fillrectangle(360*scale+ displace_x,130*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(350*scale+ displace_x,156*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(370*scale+ displace_x,156*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(340*scale+ displace_x,182*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(380*scale+ displace_x,182*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(330*scale+ displace_x,208*scale + displace_y+y11,10*scale,28*scale);//|
	gfx_fillrectangle(390*scale+ displace_x,208*scale + displace_y+y11,10*scale,28*scale);//|
	gfx_fillrectangle(330*scale+ displace_x,208*scale + displace_y+y11,60*scale,13*scale);//-
	gfx_fillrectangle(320*scale+ displace_x,234*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(400*scale+ displace_x,234*scale + displace_y+y11,10*scale,26*scale);//|
	//A
	
	gfx_fillrectangle(435*scale+ displace_x,130*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(445*scale+ displace_x,156*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(495*scale+ displace_x,130*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(485*scale+ displace_x,156*scale + displace_y+y11,10*scale,26*scale);//|
	gfx_fillrectangle(475*scale+ displace_x,182*scale + displace_y+y11,10*scale,16*scale);//|
	gfx_fillrectangle(455*scale+ displace_x,182*scale + displace_y+y11,10*scale,16*scale);//|
	gfx_fillrectangle(465*scale+ displace_x,196*scale + displace_y+y11,10*scale,63*scale);//|
	//Y
}
void Exit_Text(int y10){

	newgfx_color(0,0,0);//black
	gfx_fillrectangle(140*scale+ displace_x,130*scale + displace_y+y10,10*scale,100*scale);
	gfx_fillrectangle(140*scale+ displace_x,130*scale + displace_y+y10,70*scale,10*scale);
	gfx_fillrectangle(140*scale+ displace_x,170*scale + displace_y+y10,70*scale,10*scale);
	gfx_fillrectangle(140*scale+ displace_x,220*scale + displace_y+y10,70*scale,10*scale);
	
	//E
	float y1 = 130;
	for(int i = 0; i < 70;i++){
		for(int j = 65; j > 0; j--){
			JiePixel(230+i,y1, 12,2);
			JiePixel(295-i,y1,12,2);
			}
		y1= y1 + 1.401;
		}

			
	gfx_fillrectangle(320*scale+ displace_x,130*scale + displace_y+y10,70*scale,10*scale);
	gfx_fillrectangle(350*scale+ displace_x,130*scale + displace_y+y10,10*scale,100*scale);
	gfx_fillrectangle(320*scale+ displace_x,220*scale + displace_y+y10,70*scale,10*scale);
	//I
	

	gfx_fillrectangle(410*scale+ displace_x,130*scale + displace_y+y10,70*scale,10*scale);
	gfx_fillrectangle(440*scale+ displace_x,130*scale + displace_y+y10,10*scale,105*scale);
	//T
}


void dealer_arm_1st()
{
	//animated arm
		newgfx_color(255,255,255);//white
		Pixel(48,20,3,11);//G1
		Pixel(44,24,4,15);	
		Pixel(40,28,3,27);//g2
		Pixel(36,32,4,19);
		Pixel(32,40,4,7);//g3
		Pixel(44,44,4,19);
		Pixel(48,48,4,11);//g4
		Pixel(52,56,4,3);		
		
		newgfx_color(238,206,180);//skin
		Pixel(48,60,11,11);
		

}

void dealer_arm_2nd()
{
		newgfx_color(255,255,255);//white
		Pixel(48,20,3,51);//G1
		Pixel(44,24,4,51);
		Pixel(40,36,4,31);//G2
		Pixel(51,64,3,7);
		newgfx_color(238,206,180);//skin
		Pixel(48,72,11,11);
		
		//cards
		newgfx_color(255,255,255);//white
		Pixel(52,84,21,11);
}

void dealer_arm_3rd()
{
	newgfx_color(238,206,180);//skin
		Pixel(44,71,10,15);
		
		newgfx_color(255,255,255);//white
		Pixel(48,20,3,55);//G1
		Pixel(44,24,4,55);
		Pixel(40,36,4,31);//G2
		Pixel(51,64,3,7);
		
		//cards
		newgfx_color(255,255,255);//white
		Pixel(52,84,21,11);
}

void dealer_arm_4th()
{
	//animated fourth frame
		newgfx_color(238,206,180);//skin
		Pixel(36,72,11,11);
		
		newgfx_color(255,255,255);//white
		Pixel(48,20,3,55);//G1
		Pixel(44,24,4,51);
		Pixel(40,36,3,39);
		
		//cards
		newgfx_color(255,255,255);//white
		Pixel(40,100,11,15);
}

/*void dealer_body()
{
	newgfx_color(238,206,180);//skin
	Pixel(60,1,19,15);
	Pixel(64,16,11,4);


	//unmoving arm
	Pixel(77,60,11,11);



	newgfx_color(0,0,0);//black
	Pixel(52,20,35,24);
	Pixel(56,44,27,11);

	newgfx_color(255,255,255);//white
	Pixel(64,20,11,7);
	Pixel(68,28,3,3);
	//unmoving arm
	Pixel(88,20,4,11);
	Pixel(92,24,3,43);
	Pixel(95,28,3,35);
	Pixel(99,36,3,19);
	Pixel(89,56,3,11);
	Pixel(84,56,4,3);
	
	newgfx_color(128,128,128);//grey buttons
	Pixel(68,36,3,3);
	Pixel(68,44,3,3);
	
	//cards
	newgfx_color(255,255,255);//white
	Pixel(56,64,21,11);
	gfx_flush();
}


void dealer()
{

	dealer_body();
	dealer_arm_1st();
	
	usleep(16700);
	gfx_clear();
}
*/






