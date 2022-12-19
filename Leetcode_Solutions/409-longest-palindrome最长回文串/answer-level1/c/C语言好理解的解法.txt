解题思路：
    先计算相同字母的个数
    个数为偶数就是回文串
    个数为奇数，但是大于2，少一个的偶数也是回文串
    再这个基础上还可以加上一个字母（如果是一个的也可以，如果其中有奇数的也可以）

    这三种情况按照循序加起来就可以了

int longestPalindrome(char * s)
{
    int i, j;
    int sum = 0;
    int n[127] = {0};
    int len = strlen(s);
    if (s == NULL ||len == 0) {
        return 0;
    }
    for (i = 0; i < len; i++) {
        n[s[i]]++;
    }
    for (i = 0; i < 127; i++) {
        if (n[i] % 2 == 0) {
            sum = sum + n[i];
        } else if (n[i] % 2 != 0 && n[i] > 2) {
            sum = sum + n[i] - 1;
        }
    }
    for (i = 0 ; i < 127; i++) {
        if (n[i] == 1 || (n[i] % 2 != 0)) {
            sum = sum + 1;
            break;
        } 
    }
    return sum;
}