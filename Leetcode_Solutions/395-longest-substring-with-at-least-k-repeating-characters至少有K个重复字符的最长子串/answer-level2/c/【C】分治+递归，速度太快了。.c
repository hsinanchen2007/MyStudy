### 解题思路
思路：
    1. 先统计一波s字符串中各字符数记为dict，如果某个字符数小于k，该字符肯定不能作为子串，记录此位置为guard。
    2. 所以在整个字符串中，会出现许多的guard，讲道理，最长字符串肯定从这些个guard中间产生。
    3. 遍历s，计算guardx和guard(x+1)之间的字符串，此时之前统计的dict不能再用了，需要重新统计，调到1。
步骤：
    1. 遍历start, end之间的字符，统计字符出现个数，记为dict数组；
    2. 遍历start, end之间的字符，如果end - start <ｋ，直接返回0;
    3. 如果dict[i] <ｋ，记为guard;
    4. 获取相邻gurad之间的边界start', end'，跳到1；
    5. 计算相邻gurad之间统计子串个数的最大值，作为返回值；
注意：
    1. guard表示不符合要求的字符位置，因此起始guard放到id为-1的位置，最终guard放到结束符‘\0’的位置；
    2. 一定要保证所有的guard之间的子串都得到处理。
    3. 尤其需要考虑当s中只有一个区间(两个guard)，和最后一个区间(倒数第二个guard和最终'\0'结束符位置)的情况。
效果：
    
![image.png](https://pic.leetcode-cn.com/34b060427e90c47c502b57fbf018c8cefaa16aab794e1d4e8c30b803b7234a47-image.png)

### 代码

```c
int GetLongeestString(char *start, char *end, int k)
{
    if (start >= end || end - start - 1 < k) {
        return 0;
    }

    int val[26] = {0};
    char *tmp = start + 1;
    while (tmp < end) {
        val[(*tmp) - 'a']++;
        tmp++;
    }
    int max = 0;

    tmp = start + 1;
    char *lastPos = start;
    while (tmp < end) {
        if (val[(*tmp) - 'a'] < k) {
            int ret = GetLongeestString(lastPos , tmp, k);
            if (ret > max) {
                max = ret;
            }
            lastPos = tmp;
        }
        tmp++;
    }
 
    int ret = 0;
    if (lastPos == start) {
        ret = end - start - 1;
    } else {
        ret = GetLongeestString(lastPos, end, k);
    }

    if (ret > max) {
        max = ret;
    }

    return max;
}

int longestSubstring(char * s, int k){

    return GetLongeestString(s - 1, s + strlen(s), k);
}
```