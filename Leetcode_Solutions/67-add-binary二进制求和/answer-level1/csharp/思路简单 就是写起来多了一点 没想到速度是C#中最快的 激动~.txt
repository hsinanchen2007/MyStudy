### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public string AddBinary(string a, string b) {
        string str="";
        int la=a.Length;
        int lb=b.Length;
        bool flag=false;
        for(int i=la-1,j=lb-1;i>=0  && j>=0;i--,j--)
        {
            if(a[i]=='1' && b[j]=='1' && flag==true)
            {
                str=str.Insert(0,"1");
                flag=true;
            }
            else if(((a[i]=='1' || b[j]=='1') && flag==true) ||(a[i]=='1' && b[j]=='1' && flag==false))
            {
                str=str.Insert(0,"0");
                flag=true;
            }
            else if(((a[i]=='1' || b[j]=='1') && flag==false) || (a[i]=='0' && b[j]=='0' && flag==true))
            {
                str=str.Insert(0,"1");
                flag=false;
            }
            else
            {
                str=str.Insert(0,"0");
                flag=false;
            }
            if(i==0 || j==0)
            {
                la=i-1;
                lb=j-1;
            }
        }
        if(la>=0)
        {
            for(;la>=0;la--)
            {
                if(a[la]=='1' && flag==true)
                {
                    str=str.Insert(0,"0");
                    flag=true;
                }
                else if(a[la]=='1' || flag==true)
                {
                    str=str.Insert(0,"1");
                    flag=false;
                }
                else
                {
                    str=str.Insert(0,"0");
                    flag=false;
                }
            }
        }
        else
        {
            for(;lb>=0;lb--)
            {
                if(b[lb]=='1' && flag==true)
                {
                    str=str.Insert(0,"0");
                    flag=true;
                }
                else if(b[lb]=='1' || flag==true)
                {
                    str=str.Insert(0,"1");
                    flag=false;
                }
                else
                {
                    str=str.Insert(0,"0");
                    flag=false;
                }
            }
        }
        if(flag==true)
        {
            str=str.Insert(0,"1");
        }
        return str;
    }
}
```