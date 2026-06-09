### 解题思路
开一个bool数组记录是否出现过就行，发现重复就返回
![789.png](https://pic.leetcode-cn.com/3861f60395fe173ab12ce1bb67bc29b1448391bdd38f51cbbb0a1b03618f50b1-789.png)
### 代码

```cpp
class Solution {
public:
     bool isUnique(string astr) {
     bool judge[128];
     memset(judge, false, sizeof(judge));
     for (int i = 0; i < astr.size(); i++)
     {
         if (judge[(int)astr[i]] == true)
             return false;
         else
             judge[(int)astr[i]] = true;
     }
     return true;
 }
};
```