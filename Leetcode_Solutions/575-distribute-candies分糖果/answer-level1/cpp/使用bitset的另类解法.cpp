用bitset代替set标记糖果种类，效率会比set更高



执行用时 :192 ms, 在所有 C++ 提交中击败了97.67%的用户
内存消耗 :16 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        
        bitset<200001> pool;
        
        for(int i=0; i<candies.size(); i++){
            
            pool.set(candies[i]+100000);
        }
        
        return min(candies.size()/2, pool.count());
        
    }
};
```
