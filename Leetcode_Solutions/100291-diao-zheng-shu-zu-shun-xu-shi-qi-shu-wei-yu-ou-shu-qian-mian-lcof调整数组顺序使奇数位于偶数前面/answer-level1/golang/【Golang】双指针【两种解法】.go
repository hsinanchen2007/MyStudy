# 解法一：快慢双指针

**解题思路：**
**让j先走，如果nums[j]为奇数则与nums[i]进行交换并增加i的索引，循环直到j到达数组尾部，退出循环返回结果。**

--执行时间:28 ms    --内存消耗:6 MB

```go
func exchange(nums []int) []int {
    i:=0
    j:=0
    for j<len(nums){
        if nums[j]%2!=0{
            nums[i],nums[j]=nums[j],nums[i]
            i++
        }
        j++
    }
    return nums
}
```

---

# 解法二：头尾双指针

**解题思路：**
**从头部和尾部同时出发，如果满足交换条件则交换**
**不满足则判断头部位置的数值是否为奇数，为奇数：head++**
**再判断尾部位置的数值是否是偶数，为偶数：tail--**
**指针相遇则退出循环，返回结果**

--执行时间:24 ms    --内存消耗:6.2 MB

```go
func exchange(nums []int) []int {
    head:=0
    tail:=len(nums)-1
    for head<tail{
        if nums[head]%2==0 && nums[tail]%2!=0{
            nums[head],nums[tail]=nums[tail],nums[head]
            head++
            tail--
        }else{
            if nums[tail]%2==0{
                tail--
            }
            if nums[head]%2!=0{
                head++
            }
        }
        
    }
    return nums
}
```