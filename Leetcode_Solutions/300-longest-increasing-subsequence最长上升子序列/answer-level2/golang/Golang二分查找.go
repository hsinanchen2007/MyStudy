### 解题思路
![image.png](https://pic.leetcode-cn.com/f80cb35dd5a359be2a6b6daebe4a70e346c9373e93c4326201771b104e5b08e2-image.png)

新的数字通过二分搜索在heaps中寻找：
1.找到了heaps中比当前数字大且序号最靠前的数字（pos=-1,pos有值），那么直接覆盖这个数字
2.找不到（pos == len(heaps)），那么在heaps中再添加一个数字

最终的结果就是len(heaps)
### 代码

```golang
func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    heaps := []int{nums[0]}
    for i := 1; i < len(nums); i ++ {
        pos := binarySearch(heaps,0,len(heaps)-1,nums[i])
        if pos == -1 {
            heaps[0] = nums[i]
        }else if pos == len(heaps) {
            heaps = append(heaps,nums[i])
        }else {
            heaps[pos] = nums[i]
        }
    }
    return len(heaps)
}

func binarySearch(nums []int,l,r int,target int) int {
    for {
        if l > r {
            break
        }
        mid := l + (r-l) >> 1
        if nums[mid] < target {
            l = mid+1
        }else {
            r = mid-1
        }
    }
    return l
}
```