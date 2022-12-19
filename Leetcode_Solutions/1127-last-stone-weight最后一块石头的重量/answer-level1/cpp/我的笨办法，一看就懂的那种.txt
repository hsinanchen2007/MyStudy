### 思路：不断的判断，更新，排序，达到临界条件再判断就可以了。
```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1){
            return stones[0];
        }
        
        sort(stones.begin(), stones.end());
        int len = stones.size();
        int cnt = len;
        while(true){
            if(stones[cnt - 1] == stones[cnt - 2]){
                cnt -= 2;
                if(cnt == 0){
                    return 0;
                }
                if(cnt == 1){
                    return stones[0];
                }
            }
            if(stones[cnt - 1] != stones[cnt - 2]){
                stones[cnt - 2] = stones[cnt - 1] - stones[cnt - 2];
                cnt -= 1;
                if(cnt == 0){
                    return 0;
                }
                if(cnt == 1){
                    return stones[0];
                }
            }
            sort(stones.begin(), stones.begin() + cnt);
        }
        return 0;
    }
};
```
![1.png](https://pic.leetcode-cn.com/0d1d74ed2b86a4b8d2e5efb2d44f40ea7853443d768557c08e47ca1302931769-1.png)
