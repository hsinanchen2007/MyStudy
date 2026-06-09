### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m=0,n=0;
        if(str1.size()>str2.size())
        {
            m=str1.size();
            n=str2.size();
        }else{
            n=str1.size();
            m=str2.size();
        }
       
        int i=0;
        while(i<n)
        {
            if(str1[i]!=str2[i])
            break;

            ++i;

        }
        cout<<"i:"<<i<<endl;
        string result="";
        while(i>0)//i是最长匹配前缀的长度
        {
            if(m%i==0&&n%i==0)
            {
                string temp;
                for(int j=0;j<n/i;++j)
                {
                    temp=temp+str1.substr(0,i);
                }
                cout<<"temp1:"<<temp<<endl;
                if(temp==str1||temp==str2)
                {
                    for(int j=n/i;j<m/i;++j)
                    {
                        temp=temp+str1.substr(0,i);
                    }
                    cout<<"temp2:"<<temp<<endl;
                    if(temp==str2||temp==str1)
                    return str1.substr(0,i);
                }
                   

            }
            --i;
            
        }

    return result;
    }
};
```