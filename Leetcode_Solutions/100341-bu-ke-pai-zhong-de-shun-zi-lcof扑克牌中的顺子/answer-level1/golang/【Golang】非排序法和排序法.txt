# 解题思路
- **题目要求输入的扑克牌是顺子，则有以下几种情况：**
 	- 除了大小王皆为0表示，如果有其他牌（其他数字）重复，肯定不是顺子。 
 	- 如果不存在大小王0
 	 	- 又因扑克牌为5张，数字排序后是一个等差序列，差值为1，则最大值最小值之差必定为4 
 	- 如果存在大小王0，
 	 	- 则最大值最小值之差不大于4 max-min<=4 即为顺子

- **因此可知：**
 	- 需要的变量有：最大值，最小值，大小王的数量 
 	- 解题方法有：排序法、非排序法
 ---
 # 解法一：非排序法（需要记录大小王0）
 
--执行用时：0 ms --内存消耗：2.1 MB
```go
func isStraight(nums []int) bool {
    //time 记录扑克牌0~13的出现情况
    time := make(map[int]bool,14)
    max,min:=0,14
    zero:=0
    for i:=0;i<5;i++{
     	//如果数字是大小王0
        if nums[i]==0{
            zero++
            //continue 不进行下面的代码，进入下一次循环
            continue
        }
        //如果扑克牌（非0数字）重复，不是顺子
        if time[nums[i]]{
            return false
        }
        max=Max(nums[i],max)
        min=Min(nums[i],min)
        //记录出现过的数字
        time[nums[i]]=true
    }
    //是否存在大小王，返回判断结果
    if zero==0{
        return (max-min)==4
    }
    return max-min<=4
}

//Max 获取相对最大值
func Max(a,b int)int{
    if a>b{
        return a
    }
    return b
}

//Min 获取相对最小值
func Min(a,b int)int{
    if a>b{
        return b
    }
    return a
}
```
---
# 解法二：排序法（不需要记录大小王0）
--执行用时：0 ms --内存消耗：2 MB

```go
func isStraight(nums []int) bool {
    //nums 转化为递增序列
    sort.Ints(nums)
    //记录每个数字之间差值的和
    sub:=0
    for i:=0;i<4;i++{
        if nums[i]==0{
         	//continue 不进行下面的代码，进入下一次循环
            continue
        }
        //如果扑克牌（非0数字）重复，不是顺子
        if nums[i]==nums[i+1]{
            return false
        }
        //差值记录
        sub+=nums[i+1]-nums[i]
    }
    //总的差值小于5（或sub<=4）则为顺子
    return sub<5
}
```