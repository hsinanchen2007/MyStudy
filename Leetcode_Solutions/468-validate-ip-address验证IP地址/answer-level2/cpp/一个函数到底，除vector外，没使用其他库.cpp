### 解题思路
满屏的if else ，看着确实头疼。主要就是分情况讨论，先判断是IPv4还是IPv6

### 代码

```cpp
class Solution {
public:
    string validIPAddress(string IP) {
        bool a=true;
        int n=IP.end()-IP.begin();
        for(auto p=IP.begin();p!=IP.end();++p)
            if(*p=='.')
            {
                a=true;
                break;
            }
            else if(*p==':')
            {
                a=false;
                break;
            }
        if(a)
        {
            if(n>15)
                return "Neither";
            vector<int> index{0};
            for(auto p=IP.begin();p!=IP.end();++p)
            {
                if(*p=='.')
                    index.push_back(p-IP.begin());
                else if(*p>'9'||*p<'0')
                    return "Neither";
            }
            index.push_back(n-1);
            if(index.end()-index.begin()!=5)
                return "Neither";
            else
            {
                for(int i=0;i<4;++i)
                {
                    int m=index[i+1]-index[i];
                    if(i==0||i==3)
                        ++m;
                    if(m<2||m>4)
                        return "Neither";
                    else if(m==4)
                    {
                        int b=index[i];
                        if(IP[index[i]]=='.')
                            ++b;
                        if(IP[b]>'2')
                            return "Neither";
                        else if(IP[b]=='2'&&IP[b+1]>'5')
                            return "Neither";
                        else if(IP[b]=='2'&&IP[b+1]=='5'&&IP[b+2]>'5')
                            return "Neither";
                    }
                    if(m>2)
                    { 
                        if(i==0&&IP[index[i]]=='0')
                            return "Neither";
                        else
                        {
                            if(IP[index[i]+1]=='0')
                                return "Neither";
                        }
                    }
                }
            }

            if(index[4]==index[3]||index[0]==index[1])
                return "Neither";
            else
                return "IPv4";
        }
        else if(n>39)
            return "Neither";
        else
        {
             if(n<15)
                return "Neither";
            vector<int> index{0};
            for(auto p=IP.begin();p!=IP.end();++p)
            {
                if(*p==':')
                    index.push_back(p-IP.begin());
                else if(!(*p <= 'f'&&*p >= 'a' || *p <= 'F'&&*p >= 'A' || *p <= '9'&&*p >= '0'))
                    return "Neither";
            }
            index.push_back(n-1);
            for(int i=0;i<8;++i)
            {
                int m=index[i+1]-index[i];
                if(i==0||i==7)
                    ++m;
                if(m<2||m>5)
                    return "Neither";
            }
            return "IPv6";
        }
    }
};
```