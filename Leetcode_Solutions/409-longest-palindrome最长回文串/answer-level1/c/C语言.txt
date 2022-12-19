先计数，由于是大小写字母，所以这里为了方便(不记得z的ascii)直接使用了char_arr[128]
回文串中，如果是奇数个字母，那么除了中间的字母外，其他字母的数量均是偶数；如果是偶数个字母，那么所有字母的数量都是偶数。
因此对每个字母取出最大的偶数个，并且如果存在数量为奇数的字母，最终结果需要加1。
另外，考虑到源串s的长度如果是奇数，那么肯定会存在数量为奇数个的字母

```
int longestPalindrome(char * s){
    int i = 0;
    int char_arr[128] = {0};
    int add_flag = 0;
    int count = 0;

    for (i = 0; s[i] != 0; i++){
        char_arr[s[i]]++;
    }

    if (i % 2 == 1) {
        add_flag = 1;
        for (i = 0; i < 128; i++) {
            count += char_arr[i] / 2 * 2;
        }
    } else {
        for (i = 0; i < 128; i++) {
            count += char_arr[i] / 2 * 2;
            if (char_arr[i] % 2 == 1) {
                add_flag = 1;
            }
        }
    }

    return count + add_flag;
}
```
