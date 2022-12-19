
![image.png](https://pic.leetcode-cn.com/f442efe8f1554511ba4552dfb08e266f4a089b490d842a4e42fca229c22c0d14-image.png)
```
func search(nums []int, target int) int {
    if len(nums)==0{
        return -1
    }
    //判断目标值与头节点的大小，如果大则必定在前半段，小则必定是在后半段
    if target==nums[0]{
        return 0
    }
    l := len(nums)
    if target==nums[l-1]{
        return l-1
    }
    if target>nums[0]{
        i :=0
        for i+1<len(nums)-1&&nums[i]<nums[i+1]{
            if target==nums[i+1]{
                return i+1
            }
            i++
        }
        return -1
    }

    if target<nums[0]{
        i:=l-1
        for i-1>=0&&nums[i-1]<nums[i]{
            if target==nums[i-1]{
                return i-1
            }
            i--
        }
        return -1
    }

    return -1
}
```

