### 解题思路
  可以发现其实这里是一个每一次+1的一个等差数列，但是这里要注意就是循环累加和最后糖果剩余不足的情况了。刚开始想用count这个变量来记录循环次数，并用公式（count * n + index + i）来计算每一个下标应该添加的值。但是到最后发现循环次数，累加值这些信息都可以直接保留在 index % n(取模运算就是一循环，index这里就是等差数列的第几项，加上循环一起考虑的话就是每次的累加值。)。用一个循环条件的来判断剩下的糖果是否够不够分。

  时间复杂度：由于是等差数列的累加。由其公式知时间复杂度就算公式中的n，candies为累加和，所以应该为O（candies^0.5）；
  空间复杂度：只需要几个额外的空间，为O(1);

题外话：这道题一种大家都比较能想到的就是暴力求解的方法了，刚开始我也是用这种方法自己显示了一次，然后提交了运行通过，不是很快，循环内用了十几行代码吧。然后去看了1ms的解，才发现那才是一个简洁呀（暴击），2行搞定。官方因为是调用函数的原因也慢了不少。
### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int i = 0;
        int count = 1;      //count表示的是当前分配的糖果，与题解描述的count无关。
        while (candies - count > 0) {
            ans[i++ % num_people] += count;
            candies -= count++;
        }
        //最后糖果不够的情况
        ans[i % num_people] += candies;
        return ans;

    }
}
```