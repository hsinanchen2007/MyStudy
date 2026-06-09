### 解题思路
这道题是使用双指针就地删除元素的题目，基本思想就是使用后面的覆盖前面的元素，覆盖方法如下：
i,j为两个指针，i指针记录需要覆盖的下一个位置，同时也可以代表最终数组的长度
j指针向前探索下一个所需的元素
对本题而言：
（1）i先找到第一个要覆盖的位置
（2）nums[j]!=val,则j位置可以覆盖掉i位置，nums[i]=nums[j]，同时i++
 (3) nums[j]==val,则j继续向前探索
[这有一道删除重复元素的题](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)
### 代码

```golang
func removeElement(nums []int, val int) int {
    i:=0
    for ;i<len(nums);i++{
        if nums[i]==val{
            break
        }
    }

    for j:=i+1;j<len(nums);j++{
        if nums[j]!=val{
            nums[i]=nums[j]
            i++
        }
    }
    return i
}
```