### 解题思路
將右括號壓入棧
左括號根據是否額能夠跟棧頂的括號匹配來決定是否有效抵消右括號，這裏要使用一個map來得到對應的右括號。
如果抵消則出棧右括號，如果不行則匹配失敗，返回false
最後檢查右括號是否被抵消完畢，如果完畢則返回true,否則返回false

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> c;
        unordered_map<char,char> m={{'(',')'},{'[',']'},{'{','}'}};
       // while(!c.empty()) c.pop();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') c.push(s[i]);//左括號入棧
            else if(!c.empty()&&s[i]==m[c.top()])//如果和右括號正確匹配,注意要檢查c是否為空
            {
                if(!c.empty())
                {
                    c.pop();
                }
                else return false;
            }
            else return false;//如果左邊括號沒有成功匹配
        }
        return c.size()==0;//如果右邊括號剩餘
    }
};
```