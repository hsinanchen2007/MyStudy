### 解题思路
见注释。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int [num_people];
        // i记录遍历位置; j记录要给下一个孩子的糖果数, 初始为0
        int i = 0, j = 1;
        // 如果剩余糖果数大于0, 一直循环
        while(candies > 0){
            // 若剩余糖果数大于要给下一个孩子的糖果数
            if(candies > j)
                // 剩余糖果数减去要给下一个孩子的糖果数
                candies -= j;
            else{
                // 否则说明剩余糖果数不够要给下一个孩子的糖果数, 剩下的糖果全部给下一个孩子, 糖果数清零, 退出循环
                j = candies;
                candies = 0;
            }
            // 按题目要求给孩子糖果, 给完糖果后切换遍历位置、切换于要给下一个孩子的糖果数
            result[(i++) % num_people] += j++;
        }
        return result;
    }
}
```