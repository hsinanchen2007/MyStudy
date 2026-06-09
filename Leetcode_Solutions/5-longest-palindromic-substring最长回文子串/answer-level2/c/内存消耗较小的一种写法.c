类似动态规划的思想，不过写起来简单一些
考虑到对应字符串 s ，最长回文子串substr有可能存在于任何一个位置
记s的长度为size，p(size)为长度为size的字符串s的最长回文子串解，f(size)为长度为size的字符串s，最后一个元素能构成的最长回文子串解
设m为字符串s的最长回文子串的最后一个字符的位置，那么有p(size) = f(m+1) = max{f(1),f(2).....,f(m+1),...,f(size)};
也就是说size从1取到stelens(s)，找到其中最大的就可以了
```
int maxLength;
int maxIndex;
void longest(char *s, int size) {
    for(int i = 0; i < size; i++) {
        if(s[i] == s[size - 1]) {
            int left = i + 1;
            int right = size - 2;
            while(left < right) {
                if(s[left] != s[right]) {
                    break;
                }
                left++;
                right--;
            }
            if(left >= right) {
                if(maxLength < size - i) {
                    maxLength = size -i;
                    maxIndex = i;
                }
            }
        }
    }
}
char * longestPalindrome(char * s){
    maxIndex = 0;
    maxLength = 0;
    if(strlen(s) < 2) {
        return s;
    }
    for(int i = strlen(s); i >= 2; i--) {//size 从最大取到2 ，解肯定在里面，找个最大就可以了
        if(i > maxLength)//如果size 已经小于maxlength了，说明解肯定已经找到了
            longest(s, i);
    }
    char *retStr = malloc(maxLength + 1);
    memset(retStr, '\0', maxLength + 1);
    strncpy(retStr, s + maxIndex, maxLength);
    return retStr;
}
```

 