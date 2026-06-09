1、依据题意分析，对角线遍历，每次都是从矩阵的边界上开始，到另一个边界
1  2  3
4  5  6
7  8  9
如上矩阵，上边界为 2 3 6 9，就是第一行，最后一列
下边界为4,7,8,9 第一列，最后一行

2、按照遍历顺序，从0开始，偶数次是从上到下，奇数次是从下到上。遍历到末尾即可

源码如下：初学python，比较丑，见谅
def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        
        row = len(matrix)
        if row == 0:
            return []

        col = len(matrix[0])
        output = [matrix[0][0]]

        # edge_list 获取上下边界节点
        top_list = [(0, j) for j in range(1, col)] + [(i, col - 1) for i in range(1, row)]
        end_list = [(i, 0) for i in range(1, row)] + [(row - 1, j) for j in range(1, col)]

        k = 0
        flag = True
        #开始遍历边界节点，区分奇数和偶数次
        for k in range(len(top_list)):
            if k % 2 == 0:
                s_rr, s_cc = top_list[k]
                e_rr, e_cc = end_list[k]
                flag = True
            else:
                s_rr, s_cc = end_list[k]
                e_rr, e_cc = top_list[k]
                flag = False

            # get output
            if flag:
                while s_rr < e_rr + 1 and s_cc > e_cc - 1:
                    output.append(matrix[s_rr][s_cc])
                    s_rr += 1
                    s_cc -= 1
            else:
                while s_rr > e_rr - 1 and s_cc < e_cc + 1:
                    output.append(matrix[s_rr][s_cc])
                    s_rr -= 1
                    s_cc += 1

        return output
