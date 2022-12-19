暴力解法：O(n^3) ，因为n最大为500，所以会超时。
观察到i是一个“枢纽”，对于每个点i，遍历其余点到i的距离O(n^2)。

![1.png](https://pic.leetcode-cn.com/0bada2d7484888ccdd1375e7c6a11ef8b3d502783b8dc3fb1c648560d586a692-1.png)


对应的键就是距离值，对应的值就是有多少这样的点

```go
// 查找表 Time: O(n^2), Space: O(n)
func numberOfBoomerangs(points [][]int) int {
   res := 0                           // 记录一共有多少题目所描述的三元组
   for i := 0; i < len(points); i++ { // 遍历枢纽点i
      // 对于每一个points[i]设立一个查找表,key是距离，value是相同距离点的个数
      record := make(map[int]int)        // 记录其余所有点到i的距离出现的频次
      for j := 0; j < len(points); j++ { // 遍历其余所有的点
         if j != i { // 索引j和i不相等，就找到了一个不同的点
            record[dis(points[i], points[j])]++ // 记录这个距离出现的频次
         }
      }
      for _, v := range record { // 遍历距离的查找表record
         if v >= 2 { // 这个距离的频次大于等于2次
            res += v * (v - 1) // 即可以找到这样三元组的可能
         }
      }
   }
   return res
}

// 辅助函数 计算两点之间的距离
func dis(pa, pb []int) int {
   return (pa[0]-pb[0])*(pa[0]-pb[0]) + (pa[1]-pb[1])*(pa[1]-pb[1])
}
```