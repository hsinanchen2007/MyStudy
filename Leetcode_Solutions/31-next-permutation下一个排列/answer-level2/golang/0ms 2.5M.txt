![image.png](https://pic.leetcode-cn.com/a600d737b549cf8fa49947acf6f2e99f2d9410c4a6e36ec115a840c22114bbc6-image.png)

### 解题思路
没想到，看的别的题解。
首先是从右往左找第一个相邻的左<右的位置，下一个就要换小的。跟小的交换的是小的右边最接近小的一个（比小的）大的数。
然后交换2个数之后，原先小的位置右边肯定是降序排序的。因为你找小数的时候是找的第一个左<右，因此右边全是左>右。你交换的是与小的最接近的大数，因此从右往左找这个数的时候，这个数位置的右边都比小数小，左边都比小数大了。

### 代码

```golang
func nextPermutation(nums []int)  {
    
    match := -1
    for i:= len(nums)-1;i>0;i--{
        if nums[i]>nums[i-1]{
            match = i-1
            break
        }
    }
    if match == -1{
        reverse(nums,0,len(nums)-1)
        return
    }

    for i:=len(nums)-1;i>match;i--{
        if nums[i]>nums[match]{
            nums[i],nums[match] = nums[match],nums[i]
            reverse(nums,match+1,len(nums)-1)
            return
        }
    }
}

func reverse(nums []int,start,end int){
    for i:=start;i<=(end+start)/2;i++{
        nums[i],nums[end + start-i] = nums[end + start-i],nums[i]
    }
}
```