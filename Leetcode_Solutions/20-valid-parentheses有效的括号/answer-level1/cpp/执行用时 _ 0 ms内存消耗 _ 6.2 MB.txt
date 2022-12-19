### 解题思路
思路：遇到左括号加进去，右括号检验，匹配就和左括号抵消掉，不匹配就返回false

具体实现：利用vector构建栈数据结构，遍历string每个字符，若为左括号则push_back，遇到右括号判断vector是否空&&是否match，是则删除栈顶元素，否则返回false。最后防止左括号过多，检验vector是否为空。

### 代码

```cpp
class Solution {
public:
    bool isleft(const char& c){
        if (c=='('||c=='[') return true;
        if(c=='{') return true;
        return false;
    }
    bool match(const char& c1,const char& c2){
        if(c1=='('&&c2==')') return true;
        if(c1=='['&&c2==']') return true;
        if(c1=='{'&&c2=='}') return true;
        return false;
    }
    bool isValid(string s) {
        if (s.size()==0) return true;
        vector<char> stack;
        if (!isleft(s[0])) return false;
        stack.push_back(s[0]);
        for(int i=1;i<s.size();++i){
            if(isleft(s[i])){
                stack.push_back(s[i]);
            }else{
                if((stack.size()!=0)&&match(stack.back(),s[i])){
                    stack.pop_back();
                }else{
                    return false;
                }
            }
        }
        if(stack.size()==0){
            return true;
        }else{
            return false;
        }
    }
};
```