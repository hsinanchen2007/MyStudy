#### 方法一：贪心

**分析**

我们这样来看这个问题，公司首先将这 $2N$ 个人全都安排飞往 $B$ 市，再选出 $N$ 个人改变它们的行程，让他们飞往 $A$ 市。如果选择改变一个人的行程，那么公司将会额外付出 `price_A - price_B` 的费用，这个费用可正可负。

![bla](https://pic.leetcode-cn.com/Figures/1029/users.png){:width=600}
{:align=center}

因此最优的方案是，选出 `price_A - price_B` 最小的 $N$ 个人，让他们飞往 `A` 市，其余人飞往 `B` 市。

**算法**

- 按照 `price_A - price_B` 从小到大排序；

- 将前 $N$ 个人飞往 `A` 市，其余人飞往 `B` 市，并计算出总费用。

```Python [sol1]
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        # Sort by a gain which company has 
        # by sending a person to city A and not to city B
        costs.sort(key = lambda x : x[0] - x[1])
        
        total = 0
        n = len(costs) // 2
        # To optimize the company expenses,
        # send the first n persons to the city A
        # and the others to the city B
        for i in range(n):
            total += costs[i][0] + costs[i + n][1]
        return total
```

```Java [sol1]
class Solution {
    public int twoCitySchedCost(int[][] costs) {
      // Sort by a gain which company has 
      // by sending a person to city A and not to city B
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

```C++ [sol1]
class Solution {
    public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by a gain which company has 
        // by sending a person to city A and not to city B
        sort(begin(costs), end(costs),
                [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[0] - o1[1] < o2[0] - o2[1]);
        });

        int total = 0;
        int n = costs.size() / 2;
        // To optimize the company expenses,
        // send the first n persons to the city A
        // and the others to the city B
        for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
        return total;
    }
};
```

**复杂度分析**

* 时间复杂度：$O(N)$，需要对 `price_A - price_B` 进行排序。

* 空间复杂度：$O(1)$。