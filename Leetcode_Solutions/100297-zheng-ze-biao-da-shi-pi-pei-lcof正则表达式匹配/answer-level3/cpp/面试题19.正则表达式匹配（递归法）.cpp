### 解题思路
核心要点：以正则式p为关键递归条件和递归出口
递归出口：当p为空时，返回s.empty()
递归条件：
（1）如果p[1]=='\*'，以下条件满足其一即可成功匹配：s与p.substr(2)成功匹配；s非空且s[0]与p[0]相同且s.substr(1)与p匹配成功；
（2）如果p[1]!='\*'（p[1]可能为某个字符、'.'、'\0'）：以下条件满足即可匹配：s非空且s[0]与p[0]相同且s.substr(1)与p.substr(1)匹配成功
执行用时 768 ms, 在所有 C++ 提交中击败了14.26%的用户
内存消耗 :13.5 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())return s.empty();
        if(p[1]=='*'){
            return isMatch(s,p.substr(2))||(!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p));
        }
        else{
            return (!s.empty())&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
        }
    }
};
```