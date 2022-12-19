
![image.png](https://pic.leetcode-cn.com/58e211d3b0e0492842a2001f027fcecec0605a3646ed399a3d02244e36a21cf9-image.png)

用二分查找寻找 num 的平方根

代码
```
func isPerfectSquare(num int) bool {
    for i,j := 1,num; i<=j; {       // 二分查找平方根
        mid := (i+j) / 2
        if mid*mid > num {          // 去左区间找
            j = mid-1
        } else if mid*mid < num {   // 去右区间找
            i = mid+1
        } else {
            return true
        }
    }
    return false
}
```