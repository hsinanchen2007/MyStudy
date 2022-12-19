### 解题思路
括号匹配，这题借助数据结构栈(stack)解决起来会很方便。我们来看下面这个例子，

s = "[{[]}]()"

直观看来，我们为了判断这个括号字符串是否合法，似乎很难去找到一个简洁的规律或法则作为判断标准。有个规则是，当一对括号匹配后，这对括号中间的所有括号字符必须成对匹配。从内往外看，当出现一对匹配括号时，如果我们将其消除掉，会让判断更简单些。比如上述的s我们可以简化为判断"[{}]()"，再进一步简化为"[]()"，显然此时就能很快判断了。我们借助消除内部相邻的匹配括号的方式让问题变得简单，于是想到用栈这样的数据结构来帮助我们具体实现。因为栈能保存之前的元素，且最近的加入的元素在栈顶，就方便我们进行比较。

根据以上思路，我们可以借助一个栈实现一个时间复杂度为O(n)，空间复杂度为O(n)的算法。新建一个栈。遍历s中的每个元素，尝试将该元素入栈，如果当前元素与栈顶元素形成匹配，则该元素不入栈，且栈顶元素出栈。匹配规则需要再写一个函数，即cmp函数。遍历结束后，如果所有括号符号满足匹配规则，那么栈里应该没有元素了，即栈为空，返回true；若栈不为空，则返回false。


### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len == 0) return true;
        if(len % 2 != 0) return false;
        for(int i=0;i<len;i++){
            if(!st.empty()){
                char topst = st.top();//what if st is empty?
                if(cmp(topst,s[i])){    //if they match
                    st.pop();
                }else{
                    st.push(s[i]); //push into the stack when not matched
                }
            }else{
                st.push(s[i]);
            }

        }
        if(st.empty()) return true;
        else return false;

    }
private:
    stack<char> st;
    bool cmp(char c1,char c2){
        if((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')')){
            return true;
        }else{
            return false;
        }
    }
};
```