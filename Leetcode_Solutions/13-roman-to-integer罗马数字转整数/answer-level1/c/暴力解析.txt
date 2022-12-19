#define  ROMAN_M  0
#define  ROMAN_D  1
#define  ROMAN_C  2
#define  ROMAN_L  3
#define  ROMAN_X  4
#define  ROMAN_V  5
#define  ROMAN_I  6

#define  ROMAN_CM  0
#define  ROMAN_CD  1
#define  ROMAN_XL  2
#define  ROMAN_XC  3
#define  ROMAN_IV  4
#define  ROMAN_IX  5

void CheckState(char* s, int* flag, int* vis) {
    int len = strlen(s);
    int index = 0;

    while (index < len) {
        switch (s[index]) {
            case 'M':
                vis[ROMAN_M] = 1;
                if (vis[ROMAN_C] == 1) {
                    flag[ROMAN_CM] = 1; // C->M
                }
                break;
            case 'D':
                vis[ROMAN_D] = 1;
                if (vis[ROMAN_C] == 1) {
                    flag[ROMAN_CD] = 1; // C->D
                }
                break;
            case 'C':
                vis[ROMAN_C] = 1;
                if (vis[ROMAN_X] == 1) {
                    flag[ROMAN_XC] = 1; // X->C
                }
                break;
            case 'L':
                vis[ROMAN_L] = 1;
                if (vis[ROMAN_X] == 1) {
                    flag[ROMAN_XL] = 1; // X->L
                }
                break;
            case 'X':
                vis[ROMAN_X] = 1;
                if (vis[ROMAN_I] == 1) {
                    flag[ROMAN_IV] = 1; // I->V
                }
                break;
            case 'V':
                vis[ROMAN_V] = 1;
                if (vis[ROMAN_I] == 1) {
                    flag[ROMAN_IX] = 1; // I->X
                }
                break;
            case 'I':
                vis[ROMAN_I] = 1;
                break;
            default:
                break;
        }
        index++;
    }
}

int romanToInt(char * s){

    int len = strlen(s);
    int index = 0;
    int flag[7] = {0};
    int vis[7] = {0}; // M D C L X V I
    int cnt = 0;
    CheckState(s, flag, vis);

    while (index < len) {
        switch (s[index]) {
            case 'M':
                cnt += 1000;
                break;
            case 'D':
                cnt += 500;
                break;
            case 'C':
                if (flag[0] > 0 || flag[1] > 0) { // 在M前面
                    cnt -= 100;
                    // 检测
                    if (s[index + 1] == 'M') {
                        flag[0] = 0;
                    }
                    if (s[index + 1] == 'D') {
                        flag[1] = 0;
                    }
                } else {
                    cnt += 100;
                }
                break;
            case 'L':
                cnt += 50;
                break;
            case 'X':
                if (flag[2] > 0 || flag[3] > 0) { // 在L C前面
                    cnt -= 10;
                    if (s[index + 1] == 'L') {
                        flag[2] = 0;
                    }
                    if (s[index + 1] == 'C') {
                        flag[3] = 0;
                    }
                } else {
                    cnt += 10;
                }
                break;
            case 'V':
                cnt += 5;
                break;
            case 'I':
                if (flag[4] > 0 || flag[5] > 0) {
                    cnt -=1;
                    if (s[index + 1] == 'V') {
                        flag[4] = 0;
                    }
                    if (s[index + 1] == 'X') {
                        flag[5] = 0;
                    }
                } else {
                    cnt += 1;
                }
                break;
            default:
                break;
        }
        index++;
    }
    return cnt;
}