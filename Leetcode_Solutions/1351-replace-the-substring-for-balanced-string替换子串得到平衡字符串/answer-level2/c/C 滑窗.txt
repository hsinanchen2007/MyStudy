```
#define MIN(a, b) (a) <= (b) ? (a) : (b)
int GetCharId(char c)
{
    switch (c) {
        case 'Q':
            return 0;
        case 'W':
            return 1;
        case 'E':
            return 2;
        case 'R':
            return 3;
        default:
            return 0;
    }
}

int balancedString(char* s)
{
    int i, len, avg, ans, left = 0, right = 0;
    int nums[4] = {0};

    if (s == NULL) {
        return 0;
    }

    len = strlen(s);
    if (len % 4 != 0) {
        return 0;
    }

    avg = len / 4;
    ans = len;
    for (i = 0; i < len; i++) {
        ++nums[GetCharId(s[i])];
    }

    while (right < len) {
        // 滑动窗口里进来一个元素 就把nums里的这个值减1
        --nums[GetCharId(s[right])];
        // 如果四个元素都符合要求 就计算最小值
        while (left < len && nums[0] <= avg && nums[1] <= avg && nums[2] <= avg && nums[3] <= avg) {
            ans = MIN(ans, right - left + 1);
            // 移动左指针 看能不能缩小范围
            ++nums[GetCharId(s[left])];
            ++left;
        }
        ++right;
    }

    return ans;
}
```
