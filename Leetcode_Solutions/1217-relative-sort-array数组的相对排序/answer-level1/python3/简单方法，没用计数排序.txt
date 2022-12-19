class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        #借助2个空列表来进行操作；
        res = []
        left = []
        for i in arr2:
            for j in arr1:
            #按照arr2的顺序，依次放入；
                if j == i:
                    res.append(j)
        #这里可以优化一下 ，找到不在arr2中的元素；
        for m in arr2:
            while m in arr1:
                arr1.remove(m)
        
        
        res = res+ sorted(arr1)
        
        return res