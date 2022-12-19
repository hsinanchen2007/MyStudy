### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int turn = 0;
        int sum = (1 + num_people) * num_people / 2;
        
        // 计算糖果可以满足的完整轮次数turn
        while(candies - sum > 0) {
            turn++;
            candies -= sum;
            sum = (turn * num_people * 2 + 1 + num_people) * num_people / 2;
        }
        // 利用turn，算出走完turn轮次的每个小孩的糖果数
        for(int i=0; i<num_people; i++) {
            ans[i] = (i + 1 + num_people * (turn - 1) + i + 1) * turn / 2;
        }
        // 剩余糖果依次递减
        for(int i=0; candies; i++) {
            int curcandies = turn * num_people + i + 1;
            if(candies > curcandies) {
                ans[i] += curcandies;
                candies -= curcandies;
            }
            else{ 
                ans[i] += candies;
                break;
            }
        }

        return ans;
    }
};
```
![微信图片_20200305115426.png](https://pic.leetcode-cn.com/778cbe84a4ec3c92abd0eeac0a45d1bbd443fc771d4914f4f6502be3f4d8c3fa-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200305115426.png)
