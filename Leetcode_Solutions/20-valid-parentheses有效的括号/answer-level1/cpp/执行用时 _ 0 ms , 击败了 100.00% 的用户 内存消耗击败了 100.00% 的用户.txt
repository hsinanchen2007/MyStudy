### 解题思路
使用一个stack去维护左括号的集合，一旦遇到左括号就压入stack，一旦遇到右括号，就比较栈顶与当前括号是否匹配。匹配的话，弹出，继续遍历。
边界条件：
(1) ")))" 对于没有左括号的情况，因此在调用stack的栈顶元素时，先要判断stack是否为空
(2) 遍历完string后，如果stack不为空，那么说明还有“残留”的左括号没有被匹配

trick: if(s.size()%2 > 0) return false;
括号必须成对出现，因此不可能字符串长度为奇数。我猜是这个trick，让这个方法速度击败了100%的用户

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> left_bracket;
        int len = s.size();
        if(s.size()%2 > 0) return false;
        for(int i = 0; i < len; ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                left_bracket.push(s[i]);
            }else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(s[i] == ')'){
                    if(left_bracket.empty() || left_bracket.top() != '(') return false;
                }else if(s[i] == ']'){
                    if(left_bracket.empty() || left_bracket.top() != '[') return false;
                }else{
                    if(left_bracket.empty() || left_bracket.top() != '{') return false;
                }
                left_bracket.pop();
            }else{
                return false;
            }
        }
        return left_bracket.empty();
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户