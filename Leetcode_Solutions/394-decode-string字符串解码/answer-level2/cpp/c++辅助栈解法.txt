```
class Solution {
public:
    //将temp字符串复制nums数量个，然后返回这个字符串
    string handle(string temp,string nums)
    {
        string res;
        int m=atoi(nums.c_str());
        while(m)
        {
            res+=temp;
            m--;
        }
        return res;
    }
    string decodeString(string s) {
        stack<string>   temp;//存放[]里的字符串
        stack<string>  nums;//存放[]前的表示数字的字符串
        int m=1;//数字栈的标志位
        int n=0;//字符串栈的标志位
        string res;//存储结果
        int flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                if(nums.size()<m)
                {
                    string temp1;
                    temp1+=s[i];
                    nums.push(temp1);
                }
                else nums.top()+=s[i];
            }
            else if(s[i]=='[')
            {
                temp.push("");
                flag=1;
                n++;
                m++;
            }
            else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            {
                if(flag==1)
                {
                    if(temp.size()<n)
                    {
                        string temp1;
                        temp1+=s[i];
                        temp.push(temp1);
                    }
                    else temp.top()+=s[i];
                }
                else{
                    res+=s[i];
                }
            }
            else if(s[i]==']')
            {
                string temp2=handle(temp.top(),nums.top());
                temp.pop();
                nums.pop();
                if(temp.empty())    
                {
                   flag=0; 
                   res+=temp2;
                }
                else temp.top()+=temp2;
                n--;
                m--;
            }
            //if(!temp.empty()&&!nums.empty())
            //cout<<temp.top()<<','<<nums.top()<<endl;
        }
        return res;
    }
};
```
