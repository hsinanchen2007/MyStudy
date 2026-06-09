首先了解回文串特性：
由于对称性，奇数个数的字符最多只有一个，例如“aba”，b为奇数个，也可能是0个，例如“baab”，a、b均为偶数个。
也就是说回文串由若干个偶数个的字符和0个或1个奇数字符组成。

因此遍历输入的字符串，用哈希表计数方式统计每个字符的个数
为了统计以后不用再遍历哈希表算总数，可以再定义个数组，记录有值的哈希表下标，遍历数组即可。
遍历数组的时候偶数个直接统计进去，有奇数个的时候`flag`置`true`，并记录`cnt-1`个。
最后判断`flag`为`true`的话总数再`+1`。

代码如下：
```
#define HASH_SIZE (256)
#define GET_HASH_SUB(val) (val)

int longestPalindrome(char * s){
    int hash[HASH_SIZE];
    int notes[HASH_SIZE];
    int notesCnt = 0;
    int sub = 0;
    char *pChar = s;
    int len = 0;
    int flag = 0;

    if(NULL == s
        || 0 == strlen(s)){
        return 0;
    }

    memset(hash, 0, sizeof(hash));
    memset(notes, 0, sizeof(notes));
    while(*pChar != '\0'){
        sub = GET_HASH_SUB(*pChar);
        if(0 == hash[sub]++){
            notes[notesCnt] = sub;
            notesCnt++;
        }
        pChar++;
    }

    for(int i = 0; i < notesCnt; i++){
        sub = notes[i];
        if(0 == hash[sub] % 2){
            len += hash[sub];
        }else{
            len += hash[sub] - 1;
            flag = true;
        }
    }

    if(flag){
        len += 1;
    }

    return len;
}
```
