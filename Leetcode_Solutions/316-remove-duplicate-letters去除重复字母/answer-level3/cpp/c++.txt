### 解题思路
贪心，每次找到当前最优的情况，即尽量让字典序小的字母排在前面。每次从当前位置往前推，如果前一个比当前字母字典序大且后面后重复，那么前一个字母一定会被删除。

### 代码

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(res.find(s[i])!=-1) continue;//前面已经将这个字母压入答案串了
            while(res.size()>0&&res.back()>s[i]&&s.find(res.back(),i)!=-1){//前一个字典序更大且后面有重复
                res.pop_back();
            }
            res.push_back(s[i]);
        }
        return res;
    }
};
```