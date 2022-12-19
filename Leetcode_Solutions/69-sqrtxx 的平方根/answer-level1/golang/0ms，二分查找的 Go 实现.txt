
![image.png](https://pic.leetcode-cn.com/6a5ea918e769b7fb272e5d7ec2b626ab8ee6aa630c387473f7782306c1f94fc0-image.png)

顺序查找，定位平方根（24ms，2.2 MB）
```
func mySqrt(x int) int {
    // 顺序查找，定位平方根
    for i:=0; i<=x; i++ {
        if i*i > x {
            return i-1
        }
    }
    return x
}
```

二分查找，定位平方根（0ms，2.2 MB）
```
func mySqrt(x int) int {
    // 二分查找，定位平方根
    i,j := 1,x
    for i<=j {
        mid := (i+j)/2
        if mid*mid > x {        // 去左区间找
            j = mid - 1
        } else if mid*mid < x { // 去右区间找
            i = mid + 1
        } else {                // 找到了
            return mid
        }
    }
    return i-1
}
```