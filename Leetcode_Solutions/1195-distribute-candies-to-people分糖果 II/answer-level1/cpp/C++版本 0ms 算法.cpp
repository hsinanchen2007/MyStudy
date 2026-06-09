### 解题思路
利用上面老哥的解题思路写了c++版本的代码，速度真的快的吓银2333。
思路就是运用了上一次给出的糖果%(取余)等于容器的下标志，并且用最小值来收尾。
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> ans;
        int give=0;
        for(int c=0;c<num_people;c++)
        {
            ans.push_back(0);
        }
        while(candies>0)
        {
            ans[give%num_people]+=min(candies,give+1);
            give=give+1;
            candies= candies-give;
            
        }
        
        return ans;

    }
};
```