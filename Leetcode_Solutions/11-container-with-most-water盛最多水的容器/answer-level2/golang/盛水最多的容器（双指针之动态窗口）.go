# 动态窗口

一般基于字符串或数组，都会先定义两个指针，一前一后组成滑动窗口，并计算滑动窗口中的所有元素相关问题（注意以后凡是看到要处理窗口内元素的题型，都可以使用滑动窗口）。
![1c3ee38a3e1246659cc774a0e21a90f2.jpeg](https://pic.leetcode-cn.com/e148bc26da261308f35b8b5fca17c1a44863736a71383c097db34aea433abcef-1c3ee38a3e1246659cc774a0e21a90f2.jpeg)

# 注意事项

我们使用两个指针来控制这个窗口，两个指针的移动是有条件的，也就是在结合具体处理的情况下，考虑清楚什么条件下移动和什么条件下不移动。而且在一次循环判断条件后，只能移动其中一个指针

# 解题

```golang
func maxArea(height []int) int {
    l := 0                  // 第一个元素索引
    r := len(height)-1      // 最后一个元素索引
    max := 0                // 存值

    for {
        if height[l] < height[r] { // 当左边元素的高度值 < 右边元素的高度值，就先开始计算值，然后左边的索引向右移动
            if max < (r-l) * height[l] {
                max = (r-l) * height[l]
            }
            l++
        } else { // 当左边元素的高度值 > 右边元素的高度值，就先开始计算值，然后右边的索引向左移动
            if max < (r-l) * height[r] {
                max = (r-l) * height[r]
            }
            r--
        }

        if l == r { // 当索引值相等就退出循环
            break
        }
    }

    return max
}
```

