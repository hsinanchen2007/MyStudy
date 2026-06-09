### 解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        int len=s.size();
        if(len==0) return 1; //出口1

        if(len%2==1) return 0; //出口2

        stack<char> st; //初始化st栈
        st.push('0'); //避免栈空出现的错误 先压入一个0
        st.push(s[0]); //将str s中第一个字符压入
        for(int i=1;i<=len-1;i++)
        {
            //进栈时判断若与栈顶字符匹配则栈顶元素出栈
            if((st.top()=='('&&s[i]==')')||(st.top()=='['&&s[i]==']')||(st.top()=='{'&&s[i]=='}'))
          {
                st.pop(); 
          }      
            //若不匹配则入栈
            else{
                st.push(s[i]);
            }
        }
        std::cout <<"H"<<st.top()<<"H"<<endl;//输入栈顶元素进行判断
        if(st.top()=='0') return 1;//出口3
        else return 0;
    }
};

```