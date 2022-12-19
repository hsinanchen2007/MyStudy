### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int current_idx = 0;
        int[] ans = new int[num_people];
        while (candies > 0) {
            if (candies - current_idx > 0) {
                ans[current_idx%num_people] = ans[current_idx%num_people] + (++current_idx);
                candies -= current_idx;
            }
            else {
                ans[current_idx%num_people] = ans[current_idx%num_people] + candies;
                break;
            }
        }
        return ans;
    }
}
```