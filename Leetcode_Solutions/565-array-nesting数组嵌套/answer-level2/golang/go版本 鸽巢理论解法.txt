### 解题思路
本题解来嘴公众号**算法和数据结构的峡谷**
整体可以看作是鸽巢理论的变种，或者就是利用的鸽巢理论。当nums[i] = i的时候就不符合题意了，就该跳出了，为什么要将i等于
nums 中的各处的k都试一次呢，因为这里的开始的index不一定从0开始，题目中演示的是从0开始，我们要找到所有的解。

### 代码

```golang
// 鸽巢理论解法。

func arrayNesting(nums []int) int {
    // 设置一个指针
    max := 0
   for i := range nums { // 遍历这个array
         p  := 1 // 设置一个每次的转换次数的初始值
       for nums[i]  != i { 
        // 看题意  A[0], A[5], A[6], A[2]} 当 a[2] == 0的时候就退出了，
        // 0刚好是  a[0] == 5的index，所以只要 nums[i] == i 就该跳出了。
           nums[i],nums[nums[i]] = nums[nums[i]],nums[i]
           p++
       }
       if max < p {
           max = p
       }
   }
   return max
}
```