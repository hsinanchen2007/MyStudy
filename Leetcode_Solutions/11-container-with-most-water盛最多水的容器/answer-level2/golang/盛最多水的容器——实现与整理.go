
![image.png](https://pic.leetcode-cn.com/b15432b33a5cfd41c667983bc9cf4df85940c9f6cc6353f62afcbe276ef0bac3-image.png)


## 解题思考

```go
//    输入: [1,8,6,2,5,4,8,3,7]
//    输出: 49
// 输入数组长度至少为2

// 思考：
// 最粗暴的解法很简单：（枚举的思想） 两层循环i, j . ，容器容量= （j-i）* min(height[i], height[j]), max记录最大容量，每次遇更大则更新
// 显然这种思路有很多优化的地方，时间复杂度O(n*n)

// 寻找规律： 矩形面积 = 长 × 宽。 由于 题中的长为下标之差，而下标之差和高度之差不同，
// 高度之差不遍历数组是不知道的，长度却是根据数组本身的长度就可以确定的。
// 我们要寻找最大面积，则先把长度设为最大，而后逐渐将长方形的两边（选矮的那边）往内缩，这样，长度递减，如果高度还变矮了就不用计算，高度变高才需要计算面积
// 这种思路称之为“两边（双指针）向内夹逼”
```

## 解法一： 粗暴枚举

```go
// 粗暴枚举
// 时间O(N2),空间O(1)
//50/50 cases passed (392 ms)
//Your runtime beats 26.83 % of golang submissions
//Your memory usage beats 65.35 % of golang submissions (5.6 MB)
func Sol_1_1(height []int) int {
	var maxArea int
	for i:=0; i<len(height)-1; i++ {
		for j:=i+1; j<len(height); j++ {
			maxArea = max(maxArea, (j-i)*min(height[i],height[j]))
		}
	}
	return maxArea
}

// go内置只有浮点型的比较函数，为避免整形转浮点的开销，自己写min/max
func min(a, b int) int {
	if a<=b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a>=b {
		return a
	}
	return b
}

```

## 解法二： 两端向内夹逼
```go
// 向内夹逼
// 时间O(N)
//50/50 cases passed (12 ms)
//Your runtime beats 97.9 % of golang submissions
//Your memory usage beats 65.79 % of golang submissions (5.6 MB)
func Sol_1_2(height []int) int {
	maxArea, l, r := 0, 0, len(height)-1
	for l < r {  // i为左侧指针（右移）， j为右侧指针（左移）。当两个指针相遇就停止
		if height[l] < height[r] {
			maxArea = max(maxArea, (r-l)*height[l])
			l++
		} else {
			maxArea = max(maxArea, (r-l)*height[r])
			r--
		}
	}

	return maxArea
}

// 双指针法，两端向内夹逼。 要使面积增大，则在长度缩小的时候，高必须增大，不然面积不可能更大
// 优化当矮边向内移动结果更矮时不需计算面积的情况
func Sol_1_3(height []int) int {
    l, r, maxArea := 0, len(height)-1, 0
    for l<r {   // 左指针与右指针相遇则停止
        if height[l] < height[r] {
            // 优化当矮边向内移动结果更矮时不需计算面积的情况
            if l != 0 && height[l] < height[l-1] {
                l++
                continue
            }
            maxArea = max(maxArea, (r-l)*height[l])
            l++
        } else {
            // 优化当矮边向内移动结果更矮时不需计算面积的情况
            if r != len(height)-1 && height[r] < height[r+1] {
                r--
                continue
            }
            maxArea = max(maxArea, (r-l)*height[r])
            r--
        }
    }
    return maxArea
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}
```

## 优秀题解

- 双指针法（向内夹逼）证明：<https://leetcode-cn.com/problems/container-with-most-water/solution/shuang-zhi-zhen-fa-zheng-que-xing-zheng-ming-by-r3/>
- 图解： <https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/>
