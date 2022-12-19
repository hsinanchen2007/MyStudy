# 解法一:二分查找

 - 定义 left:=0 right:=len(nums) 用来确定数组的 mid
 - 因为nums是有序数组，如果mid下标的值和mid不相同就在左边查找
 - 如果 nums[mid]==mid ，说明左边是连续的有序数组，缺失的数字就在右边查找
 - left 需要向上取整+1

--执行用时：20 ms	--消耗内存：6 MB
```go
func missingNumber(nums []int) int {
    left:=0
    right:=len(nums)
    for left<right{
        mid:=(left+right)>>1
        if nums[mid]!=mid{
        //nums是有序数组，如果mid和数字不相同就在左边查找
            right=mid
        }else{
        //如果mid和数字相同，说明左边是连续的有序数组
        //缺失的数字就在右边查找，left向上取整+1
            left=mid+1
        }
    }
    return left
}
```
---
# 解法二:异或
- ^= 位逻辑异或赋值，是一个复合赋值运算符
- 异或就是两个数的二进制形式，按位对比，相同则取0。
 	- 0^0→0 ,  0^1→1 ,  1^0→1 ,  1^1→0
 	- 任何数与0异或等于它本身，即a^0=a
 	- 一个数与自己异或结果为0，即a^a=0
- 令0~n的数与nums中的数异或，运算中除了缺失值只出现一次外，其他数都出现两次等同于与自身异或。
 
--执行用时：16 ms --内存消耗：6 MB

```go
func missingNumber(nums []int) int {
    var count=len(nums)
    for i,v:=range nums{
        count^=i^v
    }
    return count
}
```

---
# 解法三:总和的差值

 1. 计算当数组不缺数字时的总和 count  
 2. count减去该数组nums的总和    
 3. 得到的差值即是缺失的数字

--执行用时：20 ms --内存消耗：6 MB
```go
func missingNumber(nums []int) int {
    n:=len(nums)
    count:=(n+n*n) >> 1
    for _,v:=range nums{
        count-=v
    }
    return count
}
```

---
# 解法四:记录数字

 1. 利用数组中数字与数组的索引相同 
 2. 申请一个长度为 len(nums)+1 的 bool 数组 flag
 3. 遍历 nums 数组并记录数字在 flag 数组中对应的索引的值为 true 
 4. 再遍历一次 flag 数组 ，得到其中值为false的索引即为缺失的数字

--执行用时：28 ms --内存消耗：5.9 MB
```go
func missingNumber(nums []int) int {
    flag:=make([]bool,len(nums)+1)
    for _,v:=range nums{
        flag[v]=true
    }
    for i,v:=range flag{
        if v==false{
            return i
        }
    }
    return 0
}
```
---