### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> m_data;

        for(auto & i : tokens){
            //当i为数字时入栈（需要检测负数）
            //int atoi (const char * str);
            //atoi (表示 ascii to integer)是把字符串转换成整型数的一个函数(C语言库函数)
            //c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同. 
            //这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string对象转换成c中的字符串样式。
            if(i[1] || isdigit(i[0])){
                m_data.push(atoi(i.c_str()));
            }
            else{
                int num2 = m_data.top();
                m_data.pop();
                int num1 = m_data.top();

                switch(i[0])
                {
                case '+':
                    m_data.top() = num1+num2;
                    break;
                case '-':
                    m_data.top() = num1-num2;
                    break;
                case '*':
                    m_data.top() = num1*num2;
                    break;
                case '/':
                    m_data.top() = num1/num2;
                    break;
                }
            }
        }
        return m_data.top();
    }
};
```