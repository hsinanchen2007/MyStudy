### 解题思路
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8 MB, 在所有 cpp 提交中击败了100.00%的用户
先把等式分为等号左边和等号右边2部分,然后分别计算左式x系数和la，左式常数和l1，右式x系数和ra，右式常数和r1,然后左右2边进行计算  左边放x系数，右边放常数式，判断是否等于0，分类讨论

### 代码

```cpp
class Solution {
public:
    string solveEquation(string equation) {
        int flag=0;//等号位置
        int l1=0;//左式常数和
        int la=0;//左式x系数和
        int r1=0;//右式常数和
        int ra=0;//右式x系数和r
        //计算等号位置
        for(int i=0;i<equation.size();i++)
        {
            if(equation[i]=='=')
            {
                flag=i;
                break;
            }  
        }
        //计算左式的常数和，x系数和
        for(int i=0;i<flag;i++)
        {
            int m=i;
            int flag1=0;
            string temp;
            while(m<flag&&equation[m]!='+'&&equation[m]!='-')
            {
                if(equation[m]=='x')
                    flag1=1;
                temp=temp+equation[m];
                m++;
            }
            //cout<<temp<<endl;
            if(i-1>=0&&equation[i-1]=='-')  temp='-'+temp;
            int a=0;
            if(temp=="x")   a=1;
            else if(temp=="-x") a=-1;
            else {
                stringstream ss;
                ss<<temp;
                ss>>a;
            }
            if(flag1==1)
                la=la+a;
            else l1=l1+a;
            i=m;
            //cout<<a<<endl;
        }
        //计算右式的常数和，x系数和
        for(int i=flag+1;i<equation.size();i++)
        {
            int m=i;
            int flag1=0;
            string temp;
            while(m<equation.size()&&equation[m]!='+'&&equation[m]!='-')
            {
                if(equation[m]=='x')
                    flag1=1;
                temp=temp+equation[m];
                m++;
            }
            //cout<<temp<<endl;
            if(equation[i-1]=='-')  temp='-'+temp;
            int a=0;
            if(temp=="x")   a=1;
            else if(temp=="-x") a=-1;
            else {
                stringstream ss;
                ss<<temp;
                ss>>a;
            }
            if(flag1==1)
                ra=ra+a;
            else r1=r1+a;
            i=m;
            //cout<<a<<endl;
        }
        //cout<<l1<<','<<la<<','<<r1<<','<<ra<<endl;
        la=la-ra;
        r1=r1-l1;
        if(la==0&&r1!=0)    return "No solution";
        else if(la==0&&r1==0)    return "Infinite solutions";
        r1=r1/la;
        string temp;
        stringstream res;
        res<<r1;
        res>>temp;
        return "x="+temp;

    }
};
```