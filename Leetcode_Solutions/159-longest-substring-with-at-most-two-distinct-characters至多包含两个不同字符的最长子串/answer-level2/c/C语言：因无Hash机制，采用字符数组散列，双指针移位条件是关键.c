```
#define CHARACTER_NUMBER_SIZE 128
#define MIN_CHARACTER_NUMBERS 2
#define LEETCODE_MAX(a, b) (a) > (b) ? (a) : (b)
bool IsStrMoreThan2Chr(char *str, int start, int end)
{
    /* 若当前长度已小于2，直接返回false */
    if (end - start < MIN_CHARACTER_NUMBERS) {
        return false;
    }

    int count = 0;
    int nums[CHARACTER_NUMBER_SIZE] = {0};
    /* 遍历并按照字符统计计数，类似于Hash */
    for (int i = start; i < end; i++) {
        if (nums[str[i]] == 0) {
            nums[str[i]]++;
            count++;
        }

        if (count > MIN_CHARACTER_NUMBERS) {
            return true;
        }
    }

    return false;
}

int lengthOfLongestSubstringTwoDistinct(char * s)
{
    int left = 0;
    int right = 0;
    int ans = 0;
    int size = strlen(s);
    if (size <= MIN_CHARACTER_NUMBERS) {
        return size;
    }

    /* Use 2 points */
    while(right < size) {
        while (IsStrMoreThan2Chr(s, left, right + 1) == true) {
            left++;
        }
        ans = LEETCODE_MAX(ans, (right - left + 1));
        right++;
    }

    return ans;
}
```
