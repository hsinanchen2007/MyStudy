from typing import List
class Solution:
    class Solution:
        def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
            """
            Do not return anything, modify A in-place instead.
            """
            """
            双指针
            如果从头开始填充会要移动A
            可以直接从末尾开始比较
            把较大的放到A的末尾
            最后把B剩下的直接连接到A的前部分
            """
            index_1, index_2 = m - 1, n - 1
            pivot = len(A) - 1
            if m == 0 or n == 0:
                if m == 0:
                    A = B

                if n == 0:
                    return A
            while index_1 >= 0 and index_2 >= 0:
                if A[index_1] > B[index_2]:
                    # A的值大，把A的值放到A的末尾
                    A[pivot] = A[index_1]
                    pivot -= 1
                    index_1 -= 1
                else:
                    A[pivot] = B[index_2]
                    # B的值更大，把B放到A末尾
                    pivot -= 1
                    index_2 -= 1

            if index_2 >= 0:
                # B中元素还没有放完，放到A的最前端
                index_2 += 1
                A[0:index_2] = B[0:index_2]

            return A