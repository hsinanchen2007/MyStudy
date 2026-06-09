### 解题思路
对第一个点求得它到其他3个点的向量
一共要经过这么几关判断：
1、如果向量之中有相同的，FALSE
2、向量之间没有相互垂直的，FALSE
3、垂直向量的长度应该相同，否则FALSE
4、垂直向量的和应该等于剩下那个向量，否则FALSE


### 代码

```python3
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        #这题好像不难啊，为什么是中等（警觉）
        #哦这个正方形可能是歪的
        #我应该先找到向量 
        arr1 = [p2[i] - p1[i] for i in range(2)]
        arr2 = [p3[i] - p1[i] for i in range(2)]
        arr3 = [p4[i] - p1[i] for i in range(2)]
        if arr1 == arr2 or arr2 == arr3 or arr1 == arr3:
            return False
        def mul(arr1,arr2):
            if arr1[0] * arr2[0] + arr1[1] * arr2[1] == 0:
                if arr1[0] ** 2 + arr1[1] ** 2 == arr2[0] ** 2 + arr2[1] ** 2:
                    return True
            else:
                return False
        def add(arr1,arr2,arr3):
            if [arr1[i] + arr2[i] for i in range(2)] == arr3:
                return True
            else:
                return False
        if mul(arr1,arr2):
            if add(arr1,arr2,arr3):
                return True
        if mul(arr1,arr3):
            if add(arr1,arr3,arr2):
                return True
        if mul(arr2,arr3):
            if add(arr2,arr3,arr1):
                return True
        return False


```