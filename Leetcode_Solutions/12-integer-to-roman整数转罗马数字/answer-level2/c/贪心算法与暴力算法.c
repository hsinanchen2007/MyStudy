### 解题思路
1. 暴力算法，列出所有的数码
2. 贪心算法，每次选取最大的数码

### 代码

```c

/* 贪心算法 */
typedef struct{
    int Num;
    char Roman[5];
} NumCode;

char * intToRoman(int num){
    NumCode NC[] = {{1000, "M"}, 
                    {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
                    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
                    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    char * res = (char *)malloc(sizeof(char)*20);
    memset(res, '\0', sizeof(char)*20);
    int k = 0;

    for(int i = 0; i< 13;i++){
        while(num >= NC[i].Num){
            num -= NC[i].Num;
            strcat(res, NC[i].Roman);
        }
    }
    return res;
}

/* 暴力算法 */
char* intToRoman(int num) {
    char *map[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, //个位
                       {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  //十位
                       {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  //百位
                       {"", "M", "MM", "MMM"}}; // 千位

    char *res = (char *)malloc(sizeof(char)*20);
    memset(res, '\0', sizeof(char)*20);
    strcat(res, map[3][num / 1000 % 10]);
    strcat(res, map[2][num / 100 % 10]);
    strcat(res, map[1][num / 10 % 10]);
    strcat(res, map[0][num % 10]);
    return res;
}

```