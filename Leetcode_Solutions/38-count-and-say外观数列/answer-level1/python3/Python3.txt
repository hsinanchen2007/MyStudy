### 解题思路
外循环n次
    初始化
    对结果进行内循环遍历
        判断：与temp相等：
                count+1
             与temp不等：
                nums_temp列表中添加count和temp
                重置
返回 列表转str

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
 
        
        nums = [1]                               
        i = 0                                    
        while i < n - 1:                         
            count = 0                            
            temp = nums[0]                       
            nums_temp = []                       
            for num in nums:                     
                if num != temp:                  
                    nums_temp.append(count)      
                    nums_temp.append(temp)       
                    temp = num                   
                    count = 1                    
                else:                            
                    count += 1                   
            nums_temp.append(count)              
            nums_temp.append(temp)               
            nums = nums_temp                     
            i += 1                               
        return "".join('%s' % id for id in nums) 
                                                                  
        

```