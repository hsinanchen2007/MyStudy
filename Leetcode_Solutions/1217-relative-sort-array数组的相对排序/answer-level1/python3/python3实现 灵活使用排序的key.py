class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        max_num = 1001  #题目最大的输入是1000
        arr2_dict = {key:idx for idx,key in enumerate(arr2) }   #创建arr2的 index字典，用于排序做key，如果key不在字典中，用max_num + x作key可以实现 排序，并且不存在数 在 存在数的右边
        arr1.sort(key=lambda  x:arr2_dict[x] if x in arr2_dict else max_num +x)
        return arr1