### 解题思路
初试指针分别为列表的头和尾，当前值等于目标值，返回，当前值小于目标值，头指针向后（这样会使得当前值慢慢变大，直到合适），当前值大于目标值时亦然。

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        index1=0                #头指针
        index2=len(numbers)-1   #尾指针
        while index1<index2:#循环结束条件，2指针相等时就正好遍历一遍
            if numbers[index1]+numbers[index2]==target:#符合要求，结束
                break
            elif numbers[index1]+numbers[index2]>target:
                index2-=1        #尾指针前移
            else:
                index1+=1        #头指针后移  
        return [index1+1,index2+1] #题设要求序号故+1
```