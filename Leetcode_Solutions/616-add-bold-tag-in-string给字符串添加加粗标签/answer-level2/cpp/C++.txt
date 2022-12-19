### 解题思路
98.23%+81.08%

### 代码

```cpp
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) 
    {
        int l1=s.length();
        if(l1==0||dict.size()==0)return s;
        int a[l1+1],c;
        memset(a,0,sizeof(a));
        for(auto p:dict)
        {
            c=-1;
            while(c!=l1)
            {
                c=s.find(p,c+1);
                if(c!=-1)
                {
                    for(int i=c;i<c+p.length();i++)
                    {
                        a[i]=1;
                    }
                }
                else break;
            }
        }
        int i=0,cnt=0;;
        while(i<l1)
        {
            if(a[i])
            {
                s.insert(i+cnt,"<b>");
                while(i<l1&&a[i])i++;
                s.insert(i+3+cnt,"</b>");
                cnt+=7;
            }
            i++;
        }
        return s;
    }
    
};
```