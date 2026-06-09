试图只遍历一次列表A。
```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        # return [e for e in A if e % 2 == 0] + [e for e in A if e % 2 == 1] #虽然只用了一行，但遍历了两次A
        return sorted(A, key=lambda x: x % 2 == 1) # 不知道sorted内部是怎么再现的，但这个题目本质是一个排序题，所以可以用内置排序函数来解
        
        # res = []
        # for x in A:
        #     if x % 2 == 0:
        #         res.insert(0, x)
        #     else:
        #         res.append(x)
        # return res
        
        # a, b = [], []
        # for x in A:
        #     if x % 2 == 0:
        #         a.append(x)
        #     else:
        #         b.append(x)
        # return a + b
```