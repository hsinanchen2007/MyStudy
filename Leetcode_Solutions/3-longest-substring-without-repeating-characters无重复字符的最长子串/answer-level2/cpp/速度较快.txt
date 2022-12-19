解题思路：
用一个256大小的int数组存储位置信息，然后用双指针计算长度
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256]; //仿照哈希map，存储每个ascii字符出现的位置
        int max = 0, len = 0;
        int start = 0, end = 0;
        memset(flag, -1, sizeof(int)*256);//用sizeof初始化int数组时记得只能初始化为0或者-1
        for (int i = 0; i < s.length(); i++) {
            if (flag[s[i]] != -1&& flag[s[i]]>=start) {//没有相同元素，后面这个条件一定要加上
                start = flag[s[i]] + 1;//flag[s[i]]>=start，排除在start之前的元素，不然长度会记少
                len = end - start;
            }
            flag[s[i]] = i;//有重复时更新位置
            len++;
            end++;
            if (len > max) max = len;
        }
        return max;
    }
};
```

