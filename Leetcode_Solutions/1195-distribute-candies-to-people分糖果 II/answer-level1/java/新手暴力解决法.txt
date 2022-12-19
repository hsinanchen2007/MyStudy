### 解题思路
解题方法：暴力方法，循环遍历发放。
1.通过一个剩余糖果数标识来区分最后一个人发多少糖果：如果发糖果时不足剩余，则发放剩余糖果。
2.通过发放轮数来区别每轮发放糖果数：如果糖果还有剩余足够按规则发放，此时每一轮的所有人都已经全部发放了，则进入下一轮发放。

*** first leetcode，还停留在解决问题，而不是优化思路。大概用时30min

### 代码

```java
class Solution {
    private int enter_count = 0; //发放轮数
    private int last_candies; //剩余糖果
    private int[] ans; //结果数组

    public int[] distributeCandies(int candies, int num_people) {
        if (enter_count == 0) {
            ans = new int[num_people];
            last_candies = candies;
        }
        for (int i = 0; i < num_people; i++) {
            if (ans[i] == 0) {
                int count = i + 1;
                if (last_candies < count) { //1
                    count = last_candies;
                    ans[i] = count;
                    break;
                } else {
                    ans[i] = count;
                    last_candies = last_candies - count;
                }
            } else {
                int count = enter_count * num_people + (i + 1);
                if (last_candies < count) { //1
                    count = last_candies;
                    ans[i] = ans[i] + count;
                    break;
                } else {
                    ans[i] = ans[i] + count;
                    last_candies = last_candies - count;
                }
            }
            if (last_candies <= 0) {
                break;
            } else {
                if (i == num_people - 1) { //2
                    enter_count++;
                    distributeCandies(last_candies, num_people);  
                }
            }
        }
        return ans;
    }
}
```