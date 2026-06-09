```
由于数组中的数可能有正数也可能有负数所以最大乘积会有以下几种情况：
1.如果数组中的元素全是负数的话，那最大乘积就是三个最大负数相乘
2.如果数组中的元素有正有负最大乘积可能为升序排序后的最后三个数的乘积
或前两个元素的乘积再乘以最后一个元素的乘积
综合上述情况分析可知
只需找出该数组中的最大三个数（maxA,maxB,maxC）和最小两个数(minA,minB)
比较一下maxA*maxB*maxC和minA*minB*maxA
返回二者中的比较大的那一个即可
```
```
func maximumProduct(nums []int) int {
    maxA, maxB, maxC := -1000, -1000, -1000
    minA, minB := 1000, 1000
    for _, v := range nums{
        if v > maxA{
            maxC = maxB
            maxB = maxA
            maxA = v   
        }else if v > maxB{
            maxC = maxB
            maxB = v
        }else if v > maxC{
            maxC = v
        }    
        if v < minA{
            minB = minA
            minA = v
        }else if v < minB{
            minB = v
        }
    }
    max1 := maxA * maxB * maxC
    max2 := minA * minB * maxA
    if max1 > max2{
        return max1
    }
    return max2 
}
```

![image.png](https://pic.leetcode-cn.com/d954fe60c59ad33d7118a32419cbbc0782905bdeaa8cf4e74e460c6bf0d62358-image.png)
