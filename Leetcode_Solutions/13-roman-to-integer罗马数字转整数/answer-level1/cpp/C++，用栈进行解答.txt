执行用时 20ms
采用栈的方式，类似于中缀表达式转后缀表达式算法。
先用switch对所有单个罗马数字进行赋值，从头开始遍历，如果遇到下一个元素比栈顶元素的值大，弹栈，二者相减。
否则压榨。字符串处理完毕，对栈中剩余元素一一弹栈，逐个相加。
代码如下：
class Solution {
public:
    int romanToInt(string s) {
        stack<char>  stk;
        int sum = 0;        //初始化和
        char temp = 'Q';    //随便值，应付
        for (int i = 0; i < s.length(); i++) {  //对字符串中元素逐个遍历
            if (!stk.empty() && romanTrans(s[i]) > romanTrans(stk.top())) {
            //字符串非空时，且当前元素大于栈顶元素
                temp = romanTrans(stk.top());
                sum = sum + romanTrans(s[i]) - temp;    //二者相减
                stk.pop();
            }
            else stk.push(s[i]);    //压栈
        }

        while (!stk.empty()) {      //对剩余元素一一相加
            sum = sum + romanTrans(stk.top());
            stk.pop();
        }

        return sum;
    }

    int romanTrans(char c) {
        switch (c)
        {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default:return 10000; break;
        }
    }
};
```

