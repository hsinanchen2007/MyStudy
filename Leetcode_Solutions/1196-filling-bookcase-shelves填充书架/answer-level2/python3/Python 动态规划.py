![image.png](https://pic.leetcode-cn.com/a2facd3f0a9857a180dfb0d460c09d5fc4c6aceedac26d6eb384f3f3dfdcffa5-image.png)



```
'''
每本书都是按照顺序放的，这个问题可以抽象成把一个数组分裂成子数组
每个子数组中宽度和不超过shelf_width, 求所有分组中的最大值之和
的最小值是多少

dp(i)表示第i本书作为分组最后一个元素时候最小的分组最大值之和

dp(i) = min {
    max(books[i]) + dp(i-1),                # 第i本书自己一组
    max(books[i], books[i-1]) + dp(i-2)     # i, i-1两本书一组
    .......
}


'''

from typing import List
class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        n = len(books)
        dp = [0 for _ in range(n)]
        dp[0] = books[0][1]

        for i in range(1, n):
            dp[i] = books[i][1] + dp[i-1]
            # 依次在分组中加一本书
            j = i-1
            total_width = books[i][0]
            max_h = books[i][1]
            while j >= 0 and total_width + books[j][0] <= shelf_width:
                max_h = max(max_h, books[j][1])
                if j-1 >= 0:
                    dp[i] = min(dp[i], max_h + dp[j-1])
                else:
                    dp[i] = min(dp[i], max_h)

                total_width += books[j][0]
                j -= 1

        return dp[n-1]
```
