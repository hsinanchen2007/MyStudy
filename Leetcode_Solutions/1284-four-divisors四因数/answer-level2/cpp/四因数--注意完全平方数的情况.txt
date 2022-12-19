### 解题思路
一开始，为了避免完全平方数。在遍历因子，`j<sq`在这里没有取等号。然鹅，这正是醉鹅的源泉。我找了很久很久的错误。
容易知道，如果一个数是完全平方数的话，那么它一定不是四因子！因为它的因子个数一定为奇数。
为了避坑，我们直接在最开始的时候进行判断，如果是完全平方数，则continue，直接判断下一个。
因此在j那一层循环中，就大可不必去担心取不取等号的情况了。是应该取的，否则6和8这样的数都会被判定为不是四因子！

### 代码

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int cnt = 0;
            int tmp=0;     
            int sq = sqrt(nums[i]);     
            if(sq*sq == nums[i]){
                continue;//完全平方数一定不满足
            }
            for(int j=2;j<=sq;j++){//要取等号
            //比如8时，如果取j<sq,也就变成了j<2,此时就会判定8不是四因子
                if(nums[i]%j == 0){
                    tmp = j;
                    cnt++;
                    if(cnt == 2){
                        break;
                    }
                }
            }
            //有四个因子
            if(cnt == 1 && sq*sq != nums[i]){
                ans += (1+nums[i] + tmp + nums[i]/tmp);
            }
        }
        return ans;
    }
};
```