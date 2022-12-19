```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        # 1. brute force wiht extra space. O(n*n)
        # ans, _ = [], arr1.sort()
        # for num in arr2:
        #     ans.extend([num]*arr1.count(num))
        # for num in arr1:
        #     if num not in arr2:
        #         ans.append(num)
        # return ans
            
        # 2. using collections.Counter(). O(n*logN)
        # ans, c = [], collections.Counter(arr1)
        # for num in arr2:
        #     ans.extend([num]*c.pop(num))
        # for k, v in sorted(c.items()):
        #     ans.extend([k]*v)
        # return ans
        
        # 3. 类似于方法二，但更简洁的代码 O(n*logN)
        # dic = {num: index for index, num in enumerate(arr2)}
        # return sorted(arr1, key=lambda num: (dic[num] if num in dic else float('inf'), num))        
        
        # 4. 还有这样的神操作 O(n*logN)
        return sorted(arr1, key=(arr2+sorted(set(arr1)-set(arr2))).index)
        
        # 5. 有没有 O(n)的？           
```
