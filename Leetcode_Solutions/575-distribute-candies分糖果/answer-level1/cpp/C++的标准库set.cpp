- 当糖果种类大于数组大小的一半时（len/2），妹妹可以任选(len/2)种的糖果;
- 当糖果种类(c)小于数组大小的一半时（len/2），妹妹最多可以任选c种的糖果.
- 所以计算糖果的种类即可，借助set结构元素不同的特性，即可统计糖果的种类

``` C++
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        if(candies.empty())
            return 0;
        int len=candies.size();        
        set<int> s;
        for(int i=0;i<len;i++)
        {
            s.insert(candies[i]);
        }
        int c=s.size();
        if(c>=len/2)
            return len/2;
        else
            return c;
    }
};
```