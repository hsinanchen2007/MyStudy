### 解题思路
将数组从大到小进行排序，计数即可

### 代码

```cpp
class compare{
    public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0)
        {
            return 0;
        }
         sort(citations.begin(),citations.end(),compare());
         int sum=0;
         for(int i=0;i<citations.size();i++)
         {
            if(sum>=citations[i])
            {
                return sum;
            }
            sum++;
         }
         return sum;
    }
};
```