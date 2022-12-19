### 解题思路
此处撰写解题思路
*(不是计算机专业的，所以不太清楚这是不是动规，只是自己感觉和动规类似，如果不是动规，请指正。)*
定义一个空字符串：子串'compare'，遍历's'，**如果's'中的字符'c'在子串中找不到，则将字符'c'添加在子串中；如果能找到'c'，则删掉字串中'c'之前的所有字符。**   最后通过子串的长度得到结果。
时间复杂度： O(n*m)  n：s的长度；  m：子串的长度
空间复杂度:  O(1)
        

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) return 1;
        if(s.size() == 0) return 0;
        string compare;
        int res = 0;
        for(char c : s){
            if(compare.size() > 0){
                for(int i=0; i<compare.size(); i++) if(compare[i] == c) compare.erase(0, i+1);
                compare.push_back(c);
                res = compare.size() > res?compare.size():res;
            }
            if(compare.size() == 0) compare.push_back(c);
        }
        return res;
    }
};
```