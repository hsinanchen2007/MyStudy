### 解题思路
此处撰写解题思路
需要注意在python中deepcopy才会改变内存地址
### 代码

```python3
import copy
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def change_to_list(data):
            re=[]
            re.append(data)
            return re
        def all_add_data(ans_array,data):
            data_tmp=new = copy.deepcopy(ans_array)
            m=len(ans_array)
            for i in range(m):
                ans_array[i].append(data)
            data_tmp =data_tmp+ ans_array 
            print(data_tmp) 
            return data_tmp
        ans=[[]]
        print(ans)
        for i in range (0,len(nums)):
            ans=all_add_data(ans,nums[i])
            #print(ans)
        #ans.append([])
        return ans

```