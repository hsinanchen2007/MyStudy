class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        db_list = [[0 for j in range(m)] for i in range(n)]
        for i in indices:
            db_list[i[0]] = list(map(lambda x: x + 1, db_list[i[0]]))
            for j in range(n):
                db_list[j][i[1]] += 1
        count = 0
        for i in db_list:
            for j in i:
                if j % 2 == 1:
                    count += 1
        return count

最正常的写法，走流程:
生成二元列表
遍历indices
一整行＋1
一整列 +1
遍历二元列表的元素
计算变量count,元素奇数count+1
返回count