### 解题思路
执行用时 : 4 ms, 在所有 C 提交中击败了 90.00% 的用户
内存消耗 : 5.6 MB, 在所有 C 提交中击败了 100.00% 的用户

字母异位词：指字母相同，但是排列顺序不同的字符串。

1、当字符串长度不同时，可提前结束判断
2、题目条件：两个字符串中含有的字符均为小写英文字母
3、同时遍历两个字符串，统计每个字符出现的次数
4、对字符串s中出现的字符次数进行+1
5、对字符串t中出现的字符次数进行-1
6、判断26个小写字母的次数是否为0

### 代码

```c
#define ARRAY_SIZE 26

bool isAnagram(char * s, char * t){
    int statis[ARRAY_SIZE] = {0};
    int s_len = strlen(s);
    int t_len = strlen(t);
    int i = 0;

    if (s_len != t_len)
    {
        return false;
    }

    for (i = 0; i < s_len; i++)
    {
        statis[s[i] - 'a']++;
        statis[t[i] - 'a']--;
    }

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (0 != statis[i])
        {
            return false;
        }
    }

    return true;
}
```