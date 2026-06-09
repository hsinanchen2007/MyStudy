```
'''
LeetCode 854 相似度为 K 的字符串
Strings A and B are K-similar (for some non-negative integer K)
if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.
Given two anagrams A and B, return the smallest K for which A and B are K-similar.
Example 1:
Input: A = "ab", B = "ba"
Output: 1
Example 2:
Input: A = "abc", B = "bca"
Output: 2
Example 3:
Input: A = "abac", B = "baca"
Output: 2
Example 4:
Input: A = "aabc", B = "abca"
Output: 2
Note:
1 <= A.length == B.length <= 20
A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

题目大意：
如果可以通过将 A 中的两个小写字母精确地交换位置 K 次得到与 B 相等的字符串，我们称字符串 A 和 B 的相似度为 K（K 为非负整数）。
给定两个字母异位词 A 和 B ，返回 A 和 B 的相似度 K 的最小值。

解题思路：
这道题就按照你的代码讲解把，这道题比较难
基于记忆化的递归搜索进行求解
我直接举例子说明吧，看代码注释
核心思想就是通过记忆化，递归交换A当前与B[0]相等的地方至第0位，这样就可以消去一位，直到全部消除就跳出递归
'''
class Solution(object):
    def kSimilarity(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        self.memo = {}
        return self.solve(A, B)

    def solve(self, A, B): # 假设输入是A=aabc B=abca
        diff = [A[i] != B[i] for i in range(len(A))] # 找出对应位置相等的地方，diff=[0,1,1,1],用于消除，因为相等的地方不用考虑
        simplify = lambda S: ''.join(c * d for c, d in zip(S, diff)) # 去除对应位置相等的地方，相等的位置就是0*？消除
        A, B = simplify(A), simplify(B) #第一次消除结果，由于0位置相等，结果为A=abc B=bca
        if not A: return 0 # 递归跳出出口，也即A和B全部消去
        if (A, B) in self.memo: # 交换后和之前一样，返回之前的值就可以了，也相当于没交换，次数ans就不用加
            return self.memo[(A, B)]
        ans = 0x7FFFFFFF
        for i, x in enumerate(A): # 遍历A
            if A[i] == B[0]: # 和B的第一位对比，如果相等
                C = A[1:i] + A[0] + A[i+1:] # 将当前位和第0位交换
                ans = min(ans, self.solve(C, B[1:])) # 交换后A和B的第0位又都一样了，可以直接simplify
        self.memo[(A, B)] = ans + 1 # 他们交换后，记录交换后的状态及其次数
        return ans + 1

if __name__ == "__main__":
    A = "aabc"
    B = "abca"
    s = Solution()
    print(s.kSimilarity(A,B))
```
