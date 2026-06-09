### 解题思路
chips = [1, 2, 2, 2, 3, 15, 23] 意味着位置1有1个筹码，位置2有3个筹码，同样位置3、15、23各有1个筹码。把所有筹码移动到一个位置，移动两步代价为0，那其实我就可以把所有“奇数位置”筹码移动到一个点A（奇数位置），且不必花费任何代价；同理，所有“偶数位置”的筹码移动到点B（偶数位置）也不需要任何代价。最终就是看A,B两点谁的筹码数多，把少的筹码移动到多的筹码的位置，每一个筹码的代价都是1。
### 代码

```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        if(chips.size()==0)return 0;
         int count_odd=0;
        int count_even=0;
        for(int i=0;i<chips.size();i++){
            if(chips[i]%2){
                count_odd++;
            }
            else{
                count_even++;
            }
        }
        return count_even>count_odd?count_odd:count_even;
        
    }
};
```