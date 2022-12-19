
思路就是从头到位判断每一个字符是否符合当前状态。状态从START开始，根据不同的情况进行流转。
虽然思路很简单，但是需要考虑的特殊情况比较多，debug了很久


```
class Solution {
public:
    bool isNumber(string s) {
        //status
        const int START=0;
        const int SIGN=1;
        const int NUM_1_L=2;
        const int NUM_2_L=3;
        const int NUM_1_L_NO_DOT=4;
        const int DOT_S=5;
         const int DOT_2=6;
        const int E=7;
        const int E_SIGN=8;
        const int BLOCK=9;
        const int ERROR=-1;

        int status=START;
        for(int i=0;i<s.size();i++)
        {
                switch(status)
                {
                        case START:
                        {
                                if(s[i]=='+'||s[i]=='-')
                                        status=SIGN;
                                else if(s[i]-'0'>=0&&s[i]-'0'<=9)
                                        status=NUM_1_L;
                                else if(s[i]==' ')
                                        status=START;
                                else if(s[i]=='.')
                                        status=DOT_S;
                                else
                                        status=ERROR;
                                break;
                        }
                        case SIGN:
                        {
                                if(s[i]-'0'>=0&&s[i]-'0'<=9)
                                        status=NUM_1_L;
                                else if(s[i]=='.')
                                        status==DOT_S;
                                else
                                        status=ERROR;
                                break;
                        }
                        case NUM_1_L:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=NUM_1_L;
                                else if(s[i]=='e'||s[i]=='E')
                                        status=E;
                                else if(s[i]=='.')
                                        status=DOT_2;
                                else if(s[i]==' ')
                                        status=BLOCK;
                                else
                                        status=ERROR;
                                break;
                        }
                        case E:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=NUM_2_L;
                                else if(s[i]=='+'||s[i]=='-')
                                        status=E_SIGN;
                                else
                                        status=ERROR;
                                break;
                        }
                        case E_SIGN:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=NUM_2_L;
                                else
                                        status=ERROR;
                                break;
                        }
                        case DOT_2:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=DOT_2;
                                else if(s[i]=='e'||s[i]=='E')
                                        status=E;
                                else if(s[i]==' ')
                                        status=BLOCK;
                                else
                                        status=ERROR;
                                break;
                        }
                        case NUM_2_L:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=NUM_2_L;
                                else if(s[i]==' ')
                                        status=BLOCK;
                                else
                                        status=ERROR;
                                break;
                        }
                        case DOT_S:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=NUM_1_L_NO_DOT;
                                else
                                        status=ERROR;
                                break;
                        }
                         case NUM_1_L_NO_DOT:
                        {
                                int val=s[i]-'0';
                                if(val>=0&&val<=9)
                                        status=NUM_1_L_NO_DOT;
                                else if(s[i]=='e'||s[i]=='E')
                                        status=E;
                                else if(s[i]==' ')
                                        status=BLOCK;
                                else
                                        status=ERROR;
                                break;
                        }
                        case BLOCK:
                        {
                                if(s[i]==' ')
                                        status=BLOCK;
                                else
                                        status=ERROR;
                                break;
                        }
                }
                if(status==ERROR)
                        break;
        }
        if(status==NUM_1_L||status==DOT_2||status==NUM_2_L||status==BLOCK||status==NUM_1_L_NO_DOT)
                return  true;
        else
                return false;

    }
};

```
提交结果：

![image.png](https://pic.leetcode-cn.com/c9657c2fb507bca223c1be376ab50d1a417480acfea7f4b3a6694780ee9d39c9-image.png)
