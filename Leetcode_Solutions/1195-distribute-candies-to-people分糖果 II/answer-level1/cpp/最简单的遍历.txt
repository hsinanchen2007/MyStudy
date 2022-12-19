### 解题思路
其实还可以优化为复杂度只和num_people的规模有关
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ret(num_people,0);
        for(int i=0;candies>0;i++)
        {
            if(candies-i-1>0)
                ret[i%num_people]+=i+1;
            else 
                ret[i%num_people]+=candies;
            candies-=i+1;
            
            
        }
        return ret;

    }
};

```