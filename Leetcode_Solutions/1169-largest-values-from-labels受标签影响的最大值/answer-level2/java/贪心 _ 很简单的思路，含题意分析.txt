#### 解题思路：



-  第一点要求 `|S| <= num_wanted` 是说选择的总数不能超过 `num_wanted`  
- 第二点要求是说同一个标签下的项，选择的数量不能超过 `use_limit`
- 理解了这两点就很清楚了，这是一个简单的贪心策略能够解决的问题，只需要将其按照价值排列，优先选择价值高的即可。
>
下面提供一种直接实现的思路。

- 执行用时 :`107 ms`，在所有 `Java` 提交中击败了 `44.00%` 的用户
- 存消耗 :`49.9 MB`，在所有 `Java` 提交中击败了 `100.00%` 的用户
#### 代码：
```java [-Java]
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        // 边界情况
        if (num_wanted == 0 || use_limit == 0) {
            return 0;
        }
        int len = values.length;
        int[][] pairs = new int[len][2];
        for(int i = 0; i < len; i++){
            pairs[i][0] = values[i];
            pairs[i][1] = labels[i];
        }
        // 按照 value 降序排列
        Arrays.sort(pairs,(o1,o2)-> o2[0]-o1[0]);
        // 记录当前label选择的数量
        int[] numLabel = new int[20001];  // max{label} = 20000
        int ans = 0;
        // 记录选择的总数 |S|
        int cnt = 0;
        for(int i = 0; i < len; i++){
            int lab = pairs[i][1];
            if(numLabel[lab] >= use_limit)
                continue;
            ans += pairs[i][0];
            numLabel[lab]++;
            cnt++;
            if(cnt >= num_wanted)
                return ans;
        }
        return ans;
        
    }
}
```

#### 复杂度分析：

时间：$O(NlogN)$ $N = len(values)$

空间：$O(max\{label\})$