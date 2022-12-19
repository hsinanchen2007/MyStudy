### 解题思路
原地删除问题一般首选覆盖方法。本题使用双指针法，i指针用于遍历数组，j指针用于记录下一个要覆盖的位置，使用cnt记录重复的个数。i，j从1的位置开始，cnt的最小值为1。算法过程如下：

 1. 如果nums[i]==nums[i-1],cnt+1；如果nums[i]!=nums[i-1],说明相邻的两个数据不重复，另cnt=1。
 2. 对于每一次循环，如果cnt<=2,说明没有连续两个以上重复，则将i位置的数覆盖到j位置，同时j++；如果cnt>2,说明已经有两个以上重复，此时j固定，等待下一次(或几次)循环找到不是重复的数，进行覆盖。
 3. 每次循环，i++
 4. 返回j的索引

### 代码

```golang
func removeDuplicates(nums []int) int {
    if len(nums)<=2{
        return len(nums)
    }

    i,j:=1,1
    cnt:=1

    for i<len(nums){  
        if nums[i]==nums[i-1]{
            cnt++
        }else{
            cnt=1
        }

        if cnt<=2{
            
            nums[j]=nums[i]
            j++
        }
        i++       
    }

    return j
}
```