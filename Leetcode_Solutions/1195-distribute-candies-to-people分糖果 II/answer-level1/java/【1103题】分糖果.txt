**方法一：暴力循环分糖**
```
class Solution {
    /**
    * 思路：
    * (1) 由题可依次知给num_people个小朋友分糖果，糖足够的情况第几次分糖就分几颗。
    * (2) 只要糖没有分完就循环遍历数组，每次总糖果数减去分出去的糖果数。
    * (3) 循环过程中，如果糖果当前一次分不完，当前位置的糖果数累加该得的糖果数；
    *       如果当前一次不够分，则剩多少都累加到当前位置并跳出循环。
    */
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int cur = 0;
        while(candies > 0){
            for(int i = 0; i < num_people; i++){
                candies -= ++cur;
                if(candies >= 0){
                    ans[i] += cur;
                }else {
                    // 如果candies为负数，则该分的糖果数减去差的糖果数就是实际分得的糖果数。
                    ans[i] += cur + candies;
                    return ans;
                }
            }
        }
        return ans;
    }
}
```

**方法二：**
```
class Solution {
    /**
    * 思路：
    * 同方法一，减少代码量，增加了运算时间(多了Math方法的调用)。
    */
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int i = 0;
        while (candies != 0) {
            ans[i % num_people] += Math.min(candies, i + 1);
            candies -= Math.min(candies, i + 1);
            i++;
        }
        return ans;
    }
}
```

**方法三：运用等差数列公式**
![distribute_candies.png](https://pic.leetcode-cn.com/9120f7c82aa050a9f9cd9137568e61dbefc85499d39d0236963eff50cb51237c-distribute_candies.png)

```
class Solution {
    /**
    * 思路：
    * 由题可知足够的糖是按等差数列分的，
    * 根据等差数列带入算出总共分多少次、最后一次分多少颗、每个人分别得到哪几次分的糖。
    */
  public int[] distributeCandies(int candies, int num_people) {
    int n = num_people;
    // how many people received complete gifts
    int p = (int)(Math.sqrt(2 * candies + 0.25) - 0.5);
    int remaining = (int)(candies - (p + 1) * p * 0.5);
    int rows = p / n, cols = p % n;

    int[] d = new int[n];
    for(int i = 0; i < n; ++i) {
      // complete rows
      d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
      // cols in the last row
      if (i < cols) d[i] += i + 1 + rows * n;
    }
    // remaining candies        
    d[cols] += remaining;
    return d;
  }
}
```
