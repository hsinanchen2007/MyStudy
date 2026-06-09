### 解题思路
1. 建立一个数字stack和一个字符stack, 迭代解析
2. 利用java的Object类型机制, 可以使用一个栈完成

### 代码

```c++ []
class Solution {
public:
    string decodeString(string s) {
        string res;
        for(int i=0; i<s.size(); ++i){
            // 考虑可能是多位数
            if(isdigit(s[i])){
                int j = i;
                int n = 0;
                while(j<s.size() && isdigit(s[j])) {n=n*10+(s[j]-'0'); j++;}
                nst.push(n);
                i = --j;
                continue;
            }
            else if(s[i]=='[')
                cst.push(s[i]);
            else if(s[i]==']'){
                // 解析完一个[]内的字符后继续压入字符栈中
                string temp;
                while(!cst.empty() && cst.top()!='[') {temp =cst.top()+temp; cst.pop();}
                cst.pop();
                int t = nst.top(); nst.pop();
                for(int i=0; i<t; ++i){
                    for(int j=0; j<temp.size(); ++j)
                        cst.push(temp[j]);
                }
            }
            else cst.push(s[i]);
        }
        while(!cst.empty()) {res=cst.top()+res; cst.pop();}
        return res;
    }

private:
    stack<char> cst;
    stack<int> nst;
};
```
```java []
class Solution {
    public String decodeString(String s) {
        int N = 0; // 记录字符串中的数字
        st = new Stack<Object>();
        char []ss = s.toCharArray();
        for(char ch: ss){
            if(Character.isDigit(ch)){
                N = N*10+ch-'0';
            }
            else if(ch == '['){
                st.push(Integer.valueOf(N));
                N = 0;
            }
            else if(ch == ']'){
                String temp = popStack(st);
                Integer cnt = (Integer)st.pop();
                for(int i=0; i<cnt; ++i) st.push(temp);
            }
            else{
                st.push(String.valueOf(ch));
            }
        }
        return popStack(st);
    }

    private String popStack(Stack<Object> st){
        String res = new String();
        // 将栈中所有字符出栈
        while(!st.isEmpty() && st.peek() instanceof String) res = st.pop()+res;
        return res;
    }

    private Stack<Object> st;
}
```
```python []
class Solution:
    def decodeString(self, s: str) -> str:
        st = []
        for c in s:
            if c != ']':
                st.append(c)
            else:
                infos = []
                while st and st[-1] !='[':
                    infos.append(st.pop(-1))
                st.pop()
                N = 0
                base = 1
                while st and st[-1].isdigit():
                    N += (ord(st.pop())-ord('0'))*base
                    base *= 10
                st.append(''.join(reversed(infos))*N)

        return ''.join(st)
```