### 解题思路
官方解答【JAVA】详细中文注释，想了很久，看来以后要加强数学了。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = num_people;
        
        //多少人次获得完整礼物
        int p = (int) (Math.sqrt(2 * candies + 0.25) - 0.5);
        //剩下的糖果
        int remaining = (int)(candies -(p+1) * p * 0.5);
        int rows = p /n;//完整的轮次
        int cols = p % n;//最后一轮获得完整礼物的人数

        int d[] = new int[n];
        //每一次循环算出一个人该得多少糖果
        for(int i = 0; i < n; ++i)
        {
            //System.out.println(i);
            d[i] = (i + 1) * rows + (int)(rows *(rows - 1) * 0.5)* n;//完整轮数的糖果
            if(i < cols)//能获得最后一轮
            d[i] += i + 1 +rows * n;//加上不完整轮数的完整份数糖果
        }
        d[cols] += remaining;//最后一个人，加上不完整份数糖果
        return d;
    }
}
```