class Solution:
    def uniqueOccurrences(self, arr:List[int]) -> bool:
        a = list(set(arr))  # 将字符串转换为列表
        b = []
        for i in a:
            counts = arr.count(i)  # 找到i 的数量
            b.append(counts)
        return len(set(b)) == len(b)