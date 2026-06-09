### 解题思路
套用模板，hash数组记录当前窗口内元素计数，大于1时移动左指针直至满足条件为止。

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int* hash = (int*)malloc(sizeof(int) * 128);
    memset(hash, 0, sizeof(int) * 128);
    int left = 0;
    int right = 0;
    int ans = 0;
    int len = strlen(s);
    while (right < len) {
        hash[s[right]]++;

        while (hash[s[right]] > 1) {
            hash[s[left]]--;
            left++;
        }

        ans = (ans > (right - left + 1) ? ans : (right - left + 1));
        right++;
    }

    return ans;
}





```