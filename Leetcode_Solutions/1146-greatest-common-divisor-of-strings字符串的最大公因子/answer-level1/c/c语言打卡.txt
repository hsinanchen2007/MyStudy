### 解题思路

### 代码

```c
int gcd(int a, int b){
    int newb;
    while(b != 0){
        newb = a % b;
        a = b;
        b = newb;
    }
    return a;
}

char* stradd(char* str1, char* str2){
    char* str = (char*)calloc((strlen(str1) + strlen(str2) + 1), sizeof(char));
    strncpy(str, str1, strlen(str1));
    strncat(str, str2, strlen(str2));
    return str;
}

char * gcdOfStrings(char * str1, char * str2){
    char *str12 = stradd(str1, str2), *str21 = stradd(str2, str1), *str;
    int gcdOfStr = gcd(strlen(str1), strlen(str2));
    if(strcmp(str12, str21))
        str = (char*)calloc(1, sizeof(char));
    else{
        str = (char*)calloc(gcdOfStr + 1, sizeof(char));
        strncpy(str, str1, gcdOfStr);
    }
    free(str12);
    free(str21);
    return str;
}

```