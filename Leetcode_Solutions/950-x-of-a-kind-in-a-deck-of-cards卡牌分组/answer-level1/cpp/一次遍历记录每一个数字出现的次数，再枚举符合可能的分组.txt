### 解题思路


### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<=1)
        return false;
            unordered_map<int,int>  mp;
            for(int i=0;i<deck.size();i++)
            { 
                    mp[deck[i]]++;
                  
            }
            unordered_map <int,int>::  iterator it;
          
            for(int i=2;i<=deck.size();i++)
            {
                if(deck.size()%i==0)   //如果每组元素个数可以被总数整除
                {
                    bool  flag=1;
                    it=mp.begin();
                  
                    while(it!=mp.end())//这个数是否可以分成几个或者多个数量为i的分组
                    {
                        if(it->second%i!=0)
                        {   
                            flag=0;
                            break;
                        }
                        it++;
                    }
                    if(flag)
                        return true;
                }
            }
        return false;
    }
};
```