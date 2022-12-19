// LeetCode5.最长回文子串
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 说明：
// (1)只要找到其中一个答案
// (2)题目要求返回指针或数组时，一定要用malloc申请，否则返回时会被释放，结果总是为NULL；
//    这就是malloc申请的内存（堆区）和函数自动分配的内存（栈区）的生存周期区别
// (3)strlen(s)求长度，要求s是数组，而不是指向数组的指针
// strlen(s)要求s最好为数组
// 如果s为空数组，strlen(s)=0
// 如果s为空指针，无打印
// (4)复制字符串时，要用库函数（如strcpy）而不是直接赋值，且要保证dest足够大
// (5)想用函数修改数组，那就将一个数组指针传入函数，函数无返回值

// 算法：中心扩散法
// 以中间字符为轴心，向两边扩散来判断回文串
// 时间复杂度:O(n^2)；空间复杂度:O(n)
// 值得一提的是，这个问题可以用动态规划方法解决，时间复杂度一样，但是空间复杂度至少要 O(N^2) 来存储 DP table。
// 这道题是少有的动态规划非最优解法的问题。


```
#include <string.h>
#include <stdlib.h>
#define MAX_N 2000

// 寻找最长回文子串
void palindrome(char* dest, const char* s, int left, int right)
{
    int len = strlen(s);
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    
    strncpy(dest, s + left + 1, right - 1 - left);
    return;  
}

char * longestPalindrome(char * s)
{
    if (s == NULL || strlen(s) <= 1) {
        return s;
    }
    
    int len = strlen(s);
    int i;
    char* res = (char*)malloc(MAX_N * sizeof(char));  // 这个一定要用malloc申请
    memset(res, 0, MAX_N * sizeof(char));
    
    for (i = 0; i < len; i++) {
        char s1[MAX_N] = {0};   // 一定要用数组
        char s2[MAX_N] = {0};   // 一定要用数组
        palindrome(s1, s, i, i);     // 以s[i]为中心的最长回文子串
        palindrome(s2, s, i, i + 1);    // 以s[i]和s[i+1]为中心的最长回文子串
        
        // 返回res, s1, s2中最大者
        if (strlen(s1) > strlen(res)) {
            strcpy(res, s1);    // 如果res不够大，复制字符串时会发生溢出
        }
        
        if (strlen(s2) > strlen(res)) {
            strcpy(res, s2);    // 如果res不够大，复制字符串时会发生溢出
        }
    }
    
    return res;
}
```
