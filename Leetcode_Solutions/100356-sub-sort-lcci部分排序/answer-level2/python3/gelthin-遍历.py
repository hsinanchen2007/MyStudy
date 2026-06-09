我自己的方法不太好，空间复杂度是 O(1), 但时间复杂度可能大于 O(n)。

思路是：从左往右扫描，每当碰到一个比左边数小的值，就再往左边搜，看其能回退到什么位置，使得此数不再小。
记录下最小的回退位置。从右往左扫描，每当碰到一个比右边数小的值，就再往右边搜，看其能回退到什么位置，使得此数不再小。
记录下最大的回退位置。

这里如果有大量元素都要回退的话，可能复杂度就是 O(n^2).

看了题解 [C++ 两次遍历 O(n)](https://leetcode-cn.com/problems/sub-sort-lcci/solution/c-liang-ci-bian-li-on-by-yuexiwen/), 其方法比较好。

与我所重构的解法不同的是，其先计算出 left_max, 然后把计算 m,n 的过程合并到计算 righ_min 的过程中去了。


使用一个数组记录这个数字是否是正确的位置，isTrue[i] = True 当且仅当：array[i] 比左边的数都大，比右边的数都小。
因此可以在从左往右遍历过程中，记录下来左边最大的数。从右往左遍历过程中，记录下右边最小的数


``` python3 个人的代码不太好
class Solution:
    def subSort(self, array: List[int]) -> List[int]:
        l_a = len(array)
        if l_a <= 1:
            return [-1,-1]
        m, n = l_a-1, 0
        i = 2
        while i <= l_a-1:
            j = i-1
            if array[i]<array[j]:  #这里还可以优化，找到了比前一位小的，可以再往后搜几步，找到更小的，再往回走
                while j-1>=0 and array[i]<array[j-1]:
                    j -= 1
                m = min(m, j)
                if m == 0:  # 后续不可能更小了
                    break
            i += 1

        i = l_a - 2
        while i>=0:
            j = i+1
            if array[i]>array[j]:   #
                while j+1 <= l_a -1 and array[j+1]<array[i]:
                    j += 1
                n = max(n, j)
                if n == l_a-1:  # 后续不可能更大了
                    break 
            i -= 1
        if n==0: #必然是同时的
            return [-1,-1]
        else:
            return [m, n]


class Solution:  # 参考别人解答后重写的解法
    def subSort(self, array: List[int]) -> List[int]:
        l = len(array)
        if l<=1:
            return [-1,-1]
        is_Correct = [True]*l

        left_max = array[0]  # 左边记录到当前的最大值
        i = 1
        while i <= l-1:
            if array[i] < left_max:
                is_Correct[i] = False
            else:
                left_max = max(left_max, array[i])
            i += 1
        
        right_min = array[l-1] # 右边记录当前的最小值
        j = l-2
        while j >= 0:
            if array[j] > right_min:
                is_Correct[j] = False
            else:
                right_min = min(right_min, array[j])
            j -= 1

        m = -1
        i = 0
        while i <= l-1:
            if is_Correct[i] == False:
                m = i
                break
            i += 1
        
        n = -1
        j = l-1
        while j >= 0:
            if is_Correct[j] == False:
                n = j
                break
            j -= 1
            
        return [m, n]



