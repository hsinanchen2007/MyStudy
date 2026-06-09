### 解题思路
可直接模拟分糖果的过程，每次数组下标加一时对数组下标取余num_people，当到末尾时转到数组头

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int use=1,nowi;
        while(candies>0){
            if(use>candies) use=candies;
            candies-=use;
            res[nowi]+=use;
            use++;
            nowi=(nowi+1)%num_people;
        }
        return res;
    }
};
```