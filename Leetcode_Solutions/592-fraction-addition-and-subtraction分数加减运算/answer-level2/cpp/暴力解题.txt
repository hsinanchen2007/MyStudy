执行结果：通过显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了81.25%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了84.00%的用户
本题的思路，将所有的分数分母相乘，然后再把处理后的分子全部相加，最后在进行约分，即可得到最后的结果。
在于输入字符的数字范围为[1,10]，这个10是2位数，判断的时候要单独拿出来讨论
```
class Solution {
public:
    string fractionAddition(string expression) {
        long long num1=0;
        long long num2=1;
        string res;
        //所有的分数分母相乘
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]=='/')
            {
                if(i+2>expression.size()-1||expression[i+2]=='+'||expression[i+2]=='-')
                    num2=num2*(expression[i+1]-'0');
                else if(i+3>expression.size()-1||expression[i+3]=='+'||expression[i+3]=='-')
                    num2=num2*10;
            }
        }
        //所有的分数分子相加
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]=='/')
            {
                if((i-2<0||expression[i-2]=='+')&&(i+2>expression.size()-1||expression[i+2]=='+'||expression[i+2]=='-'))
                {
                    num1=num1+(expression[i-1]-'0')*(num2/(expression[i+1]-'0'));
                }
                else if((i-2<0||expression[i-2]=='+')&&(i+3>expression.size()-1||expression[i+3]=='+'||expression[i+3]=='-'))
                {
                    num1=num1+(expression[i-1]-'0')*(num2/10);
                }
                else if(expression[i-2]=='-'&&(i+2>expression.size()-1||expression[i+2]=='+'||expression[i+2]=='-'))
                {
                    num1=num1-(expression[i-1]-'0')*(num2/(expression[i+1]-'0'));
                }
                else if(expression[i-2]=='-'&&(i+3>expression.size()-1||expression[i+3]=='+'||expression[i+3]=='-'))
                {
                    num1=num1-(expression[i-1]-'0')*(num2/10);
                }
                else if((i-3<0||expression[i-3]=='+')&&(i+2>expression.size()-1||expression[i+2]=='+'||expression[i+2]=='-'))
                {
                    num1=num1+10*(num2/(expression[i+1]-'0'));
                }
                else if((i-3<0||expression[i-3]=='+')&&(i+3>expression.size()-1||expression[i+3]=='+'||expression[i+3]=='-'))
                {
                    num1=num1+num2;
                }
                else if(expression[i-3]=='-'&&(i+2>expression.size()-1||expression[i+2]=='+'||expression[i+2]=='-'))
                {
                    num1=num1-10*(num2/(expression[i+1]-'0'));
                }
                else if(expression[i-3]=='-'&&(i+2>expression.size()-1||expression[i+2]=='+'||expression[i+2]=='-'))
                {
                    num1=num1-num2;
                }
            }
        }
        //判断计算的分子结果是否为0，判断正负，给结果加上正负号
        if(num1==0)     return "0/1";
        if(num1<0)  res.push_back('-');
        num1=abs(num1);
        int m=num1;
        //分子分母约分
        for(int i=2;i<=m;i++)
        {
            while(num1%i==0&&num1/i!=0&&num2%i==0&&num2/i!=0)
            {
                num1=num1/i;
                num2=num2/i;
                m=num1;
            }
        }
        return res+to_string(num1)+'/'+to_string(num2);
    }
};
```
