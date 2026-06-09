
bool isPalindrome(char * s){

    int lenS = 0;
    lenS = strlen(s);
    int i = 0;
    int countS = 0;//strSelect 有效长度
    int first = 0;
    int last = 0;

    char* strSelect = (char*)malloc(sizeof(char)*lenS);
    for (i = 0; i < lenS; i++) {
        if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9')))  {
            strSelect[countS] = s[i];
            countS++;//Notice :指向最后一个值的下一个
        }
    }
    for (i = 0; i < countS; i++) {
        if ((strSelect[i] >= 'A') && (strSelect[i] <= 'Z')) {
            strSelect[i] = strSelect[i] + 32 ;
        }
    }
    last = countS - 1;
    while (first < last) {bool isPalindrome(char * s){
    int lenS = 0;
    lenS = strlen(s);
    int i = 0;
    int countS = 0;//strSelect 有效长度
    int first = 0;
    int last = 0;

    char* strSelect = (char*)malloc(sizeof(char)*lenS);
    for (i = 0; i < lenS; i++) {
        if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= '0') && (s[i] <= '9')))  {
            strSelect[countS] = s[i];
            countS++;//Notice :指向最后一个值的下一个
        }
    }
        if (strSelect[first++] != strSelect[last--]) {
            return false;
        }
    }
    return true;
}