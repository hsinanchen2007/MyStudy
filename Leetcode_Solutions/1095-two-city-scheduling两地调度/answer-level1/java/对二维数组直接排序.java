### 解题思路
计算出A-B地费用的差值，进行排序，前N个人去A地，h其他人去B地，因为差值的前N项如果是小于0，说明去A地的费用比去B地的费用低，如果有大于0的值，那也比N项之后的值更小，说明去A地花费的比去B地的多一些，但是不如后N项多的多，为了使N个人去A地，只好让他们去A地
原来的一个思路是将费用差存在一个数组里，而且作为一个hashmap的键值，对应的value是该费用差对应的人i，但是这样有一个问题，有可能费用差存在一样的情况，即使可能性非常小，也是有可能存在的，因此不可以这么做

### 代码

```java
class Solution {
    public int twoCitySchedCost(int[][] costs) {
         Arrays.sort(costs, new Comparator<int[]>() {
          @Override
          public int compare(int[] o1, int[] o2) {
              return o1[0] - o1[1] - (o2[0] - o2[1]);
          }
      });

      int total = 0;
      int n = costs.length / 2;
      // To optimize the company expenses,
      // send the first n persons to the city A
      // and the others to the city B
      for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
      return total;
    }
}
```