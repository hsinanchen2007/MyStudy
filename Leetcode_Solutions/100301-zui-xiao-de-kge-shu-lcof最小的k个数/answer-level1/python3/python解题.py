class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        sorted_list = sorted(arr)    # 对数组进行排序
        a = []   # 设定一个空数组
        
        for i in range(k):
            a.append(sorted_list[i])

        return a