### 解题思路
代码及注释如下

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {

        //创建两个栈分别存储两个字符串内的元素
        stack<char> s, t;

        //遍历字符串S内的字符
        for(char i : S)
        {   
            //如果当前字符为删除字符
            if(i=='#')
            {   
                //如果栈为空，则什么都不做
                //如果栈内有元素，则删除栈顶元素
                if(!s.empty()) s.pop();
            }

            //如果当前元素不是删除字符，则直接加入栈
            else s.push(i);
        }

        //用同样的方法构建t栈
        for(char i : T)
        {
            if(i=='#')
            {
                if(!t.empty()) t.pop();
            }

            else t.push(i);
        }

        //对s,t两栈内元素进行遍历
        while(!s.empty() && !t.empty())
        {   
            //若栈顶元素不同，说明结果不同
            if(s.top() != t.top()) return false;

            //若相同，则两栈同时弹出栈顶元素
            //若两栈相同，则最终都会弹空
            else
            {
                s.pop();
                t.pop();
            }
        }

        //若两栈有一个栈没弹空，则c长度不同，结果必不同
        if(!s.empty() || !t.empty()) return false;

        //若两栈全空，说明结果相同，返回真值
        return true;
    }
};
```