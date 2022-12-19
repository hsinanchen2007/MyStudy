官方题解的思路：错在跳过两个的问题。。。。。
```
int count=0;
        for(vector<int>::iterator it=(prices.begin()+1);it<prices.end();it++)
        {
            if(*it>*(it-1))
            {
              count+=(*it-*(it-1));
            }           
        }
        return count;
```
