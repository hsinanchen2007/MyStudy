变量含义解释：

为了方便，下文中所有local作用域代表离current 字符最近的左右括号圈起来的区域。

- `res` 代表现阶段的local作用域中的和，比如我要求`(1+3+3)`那么当遇到右括号的时候 `res`的值最后是7
- `curnum`代表每个被运算操作符隔开的元素，所以每遇见一个运算符会置零一次，同时把本身加到res里面
- `sign`是和`curnum`对应的

### 算法思路：

每次遇到一个左括号就知道自己进入了一个新的local作用域，把之前没有处理完的和先推到栈里面，备用
遇到一个右括号，说明现在的作用域都处理好了，把推到栈里的没处理完的接着用作`res`，然后现在这个处理完的括号内的和作为`curnum`留着以后处理
感觉非常像程序运行的时候 call一个函数入栈和出栈过程了orz
以及有一个tricky的地方就是在字符串的末尾加了一个运算符，这样他会自行把最后的加起来。

ps：
- 我的输入变成了 st 主要是因为把stack命名成了`s`之后全写完了才看到，然后懒得一逼索性直接改了输入变量名，懒人鉴定完毕
- 代码没有优化有点丑，希望大家不要嫌弃
- 算法思路中的备用。。。大概是看微博里的做菜教程看多了，吃货鉴定完毕



```
class Solution {
public:
    int calculate(string st) {
        
        stack<int> s;
        stack<char> ope;
        st.push_back('+');
        long res=0;
        long curnum = 0;
        bool sign = true;
        for(auto& cur:st){
            if(cur==' ') continue;
            if(cur=='('){
                s.push(res);
                if(sign) ope.push('+');
                else ope.push('-');
                res = 0;
                curnum = 0;
                sign = true;
            }
            if(cur=='+'||cur=='-'){
                res = sign? res+curnum: res-curnum;
                curnum = 0;
                sign= cur=='+';
                
            }
            if(isdigit(cur)){
                curnum = curnum * 10 + cur - '0';
            }
            if(cur==')'){
                res = sign? res+curnum: res-curnum;
                curnum = res;
                res = s.top();
                sign= ope.top()=='+';
                ope.pop(); s.pop();
            }
            
        }
        return res;

    }
};
```


