### 解题思路
先回忆后缀表达式求值，我们是用栈1保存运算符，栈2保存数，当我们遇到遇到一个运算符时，就根据运算符出对栈2进行出栈并出栈，等等，这里可能需要你留意一下，我们是怎么知道要出栈几个呢？关键就是在这。两个啊，没错的确都是两个，这是因为加减乘除都是二元运算符。
回到这道题中，因为在这题中可以将所有逻辑运算符视为右结合，所以这和后缀表达式求值的情况是类似的，都是知道了运算符才去找这个运算符要操作的数，关键就是这里，怎么找到相应的操作数，之前后缀表达式求值可以很容易的找到运算数是栈2的前两个元素，这道题呢？我们发现当前逻辑运算符要操作的“数”（姑且允许我称为数），都在紧接它之后的一个括号内，我们只要把这个括号里的内容记下，在运算就可以完成这次操作，接着压入栈中。所以只要看到')'括号，我们就要进行一次运算了，因为逻辑运算符已经在栈1顶，“数”也可以因此确定范围了。
具体细节看代码。
### 代码

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk1;//保存逻辑运算符
        stack<char> stk2;//保存“数”
        //从左到右，而且遍历完最后一个')'括号时一定只剩stk2中一个元素
        for(int i=0; i< expression.size() ;i++ ){
            //是操作符就入stk1
            if( expression[i] == '|' || expression[i] == '&' || expression[i] == '!' )
                stk1.push(expression[i]);
            //是')'就知道要进行一次运算了
            else if( expression[i] == ')' ){
                int t = 0;//记录f和t出现的次数
                int f = 0;
                while(stk2.top() != '('){//这对括号里的就是要操作的“数”
                    if(stk2.top() == 't')
                        t++;
                    if(stk2.top() == 'f')
                        f++;
                    stk2.pop();
                }
                stk2.pop();
                char x = stk1.top();//弹出逻辑运算符
                stk1.pop();
                //接下来就是运算，并将结果压栈
                if( x == '!' ){
                    if(t == 1)
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
                else if( x == '|'){
                    if( t != 0 )
                        stk2.push('t');
                    else
                        stk2.push('f');
                }
                else if( x == '&' ){
                    if( f!= 0 )
                        stk2.push('f');
                    else
                        stk2.push('t');
                }
            }
            else
                stk2.push(expression[i]);
        }
        if(stk2.top() == 't' ) return true;//在表达式没有错误的情况，最后一定只会剩一个
        else return false;
        
    }
};
```
![1583924075(1).png](https://pic.leetcode-cn.com/98955d305b0d4c1a915d94db52b30451a30dee18e4c46da31170a07b335d2db6-1583924075\(1\).png)
