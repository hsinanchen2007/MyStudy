### 解题思路
直接看代码吧

### 代码

```c
#define MAX_MAP_SIZE 128

int MAX(int a, int b)
{
    return a < b ? b : a;
}

int lengthOfLongestSubstringKDistinct(char * s, int k){
    int left, right, pos;
    int count;
    int length;
    int max;
    int map[MAX_MAP_SIZE] = {0};

    if ((s == NULL) || (s[0] == '\0')) {
        return 0;
    }

    if (k == 0) {
        return 0;
    }

    left = 0;
    count = 0;
    length = 0;
    max = 0;
    for (right = 0; s[right] != '\0'; right++) {
        pos = (int)(s[right]);
        map[pos]++;
        if (map[pos] == 1) {
            count++;
        }
        if (count > k) {
            while (count > k) {
                pos = (int)(s[left]);
                map[pos]--;
                if (map[pos] == 0) {
                    count--;
                }

                left++;
            }
        }
        length = right - left + 1;
        max = MAX(max, length);
    }
    
    return max;
}
```