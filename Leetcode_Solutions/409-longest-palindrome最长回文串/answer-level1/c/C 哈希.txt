### 解题思路
简单哈希
用了两个数组区分大小写

### 代码

```c

//只要是偶数个元素都可以作为回文的一部分 
//但是奇数只能有一个放在中间
#define MAXLENGTH 26
bool isLittleCase(char word)
{
    if ((word >= 'a') && (word <= 'z')) {
        return true;
    }
    return false;
}

int longestPalindrome(char * s){
    char * tmp = NULL;
    int longestCount = 0;
    bool haveSingle = false;
    //申请两个数组分别装大小写字母的出现的个数
    int* littleArray = (int *)malloc(sizeof(int) * MAXLENGTH);
    int* bigArray = (int *)malloc(sizeof(int) * MAXLENGTH);
    memset(littleArray, 0, sizeof(int) * MAXLENGTH);
    memset(bigArray, 0, sizeof(int) * MAXLENGTH);

    if (s == NULL) {
        return 0;
    }

    if (*s == '\0') {
        return 0;
    }

    for (tmp = s; *tmp != '\0'; tmp++) {
        if (isLittleCase(*tmp)) {
            littleArray[*tmp - 'a']++;
        } else {
            bigArray[*tmp - 'A']++;
        }
    }

    for (int i = 0; i < MAXLENGTH; i++) {
        if (littleArray[i] % 2 == 0) {
            longestCount = longestCount + littleArray[i];
        } else {
            longestCount = longestCount + littleArray[i] - 1;
            haveSingle = true;
        }

        if (bigArray[i] % 2 == 0) {
            longestCount = longestCount + bigArray[i];
        } else {
            longestCount = longestCount + bigArray[i] - 1;
            haveSingle = true;
        }
    }
    if (haveSingle == true) {
        longestCount++;
    }
    free(littleArray);
    free(bigArray);
    return longestCount;
}
```