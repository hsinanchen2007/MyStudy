### 解题思路
动态规划常用思路，假设第i本书为最后一本，则dp[i]表示以第i本书为最后一本的当前书架的最低高度。
第i本书有两种方法，加入当前层数能够放下第i本书，则第i本书可以
1）放在当前层
2）放到下一层，同时可以尝试着将第i-1本书也放到下一层（如果能放下）此时书架的高度为dp[i-2] + max(books[i - 1][1], books[i][1]，将i-2本书也放到下一层（如果能放下）此时书架的高度为dp[i-2] + max(books[i - 1][1], books[i - 2][1], books[i][1]……，直到下一层放不下。
其实第二种情况已经包含了第一种情况，即假如第二层能包含第i本到第1本所有的书，那么所有的书都放到了一层，相当于将第i本书加入到当前层。所以，下面只对第二种情况进行讨论。
下面结合代码来说解题思路：
设数组dp[i]表示以第i本书为最后一本的当前书架的最小高度，i从0开始，为了和books数组契合。
```java
dp[0] = books[0][1];  // 只有第一本书
```
下面需要一个双层循环，外层循环表示以第i本书为最后一本书，内层循环则尝试着将第i本书和第i-1，i-2……本书放到下一层，直到放不下，则`dp[i] = Math.min(dp[i], dp[j - 1] + height)`。
```java
for (int i = 1; i < num; i++) {  // 从第二本开始计算
    int height = books[i][1];    // height表示第i本书到i-1，i-2……本书的最大高度，一层书架的高度取决于最高的那本书
    int weight = books[i][0];    // weight则记录i-1，i-2……本书的总宽度，以此来判断能不能放下第i-n本书
    dp[i] = dp[i - 1] + books[i][1];  // 初始假设第i本书单独放到下一层
    for (int j = i - 1; j >= 0; j--) {
        height = Math.max(height, books[j][1]);
        weight = weight + books[j][0];
        if (weight > shelf_width) {    // 当前书太宽（厚），放不下，跳出循环
            break;
        }
        if (j == 0) {                 // 第i本到第0本书，所有的书都放到一层
            dp[i] = Math.min(dp[i], height);
        } else {
            // dp[j - 1] + height解释：
            // height表示第i本书到第j本书最大的高度，dp[j - 1]表示以第j-1本书为最后一本书，当前书架最小的高度
            dp[i] = Math.min(dp[i], dp[j - 1] + height);
        }
        
    }
}
```

### 代码

```java
class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int num = books.length;
        if (num == 1) {
            return books[0][1];
        }
        int[] dp = new int[num];
        dp[0] = books[0][1];
        for (int i = 1; i < num; i++) {
            int height = books[i][1];
            int weight = books[i][0];
            dp[i] = dp[i - 1] + books[i][1];
            for (int j = i - 1; j >= 0; j--) {
                height = Math.max(height, books[j][1]);
                weight = weight + books[j][0];
                if (weight > shelf_width) {
                    break;
                }
                if (j == 0) {
                    dp[i] = Math.min(dp[i], height);
                } else {
                    dp[i] = Math.min(dp[i], dp[j - 1] + height);
                }
                
            }
        }
        return dp[num - 1];
    }
}
```