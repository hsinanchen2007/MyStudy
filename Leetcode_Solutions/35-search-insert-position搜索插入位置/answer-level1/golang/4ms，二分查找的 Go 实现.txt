
![image.png](https://pic.leetcode-cn.com/7b4541833de74386a69c107ee58cd22ac26327aecdbe6e7f35be3df6bb4f4c78-image.png)

没什么好说的，考察二分查找。

按理说 Go 的速度不止 4ms，我看 Java 都能跑到 1ms，这个用时有些奇怪。

代码：
```
func searchInsert(nums []int, target int) int {
    l,r := 0,len(nums)-1
    for l<=r {
        mid := (l+r)/2
        if target > nums[mid] { // 去右区间找
            l = mid + 1
        } else if target < nums[mid] { // 去左区间找
            r = mid - 1
        } else { // 找到了
            return mid
        }
    }
    return l
}
```