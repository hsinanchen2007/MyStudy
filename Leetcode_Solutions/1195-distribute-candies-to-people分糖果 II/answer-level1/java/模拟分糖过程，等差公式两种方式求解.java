### 解题思路
#### 解法二：模拟分糖过程
/**
 * 解法一：直接模拟分糖，每次第num%num_people个孩子分得的糖果数为num+1，直到最后不够分结束
 */
``` java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[0];
        if (num_people == 0) {
            return ans;
        }
        ans = new int[num_people];
        int num = 0;
        while (candies > 0) {
            //如果糖果数小于等于上一次所分，直接分完结束
            if (candies <= num) {
                ans[num % num_people] += candies;
                break;
            }
            ans[num % num_people] += ++num;
            candies -= num;
        }
        return ans;
    }
}
```
#### 解法二：利用等差公式求解（见官方题解）