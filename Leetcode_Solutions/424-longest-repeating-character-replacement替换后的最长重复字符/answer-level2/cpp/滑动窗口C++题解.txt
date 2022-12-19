### 解题思路
先统计各个字母的个数，找出最多的，窗口不断扩张
扩张到需要替换的已经比k多了，需要收缩窗口
左边界向右移动
### 代码

```cpp
class Solution {
public:
 int characterReplacement(string s, int k) {
       vector<int> hash(26,0);
       int l = 0, maxCnt = 0, res = 0;
       for(int i = 0; i < s.size(); i++)
       {
        maxCnt = max(maxCnt, ++hash[s[i] - 'A']);
        while(i - l + 1 - maxCnt > k)
            hash[s[l++] - 'A']--;
        res = max(res, i - l + 1);
       }
       return res;
    }
};
```