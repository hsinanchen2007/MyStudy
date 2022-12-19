### 解题思路
1. 首先，对原列表进行排序，因为由输出可以看出最后结果集中的每个结果都是有序的.
2. 求出原列表的长度n.
3. 先不考虑结果重复问题，让第一个元素在[0,n-3)遍历且第二个元素在[i+1,n-2)之间遍历,现在已经有两层循环了,但四层循环显然不行,因此可以采用双指针法(设第三个元素的索引为L,第四个元素的坐标为R).
    - 初始化L = j + 1, R = n -1，然后开始循环，循环持续的条件为L < R：
    - 当以i,j,L,R为索引的四个元素的值的和之和等于target时，将这四个元素构成的列表追加到待返回的列(fin_list)中,然后继续寻找满足条件的L和R;
    - 若以i,j,L,R为索引的四个元素之和大于target时，说明nums[R]偏大了,R减1并继续寻找;
    - 若以i,j,L,R为索引的四个元素之和小于target时,说明nums[L]偏小了,L加1并继续寻找。
### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        fin_list=[]
        nums.sort()
        length = len(nums)
        for i in range(0,length-3):
            for j in range(i + 1,length-2):
                L = j + 1
                R = length -1
                while L < R:
                    if nums[i] + nums[j] + nums[L] + nums[R] == target:
                        fin_list.append([nums[i],nums[j],nums[L],nums[R]])
                        L += 1
                        R -= 1
                    elif nums[i] + nums[j] + nums[L] + nums[R] > target:
                        R -= 1
                    else:
                        L +=1 
                
        new_list = []
        for item in fin_list:
            if item not in new_list:
                new_list.append(item)
        return new_list
```