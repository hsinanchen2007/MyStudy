### 解题思路
此处撰写解题思路

将等差数列的项数记为p,将除等差数列外剩余的糖果数记为remaining,则有 remaining = candies - p(p+1)/2
再由 0 <= remaining < p + 1 可推出  p = (int)(Math.sqrt(2 * candies + 0.25) - 0.5)
rows 为完整分糖果的轮数，cols 为不完整分糖果的次数，具体表述如下：
1 完整分糖果阶段：第 i 个人可分得的糖果数为 i+(i+n)+(i+2*n)+...+(i+(rows-1)*n) = i*rows + n*rows*(rows-1)/2
2 不完整分糖果阶段：共进行 cols + 1 次，其中前 cols 人按等差数列规律进行分配，第 i 个人可再分得 (i + 1 + rows * n) 个糖果
  第 cols + 1 个人分得 remaining 个糖果
### 代码
// 此代码借鉴了官方题解
```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = num_people;
        /*
        将等差数列的项数记为p,将除等差数列外剩余的糖果数记为remaining,则有 remaining = candies - p(p+1)/2
        再由 0 <= remaining < p + 1 可推出  p = (int)(Math.sqrt(2 * candies + 0.25) - 0.5)
        rows 为完整分糖果的轮数，cols 为不完整分糖果的次数，具体表述如下：
        1 完整分糖果阶段：第 i 个人可分得的糖果数为 i+(i+n)+(i+2*n)+...+(i+(rows-1)*n) = i*rows + n*rows*(rows-1)/2
        2 不完整分糖果阶段：共进行 cols + 1 次，其中前 cols 人按等差数列规律进行分配，第 i 个人可再分得 (i + 1 + rows * n) 个糖果
          第 cols + 1 个人分得 remaining 个糖果
        */
        int p = (int)(Math.sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        int[] result = new int[n];
        for(int i = 0; i < n; ++i) {
            // 完整分配糖果轮数
            result[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
            // 最后一轮不完整分配
            if (i < cols) result[i] += i + 1 + rows * n;
        }
        // 循环结束后，第 cols + 1 个人再分得 remaining 个糖果        
        result[cols] += remaining;
        return result;
  }
}
```