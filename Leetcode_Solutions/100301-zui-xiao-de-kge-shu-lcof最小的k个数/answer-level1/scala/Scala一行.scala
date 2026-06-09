### 解题思路

![图片.png](https://pic.leetcode-cn.com/54b40992f8d707f726da7b388faf8345e50949732b747b4c5b9a5603148f01da-%E5%9B%BE%E7%89%87.png)

排个序取前k个就可以了。排序的时间复杂度平均为`O(nlogn)`，取前k个的时间复杂度为`O(k)`。

### 代码

```scala
object Solution {
    def getLeastNumbers(arr: Array[Int], k: Int): Array[Int] = {
        arr.sorted.take(k)
    }
}
```