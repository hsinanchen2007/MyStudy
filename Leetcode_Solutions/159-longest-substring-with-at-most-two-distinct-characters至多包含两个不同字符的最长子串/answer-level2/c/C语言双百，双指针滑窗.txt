1、右指针往前滑，只要当前滑窗内只有预期的两个字符（用first、second辅助）。
2、左指针最终用指向最后一个不同的字符，举个例子 aabbbaabbddee，一次滑窗之后，左指针需要指向小数点的位置aabbbaa.bbddee，通过右指针往前偏移。

![image.png](https://pic.leetcode-cn.com/976376bacfc5f349dab0ed80b7a31463314db5b0465773b553b16a42039ceaab-image.png)
```
int lengthOfLongestSubstringTwoDistinct(char * s){
    int size = strlen(s);
    int max = 0;
    int left = 0;
    int right = 0;
    int cnt = 0;
    char first = '\0';
    char second = '\0';

    while (right < size) {
        while (s[right] == first || first == '\0') {
            first = s[right];
            right++;
        }

        while ((right < size) && (s[right] == second || second == '\0')) {
            second = s[right];
            right++;
        }

        while ((right < size) && (s[right] == first || s[right] == second)) {
            right++;
        }


        cnt = right - left;
        max = max > cnt ? max : cnt;

        left = right;
        first = s[left - 1];
        while ((second != '\0') && (first == s[left - 1])) {
            left--;
        }
        second = '\0';
        //printf("%d %d %d\n", left, right, max);
    }
    return max;
}
```
