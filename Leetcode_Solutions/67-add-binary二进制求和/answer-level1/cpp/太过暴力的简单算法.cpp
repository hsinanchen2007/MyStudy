class Solution {
public:
    string addBinary(string a, string b) {
        string c="";
        bool flag=false;//进位
        int a1=a.length();
        int b1=b.length();
        //补齐长度
        while(a1<b1)
        {
            a='0'+a;
            a1++;
        }
        while(a1>b1)
        {
            b='0'+b;
            b1++;
        }
        for(int i=a1-1;i>=0;i--)
        {
            if((a[i]=='1')&&(b[i]=='1')&&(flag==false))
            {
                c='0'+c;
                flag=true;
            }
            else 
            {
                if((a[i]=='1')&&(b[i]=='1')&&(flag==true))
                    c='1'+c;
                else
                {
                    if(a[i]=='1'&&b[i]=='0'&&flag==true)
                        c='0'+c;
                    else
                    {
                        if(b[i]=='1'&&a[i]=='0'&&flag==true)
                            c='0'+c;
                        else
                        {
                            if(a[i]=='1'&&b[i]=='0'&&flag==false)
                                c='1'+c;
                            else
                            {
                                if(b[i]=='1'&&a[i]=='0'&&flag==false)
# **                                   c='1'+c;**
                                else
                                {
                                    if(a[i]=='0'&&b[i]=='0'&&flag==true)
                                    {
                                        c='1'+c;
                                        flag=false;
                                    }
                                    else
                                    {
                                       c='0'+c;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag==true)//首位进一
            c='1'+c;
        return c;
    }
};