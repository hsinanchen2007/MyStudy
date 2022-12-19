### 解题思路
一、拆分所有数字
二、对拆出来的数字加点，此处分类讨论，分为0开头与非0开头即可
### 代码

```cpp
class Solution {
public:
//第一版代码漏掉了一个处理情况，就是在开始为0的时候，得判断末尾是否为0
    vector<string> par(string now)
    {
        vector<string> temp;
        if(now[0]=='0')
        {
            long long now1=stoll(now);
            if(now1!=0&&now[now.size()-1]!='0')//这个点没有考虑到，哎。。。。注意多细致的思考
                temp.push_back("0."+now.substr(1));
            else
            {
                if(now.size()==1)
                    temp.push_back("0");
            }
        }
        else
        {
            if(now[now.size()-1]=='0')
            {
                temp.push_back(now);
            }
            else
            {
                temp.push_back(now);
                for(int i=0;i<now.size()-1;++i)
                {
                    temp.push_back(now.substr(0,i+1)+'.'+now.substr(i+1));
                }
            }
        }
        return temp;
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        S=S.substr(1,S.size()-2);
        for(int i=1;i<=S.size()-1;++i)
        {
            string temp1=S.substr(0,i);
            string temp2=S.substr(i);
            vector<string> temp3=par(temp1);
            vector<string> temp4=par(temp2);
            for(auto it:temp3)
                for(auto it2:temp4)
                {
                    res.push_back('('+it+", "+it2+')');
                }
        }
        return res;
    }
};
```