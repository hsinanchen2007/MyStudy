### 解题思路
![1.png](https://pic.leetcode-cn.com/4be1693e36935bb82853dba52ddbcca45684cea7cc65691ee0e28ce7cf273b63-1.png)

设定一个sum，用于记录当前和最大的情况，如果当前最大和小于nums[i]，当前和最大值就设为nums[i]，然后统计出整趟遍历下来最大的和最大值，即为所求。

### 代码

```golang
func maxSubArray(nums []int) int {
    if len(nums)==0{    //边界0
        return -2147483648
    }else if len(nums)==1{  //边界1
        return nums[0]
    }
    ans := nums[0] //和最大值的最大值
    sum := nums[0]  //和最大值
    for i:=1;i<len(nums);i++{
        sum+=nums[i]    //之前的和最大值加当前元素
        if sum<nums[i]{ //如果当前的和最大值小于当前元素，和最大值设为当前元素
            sum = nums[i]   
        }
        if ans<sum{     //如果当前和最大值大于和最大值的最大值，就把和最大值的最大值设置为当前和最大值
            ans = sum
        }
    }
    return ans
}
```