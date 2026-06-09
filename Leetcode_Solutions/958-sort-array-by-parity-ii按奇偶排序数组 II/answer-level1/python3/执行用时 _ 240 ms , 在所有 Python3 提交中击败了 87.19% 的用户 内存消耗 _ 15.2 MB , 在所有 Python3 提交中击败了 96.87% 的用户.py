### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        #复制法 给定一个新的数组
        res_list = []
        list1 = []
        list2 = []
        for i in range(len(A)):
            #奇数
            if A[i] %2:
                list1.append(A[i])
            #偶数
            else:
                list2.append(A[i])

        for j in  range(len(list2)):
            res_list.append(list2[j])
            res_list.append(list1[j])
        return res_list

                

```