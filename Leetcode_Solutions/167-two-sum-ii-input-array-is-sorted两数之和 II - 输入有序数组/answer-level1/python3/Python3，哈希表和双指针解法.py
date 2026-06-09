
```python []
#解法1：同样利用哈希表，相同的代码，可以直接解决，只需要修改返回的索引值
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}  #初始化一个哈希表
        for i,num in enumerate(nums): #遍历每一个数字
            if target - num in d:       #判断 target-num 是否已经在哈下表d中
                return d[target-num]+1,i+1  #如果在，则直接返回两个索引值
            else: #如果不在则
                d[num] = i  #将当前 num->index 映射关系添加进哈希表d中

##解法2：双指针解法
##可以利用数组有序特点，使用两个指针start,end,分别指向首位，然后不断中间移动 
def twoSum(self, nums: List[int], target: int) -> List[int]:
        start , end = 0 , len(nums) – 1 #初始化指针start,end分别指向首尾
        while start != end:  #当首尾指针没有相遇的时候
            sum = nums[start] + nums[end] #计算两数之和
            if sum > target:    #如果太大，则
                end-=1            #将end 左移
            elif sum < target:  #如果太小，则
                start+=1          #将start右移 
            else: #如果刚好等于，则
                return [start+1 , end+1] #直接返回

```

