### 解题思路
只需要从头到尾比较相邻的两个字符串，每次记录最大匹配长度，下一次比较min(已匹配最大长度,两串字符串最大长度)即可

执行用时 :
4 ms
, 在所有 cpp 提交中击败了
94.55%
的用户
内存消耗 :
9 MB
, 在所有 cpp 提交中击败了
73.54%
的用户

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        if (size(strs)==0) return s;
        int max=size(strs[0]);
        if (size(strs)==1) {
            s=strs[0];
            return s;
        }
        for (int i=0;i<size(strs)-1;i++){
            int j=0;
            while ((j<min(size(strs[i]),size(strs[i+1])))and(j<max)and(strs[i][j]==strs[i+1][j])){
                j++;
            }
            if (j<max) max=j;
        }
        for (int i=0;i<max;i++)
            s=s+strs[0][i];
        return s;
    }
};
```