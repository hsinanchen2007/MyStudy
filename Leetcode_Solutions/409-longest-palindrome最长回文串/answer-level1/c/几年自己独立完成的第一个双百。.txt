
#define HASH_MAX     52
#define GET_HASH_KEY(tmp)    (tmp)%HASH_MAX

int longestPalindrome(char * s){
    /* 
    形成哈希表，逐个判断，
    偶数，half+=tmp/2
    奇数，half+=tmp/2   flag = 1
    flag == 1
        result = half *2 + 1
    else
        result = half *2
    */
    int hashTable[HASH_MAX] = {0};
    char *tmpS = s;
    int result = 0;

    if (strlen(s) == 0) {
        return 0;
    }

    while(*tmpS != '\0') {
        hashTable[GET_HASH_KEY(*tmpS)]++;
        tmpS++;
    }
    int half = 0;
    int falg = 0;
    int halfNum = 0;
    int halfFlag = 0;
    for (int i = 0; i < HASH_MAX; i++) {
        halfNum = hashTable[i]/2;
        halfFlag = hashTable[i]%2;
        if (halfFlag == 1) {
            falg = 1;
        }

        if (halfNum != 0) {
            half += halfNum;
        }
    }
    if (falg == 1) {
        result = half * 2 + 1;
    } else {
        result = half * 2;
    }
    return result;
}