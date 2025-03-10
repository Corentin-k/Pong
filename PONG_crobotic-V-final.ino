
#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define I2C_SLAVE1_ADDRESS 11
#define PAYLOAD_SIZE 2
#define NUMPIXELS 400
#define PIN        6
#define joy1Y A0
#define joy2Y A2
#define joy1B 4
#define joy2B 5
#define a  40
#define b  41
#define c  42
#define d  43
#define e  44
#define f  45
#define g  46
#define h  47
#define d1 48
#define d2 49
#define d3 51
#define d4 50
#define v5  12
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

struct LEDStatus {
  int number;
  int red;
  int green;
  int blue;
};
long int lastdelay = millis();
int maxScore = 10;
int logo[20][20] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int matrice_celebration[20][20]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2},
{3,0,4,4,4,4,0,0,0,3,2,0,0,0,0,0,0,0,0,2},
{3,0,4,0,0,4,4,0,0,3,2,1,1,0,0,0,0,1,1,2},
{3,0,4,0,0,0,4,4,0,3,2,0,1,1,0,0,1,1,0,2},
{3,0,4,0,0,0,4,4,0,3,2,0,0,1,1,1,1,0,0,2},
{3,0,4,0,0,4,4,0,0,3,2,0,0,0,1,1,0,0,0,2},
{3,0,4,4,4,4,0,0,0,3,2,0,0,0,0,0,0,0,0,2},
{3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


int matrice_celebration2[20][20]={
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2},
{3,0,0,0,0,0,0,0,0,3,2,0,4,4,4,4,0,0,0,2},
{3,1,1,0,0,0,0,1,1,3,2,0,4,0,0,4,4,0,0,2},
{3,0,1,1,0,0,1,1,0,3,2,0,4,0,0,0,4,4,0,2},
{3,0,0,1,1,1,1,0,0,3,2,0,4,0,0,0,4,4,0,2},
{3,0,0,0,1,1,0,0,0,3,2,0,4,0,0,4,4,0,0,2},
{3,0,0,0,0,0,0,0,0,3,2,0,4,4,4,4,0,0,0,2},
{3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


LEDStatus leds_tab[20][20] = {
  {
    {399, 0, 0, 0}, {398, 0, 0, 0}, {397, 0, 0, 0}, {396, 0, 0, 0}, {395, 0, 0, 0}, {394, 0, 0, 0}, {393, 0, 0, 0}, {392, 0, 0, 0}, {391, 0, 0, 0}, {390, 0, 0, 0}, 
    {389, 0, 0, 0}, {388, 0, 0, 0}, {387, 0, 0, 0}, {386, 0, 0, 0}, {385, 0, 0, 0}, {384, 0, 0, 0}, {383, 0, 0, 0}, {382, 0, 0, 0}, {381, 0, 0, 0}, {380, 0, 0, 0}
  },{
    {360, 0, 0, 0}, {361, 0, 0, 0}, {362, 0, 0, 0}, {363, 0, 0, 0}, {364, 0, 0, 0}, {365, 0, 0, 0}, {366, 0, 0, 0}, {367, 0, 0, 0}, {368, 0, 0, 0}, {369, 0, 0, 0},
    {370, 0, 0, 0}, {371, 0, 0, 0}, {372, 0, 0, 0}, {373, 0, 0, 0}, {374, 0, 0, 0}, {375, 0, 0, 0}, {376, 0, 0, 0}, {377, 0, 0, 0}, {378, 0, 0, 0}, {379, 0, 0, 0}
  },{
    {359, 0, 0, 0}, {358, 0, 0, 0}, {357, 0, 0, 0}, {356, 0, 0, 0}, {355, 0, 0, 0},{354, 0, 0, 0},{353, 0, 0, 0}, {352, 0, 0, 0}, {351, 0, 0, 0}, {350, 0, 0, 0}, 
    {349, 0, 0, 0}, {348, 0, 0, 0}, {347, 0, 0, 0}, {346, 0, 0, 0}, {345, 0, 0, 0}, {344, 0, 0, 0}, {343, 0, 0, 0}, {342, 0, 0, 0}, {341, 0, 0, 0}, {340, 0, 0, 0}
  },{
    {320, 0, 0, 0}, {321, 0, 0, 0}, {322, 0, 0, 0}, {323, 0, 0, 0}, {324, 0, 0, 0},{325, 0, 0, 0},{326, 0, 0, 0}, {327, 0, 0, 0}, {328, 0, 0, 0}, {329, 0, 0, 0},
    {330, 0, 0, 0}, {331, 0, 0, 0}, {332, 0, 0, 0}, {333, 0, 0, 0}, {334, 0, 0, 0}, {335, 0, 0, 0}, {336, 0, 0, 0}, {337, 0, 0, 0}, {338, 0, 0, 0}, {339, 0, 0, 0}
  },{
    {319, 0, 0, 0}, {318, 0, 0, 0}, {317, 0, 0, 0}, {316, 0, 0, 0}, {315, 0, 0, 0},{314, 0, 0, 0},{313, 0, 0, 0}, {312, 0, 0, 0}, {311, 0, 0, 0}, {310, 0, 0, 0}, 
    {309, 0, 0, 0}, {308, 0, 0, 0}, {307, 0, 0, 0}, {306, 0, 0, 0}, {305, 0, 0, 0}, {304, 0, 0, 0}, {303, 0, 0, 0}, {302, 0, 0, 0}, {301, 0, 0, 0}, {300, 0, 0, 0}
  },{
    {280, 0, 0, 0}, {281, 0, 0, 0}, {282, 0, 0, 0}, {283, 0, 0, 0}, {284, 0, 0, 0},{285, 0, 0, 0},{286, 0, 0, 0}, {287, 0, 0, 0}, {288, 0, 0, 0}, {289, 0, 0, 0}, 
    {290, 0, 0, 0}, {291, 0, 0, 0}, {292, 0, 0, 0}, {293, 0, 0, 0}, {294, 0, 0, 0}, {295, 0, 0, 0}, {296, 0, 0, 0}, {297, 0, 0, 0}, {298, 0, 0, 0}, {299, 0, 0, 0}
  },{
    {279, 0, 0, 0}, {278, 0, 0, 0}, {277, 0, 0, 0}, {276, 0, 0, 0}, {275, 0, 0, 0},{274, 0, 0, 0},{273, 0, 0, 0}, {272, 0, 0, 0}, {271, 0, 0, 0}, {270, 0, 0, 0}, 
    {269, 0, 0, 0}, {268, 0, 0, 0}, {267, 0, 0, 0}, {266, 0, 0, 0}, {265, 0, 0, 0}, {264, 0, 0, 0}, {263, 0, 0, 0}, {262, 0, 0, 0}, {261, 0, 0, 0}, {260, 0, 0, 0}
  },{
    {240, 0, 0, 0}, {241, 0, 0, 0}, {242, 0, 0, 0}, {243, 0, 0, 0}, {244, 0, 0, 0},{245, 0, 0, 0},{246, 0, 0, 0}, {247, 0, 0, 0}, {248, 0, 0, 0}, {249, 0, 0, 0}, 
    {250, 0, 0, 0}, {251, 0, 0, 0}, {252, 0, 0, 0}, {253, 0, 0, 0}, {254, 0, 0, 0}, {255, 0, 0, 0}, {256, 0, 0, 0}, {257, 0, 0, 0}, {258, 0, 0, 0}, {259, 0, 0, 0}
  },{
    {239, 0, 0, 0}, {238, 0, 0, 0}, {237, 0, 0, 0}, {236, 0, 0, 0}, {235, 0, 0, 0},{234, 0, 0, 0},{233, 0, 0, 0}, {232, 0, 0, 0}, {231, 0, 0, 0}, {230, 0, 0, 0}, 
    {229, 0, 0, 0}, {228, 0, 0, 0}, {227, 0, 0, 0}, {226, 0, 0, 0}, {225, 0, 0, 0}, {224, 0, 0, 0}, {223, 0, 0, 0}, {222, 0, 0, 0}, {221, 0, 0, 0}, {220, 0, 0, 0}
  },{
    {200, 0, 0, 0}, {201, 0, 0, 0}, {202, 0, 0, 0}, {203, 0, 0, 0}, {204, 0, 0, 0},{205, 0, 0, 0},{206, 0, 0, 0}, {207, 0, 0, 0}, {208, 0, 0, 0}, {209, 0, 0, 0}, 
    {210, 0, 0, 0}, {211, 0, 0, 0}, {212, 0, 0, 0}, {213, 0, 0, 0}, {214, 0, 0, 0}, {215, 0, 0, 0}, {216, 0, 0, 0}, {217, 0, 0, 0}, {218, 0, 0, 0}, {219, 0, 0, 0}
  },{
    {199, 0, 0, 0}, {198, 0, 0, 0}, {197, 0, 0, 0}, {196, 0, 0, 0}, {195, 0, 0, 0},{194, 0, 0, 0},{193, 0, 0, 0}, {192, 0, 0, 0}, {191, 0, 0, 0}, {190, 0, 0, 0}, 
    {189, 0, 0, 0}, {188, 0, 0, 0}, {187, 0, 0, 0}, {186, 0, 0, 0}, {185, 0, 0, 0}, {184, 0, 0, 0}, {183, 0, 0, 0}, {182, 0, 0, 0}, {181, 0, 0, 0}, {180, 0, 0, 0}
  },{
    {160, 0, 0, 0}, {161, 0, 0, 0}, {162, 0, 0, 0}, {163, 0, 0, 0}, {164, 0, 0, 0},{165, 0, 0, 0},{166, 0, 0, 0}, {167, 0, 0, 0}, {168, 0, 0, 0}, {169, 0, 0, 0}, 
    {170, 0, 0, 0}, {171, 0, 0, 0}, {172, 0, 0, 0}, {173, 0, 0, 0}, {174, 0, 0, 0}, {175, 0, 0, 0}, {176, 0, 0, 0}, {177, 0, 0, 0}, {178, 0, 0, 0}, {179, 0, 0, 0}
  },{
    {159, 0, 0, 0}, {158, 0, 0, 0}, {157, 0, 0, 0}, {156, 0, 0, 0}, {155, 0, 0, 0},{154, 0, 0, 0},{153, 0, 0, 0}, {152, 0, 0, 0}, {151, 0, 0, 0}, {150, 0, 0, 0}, 
    {149, 0, 0, 0}, {148, 0, 0, 0}, {147, 0, 0, 0}, {146, 0, 0, 0}, {145, 0, 0, 0}, {144, 0, 0, 0}, {143, 0, 0, 0}, {142, 0, 0, 0}, {141, 0, 0, 0}, {140, 0, 0, 0}
  },{
    {120, 0, 0, 0}, {121, 0, 0, 0}, {122, 0, 0, 0}, {123, 0, 0, 0}, {124, 0, 0, 0},{125, 0, 0, 0},{126, 0, 0, 0}, {127, 0, 0, 0}, {128, 0, 0, 0}, {129, 0, 0, 0}, 
    {130, 0, 0, 0}, {131, 0, 0, 0}, {132, 0, 0, 0}, {133, 0, 0, 0}, {134, 0, 0, 0}, {135, 0, 0, 0}, {136, 0, 0, 0}, {137, 0, 0, 0}, {138, 0, 0, 0}, {139, 0, 0, 0}
  },{
    {119, 0, 0, 0}, {118, 0, 0, 0}, {117, 0, 0, 0}, {116, 0, 0, 0}, {115, 0, 0, 0},{114, 0, 0, 0},{113, 0, 0, 0}, {112, 0, 0, 0}, {111, 0, 0, 0}, {110, 0, 0, 0}, 
    {109, 0, 0, 0}, {108, 0, 0, 0}, {107, 0, 0, 0}, {106, 0, 0, 0}, {105, 0, 0, 0}, {104, 0, 0, 0}, {103, 0, 0, 0}, {102, 0, 0, 0}, {101, 0, 0, 0}, {100, 0, 0, 0}
  },{
    {80, 0, 0, 0}, {81, 0, 0, 0}, {82, 0, 0, 0}, {83, 0, 0, 0}, {84, 0, 0, 0},{85, 0, 0, 0},{86, 0, 0, 0}, {87, 0, 0, 0}, {88, 0, 0, 0}, {89, 0, 0, 0}, {90, 0, 0, 0}, 
    {91, 0, 0, 0}, {92, 0, 0, 0}, {93, 0, 0, 0}, {94, 0, 0, 0}, {95, 0, 0, 0}, {96, 0, 0, 0}, {97, 0, 0, 0}, {98, 0, 0, 0}, {99, 0, 0, 0}
  },{
    {79, 0, 0, 0}, {78, 0, 0, 0}, {77, 0, 0, 0}, {76, 0, 0, 0}, {75, 0, 0, 0},{74, 0, 0, 0},{73, 0, 0, 0}, {72, 0, 0, 0}, {71, 0, 0, 0}, {70, 0, 0, 0}, {69, 0, 0, 0}, 
    {68, 0, 0, 0}, {67, 0, 0, 0}, {66, 0, 0, 0}, {65, 0, 0, 0}, {64, 0, 0, 0}, {63, 0, 0, 0}, {62, 0, 0, 0}, {61, 0, 0, 0}, {60, 0, 0, 0}
  },{
    {40, 0, 0, 0}, {41, 0, 0, 0}, {42, 0, 0, 0}, {43, 0, 0, 0}, {44, 0, 0, 0},{45, 0, 0, 0},{46, 0, 0, 0}, {47, 0, 0, 0}, {48, 0, 0, 0}, {49, 0, 0, 0}, {50, 0, 0, 0}, 
    {51, 0, 0, 0}, {52, 0, 0, 0}, {53, 0, 0, 0}, {54, 0, 0, 0}, {55, 0, 0, 0}, {56, 0, 0, 0}, {57, 0, 0, 0}, {58, 0, 0, 0}, {59, 0, 0, 0}
  },{
    {39, 0, 0, 0}, {38, 0, 0, 0}, {37, 0, 0, 0}, {36, 0, 0, 0}, {35, 0, 0, 0},{34, 0, 0, 0},{33, 0, 0, 0}, {32, 0, 0, 0}, {31, 0, 0, 0}, {30, 0, 0, 0}, {29, 0, 0, 0}, 
    {28, 0, 0, 0}, {27, 0, 0, 0}, {26, 0, 0, 0}, {25, 0, 0, 0}, {24, 0, 0, 0}, {23, 0, 0, 0}, {22, 0, 0, 0}, {21, 0, 0, 0}, {20, 0, 0, 0}
  },{
    {0, 0, 0, 0}, {1, 0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0},{5, 0, 0, 0},{6, 0, 0, 0}, {7, 0, 0, 0}, {8, 0, 0, 0}, {9, 0, 0, 0}, {10, 0, 0, 0}, {11, 0, 0, 0}, 
    {12, 0, 0, 0}, {13, 0, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}, {16, 0, 0, 0}, {17, 0, 0, 0}, {18, 0, 0, 0}, {19, 0, 0, 0}} 
};
int ballMoveX = 0, ballMoveY = 0, ballPosY = 0, ballPosX = 0;
int scorePlayer1 = 0, scorePlayer2 = 0;
int boardFirstPlayer[5] = {7, 8, 9, 10, 11}, boardSecondPlayer[5] = {7, 8, 9, 10, 11};
void sendafficheurs (int score1, int score2){
  Wire.beginTransmission(I2C_SLAVE1_ADDRESS);
     Wire.write(score1);
     Wire.write(score2);
     Wire.endTransmission();
}
void moveBall() {
  // Eteint l'ancienne balle
  leds_tab[ballPosY][ballPosX].red = 0;

  // Déplace la balle
  ballPosY += ballMoveY;
  ballPosX += ballMoveX;

  // Regarde les collisions avec les murs des joueurs
 
  if(ballPosX == 1) checkLeftSide2();
  else if (ballPosX == 18) checkRightSide2();
  else if(ballPosX == 0) checkLeftSide();
  else if (ballPosX == 19) checkRightSide();
  // Regarde les collisions avec les murs du jeu
  if(ballPosY <= 0 || ballPosY >= 19) ballMoveY *= -1;

  // Allume la nouvelle balle
  leds_tab[ballPosY][ballPosX].red = 200;
}

// Prend la board d'un des joueurs, le nombre où la balle a tapé, et renvoie l'index où la balle a tapé ou -1 si la balle n'a pas tapé dans la planche
int getIndexOf(int tab[5], int search) {
  if(search < tab[0] || search > tab[4]) return -1;
  return search - tab[0];
}

void checkLeftSide() {
  int index = getIndexOf(boardFirstPlayer, ballPosY);
  if(index != -1) {
      ballMoveX = 1;
      switch(index) {
        case 0:
          ballMoveY = -2; 
          break;

        case 1:
          ballMoveY = -1;
          break;

        case 2:
          ballMoveY = 0; 
          break;
  
        case 3:
          ballMoveY = 1;
          break;

        case 4:
          ballMoveY = 2;
          break;
            
        default: break;
      }
  } else {
    leds_tab[ballPosY][ballPosX].red = 200;
    syncArrayAndLed();
    updateScore(2);
  }
}

void checkRightSide() {
  int index = getIndexOf(boardSecondPlayer, ballPosY);
  if(index != -1) {
      ballMoveX = -1;
      switch(index) {
        case 0:
          ballMoveY = -2; 
          break;

        case 1:
          ballMoveY = -1;
          break;

        case 2:
          ballMoveY = 0; 
          break;
  
        case 3:
          ballMoveY = 1;
          break;

        case 4:
          ballMoveY = 2;
          break;
            
        default: break;
      }
  } else {
    leds_tab[ballPosY][ballPosX].red = 200;
    syncArrayAndLed();
    updateScore(1);
  }
}
void checkLeftSide2() {
  int ballPosY2 =ballPosY+ballMoveY;
  int ballPosX2 =ballMoveX+ballMoveX;
  int index = getIndexOf(boardFirstPlayer, ballPosY);
  if(index != -1) {
      ballMoveX = 1;
      switch(index) {
        case 0:
          ballMoveY = -2; 
          break;

        case 1:
          ballMoveY = -1;
          break;

        case 2:
          ballMoveY = 0; 
          break;
  
        case 3:
          ballMoveY = 1;
          break;

        case 4:
          ballMoveY = 2;
          break;
            
        default: break;
      }
  } 
}

void checkRightSide2() {
  int ballPosY2 =ballPosY+ballMoveY;
  int ballPosX2 =ballMoveX+ballMoveX;
  int index = getIndexOf(boardSecondPlayer, ballPosY2);
  if(index != -1) {
      ballMoveX = -1;
      switch(index) {
        case 0:
          ballMoveY = -2; 
          break;

        case 1:
          ballMoveY = -1;
          break;

        case 2:
          ballMoveY = 0; 
          break;
  
        case 3:
          ballMoveY = 1;
          break;

        case 4:
          ballMoveY = 2;
          break;
            
        default: break;
      }
  } 
}
void makeCelebration(int ledRow) {
  if (ledRow != 0){
  for (int i=0; i<20; i++){
    for (int j=0; j<20; j++){
      if (matrice_celebration[i][j]==0){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 0;
        leds_tab[i][j].blue = 0;
      }else if(matrice_celebration[i][j]==1){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 150;
        leds_tab[i][j].blue = 0;
      }else if(matrice_celebration[i][j]==2){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 50;
        leds_tab[i][j].blue = 150;
      }else if(matrice_celebration[i][j]==3){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 50;
        leds_tab[i][j].blue = 150;
      }else if(matrice_celebration[i][j]==4){
        leds_tab[i][j].red = 150;
        leds_tab[i][j].green = 0;
        leds_tab[i][j].blue = 0;
      }
    }
  }
  }else{
    for (int i=0; i<20; i++){
    for (int j=0; j<20; j++){
      if (matrice_celebration2[i][j]==0){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 0;
        leds_tab[i][j].blue = 0;
      }else if(matrice_celebration2[i][j]==1){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 150;
        leds_tab[i][j].blue = 0;
      }else if(matrice_celebration2[i][j]==2){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 50;
        leds_tab[i][j].blue = 150;
      }else if(matrice_celebration2[i][j]==3){
        leds_tab[i][j].red = 0;
        leds_tab[i][j].green = 50;
        leds_tab[i][j].blue = 150;
      }else if(matrice_celebration2[i][j]==4){
        leds_tab[i][j].red = 150;
        leds_tab[i][j].green = 0;
        leds_tab[i][j].blue = 0;
      }
    }
   }
  }
  syncArrayAndLed();
  while(digitalRead(joy1B)!=LOW && digitalRead(joy2B)!=LOW){}
  delay(500);
  printlogo();
}

void updateScore(int playerId) {
  
  // Ajoute 1 au score du joueur
  if(playerId == 1){
    scorePlayer1 += 1;
    resetPos(-1);  
  }else{
    scorePlayer2 += 1;
    resetPos(1);
  }
  sendafficheurs(scorePlayer1,scorePlayer2);

  
  // Si pas de victoire, return
  if(scorePlayer1 != maxScore && scorePlayer2 != maxScore) {
    if(playerId != 1){
       while(digitalRead(joy2B)!=LOW){}
       syncArrayAndLed();
       delay(500);
       while(digitalRead(joy2B)!=LOW){}
    }else{
      while(digitalRead(joy1B)!=LOW){}
      syncArrayAndLed();
      delay(500);
      while(digitalRead(joy1B)!=LOW){}
    }
    return;
  }

  // Célébration pour le joueur ayant gagné
  if(scorePlayer1 == maxScore) makeCelebration(0);
  else makeCelebration(19);
  
  resetGame(); // Reset
  
  // Show LEDs
  syncArrayAndLed();
  delay(700);
  while(digitalRead(joy1B)!=LOW && digitalRead(joy2B)!=LOW){}
}

int readPlayer(int playerId) {
  int value = 0;
  if(playerId == 1) value = analogRead(joy1Y);
  else value = analogRead(joy2Y);

  if(value < 400) return -1;
  else if(value > 600) return 1;
  else return 0;
}

void syncBoardAndLeds(int ledRow, int board[5]) {
  // Eteint toutes les anciennes positions de LEDs
  for(int i = 0; i < 20; i++) leds_tab[i][ledRow].blue = 0;

  // Allume la nouvelle planche
  for(int i = 0; i < 5; i++) {
    leds_tab[board[i]][ledRow].blue = 255;
  }
}

void moveFirstPlayer() {
  int move = readPlayer(1);

  if(move == 0) return;
  if(move < 0) {
    if(boardFirstPlayer[0] == 0) return; // Si la planche est au plus haut
    for(int i = 4; i >= 0; i--) boardFirstPlayer[i] --; 
  } else {
    if(boardFirstPlayer[4] == 19) return; // Si la planche est au plus bas 
    for(int i = 4; i >= 0; i--) boardFirstPlayer[i] ++; 
  }
  syncBoardAndLeds(0, boardFirstPlayer);
}

void moveSecondPlayer() {
  int move = readPlayer(2);

  if(move == 0) return; // Si le joueur ne bouge pas sa planche
  if(move < 0) { // Si le joueur déplace sa planche en haut
    if(boardSecondPlayer[0] == 0) return; // Si la planche est au plus bas 
    for(int i = 4; i >= 0; i--) boardSecondPlayer[i] --; 
  } else { // Si le joueur déplace sa planche vers le bas
    if(boardSecondPlayer[4] == 19) return; // Si la planche est au plus bas 
    for(int i = 4; i >= 0; i--) boardSecondPlayer[i] ++; 
  }
  syncBoardAndLeds(19, boardSecondPlayer);
}

void resetGame() {
  scorePlayer1 = 0;
  scorePlayer2 = 0;
  sendafficheurs(scorePlayer1,scorePlayer2);
  resetPos(1);
}

void resetPos(int sens) {
  // Reset de la grille
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      leds_tab[i][j].red = 0;
      leds_tab[i][j].green = 0;
      leds_tab[i][j].blue = 0;
    }
  }

  // Gestion de la balle
  leds_tab[9][9].red = 200;
  ballPosY = 9; 
  ballPosX = 9;
  ballMoveX = sens; 
  ballMoveY = 0;

  // Reset des planches des joueurs
  for(int i = 0; i < 5; i++) {
    boardFirstPlayer[i] = 7 + i;
    boardSecondPlayer[i] = 7 + i;
  }

  // Pixel de la planche du premier joueur
  leds_tab[7][0].blue = 255;
  leds_tab[8][0].blue = 255;
  leds_tab[9][0].blue = 255;
  leds_tab[10][0].blue = 255;
  leds_tab[11][0].blue = 255;

  // Pixel de la planche du second joueur
  leds_tab[7][19].blue = 255;
  leds_tab[8][19].blue = 255;
  leds_tab[9][19].blue = 255;
  leds_tab[10][19].blue = 255;
  leds_tab[11][19].blue = 255;
}

void syncArrayAndLed() {
  pixels.clear();
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < 20; j++) {
      if(leds_tab[i][j].red != 0 || leds_tab[i][j].green != 0 || leds_tab[i][j].blue != 0) {
        pixels.setPixelColor(leds_tab[i][j].number, pixels.Color( leds_tab[i][j].green,leds_tab[i][j].red, leds_tab[i][j].blue));
      }
    }
  }
  pixels.show();
}
void printlogo(){
  delay(500);
  for (int i=0; i<20; i++){
    for (int j=0; j<20; j++){
      if (logo[i][j]==1){
        leds_tab[i][j].red=150;
        leds_tab[i][j].green=10;
        leds_tab[i][j].blue=0;
      }else{
        leds_tab[i][j].red=0;
        leds_tab[i][j].blue=0;
        leds_tab[i][j].green=0;
      }
    }
  }
  syncArrayAndLed();
  while(digitalRead(joy1B)!=LOW && digitalRead(joy2B)!=LOW){
    int poten = readPlayer(1);
    if (poten == 1 && maxScore>1){
      maxScore--;
    }else if (poten == -1){
      maxScore++;
    }
    sendafficheurs(maxScore,0);
    delay(150);
  }
  while(digitalRead(joy1B)==LOW || digitalRead(joy2B)==LOW){}
}
void setup() {
  Wire.begin();
  Serial.begin(9600);
  pinMode(joy1B, INPUT_PULLUP);
  pinMode(joy2B, INPUT_PULLUP);
  pixels.begin();
  pixels.clear();
  printlogo();
  pixels.clear();
  resetPos(1);
  pixels.show();
  pinMode(v5, OUTPUT);
  digitalWrite(v5, HIGH);
  sendafficheurs(0,0);
  resetGame(); // Reset
  moveBall();
  moveFirstPlayer();
  moveSecondPlayer();
  // Show LEDs
  syncArrayAndLed();
  while(digitalRead(joy1B)!=LOW && digitalRead(joy2B)!=LOW){}
}

void loop() {
  if (millis()-lastdelay>30){
    lastdelay = millis();
  
    moveBall();
    moveFirstPlayer();
    moveSecondPlayer();
    syncArrayAndLed();
  }

}

