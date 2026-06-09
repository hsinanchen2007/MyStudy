递归解法：
资源消耗如下：
![81J{T}Z@QDU9R3_08_0(6~B.png](https://pic.leetcode-cn.com/65e1701e65d96d0568b3948285eb8ca3e9b02ed96a5db8b726920f9a88b496c2-81J%7BT%7DZ@QDU9R3_08_0\(6~B.png)

设原数组长度为n，将偶数位和奇数位分为两部分考虑，分别用两个数组存储，处于第0个位置、第2个位置、第4个位置等奇数个位置一定所存放的数一定是最小的n/2个数，这n/2个位置存放的值可以确定，我们剩下的事就是确定另外处于奇数位上的值，确定奇数位上的值之后，最后将奇数位与偶数位合并即可。
如何确定奇数位上的值：
1. 如果n为偶数，在将偶数位上的值全部取出来之后，剩下的n/2个数的相对位置与奇数位上的值相对位置相同，奇数位的相对位置构成一个n/2规模的子问题，即原序列中前n/2大的数构成一个n/2的子问题。
2. 如果n为奇数，则原始序列的最后一个为偶数位，剩下的n/2（下取整）个数字与原奇数位上的值的的相对位置唯一的不同就在于原奇数位的第一个值，原奇数位的第一个值在剩下的n/2个数字中位于最后一个，其他的相对位置关系相同。
运行时间复杂度分析：排序只需要排一次就行了，与递归无关：O(*n*lg*n*), 递归中奇数位与偶数位合并O(*n*)。
递归时间复杂度：T(n) = T(n/2) + O(*n*) = O(*n*)
故总的时间复杂度为：O(*n*lg*n*)+T(n) = O(*n*lg*n*)
```
class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        deck.sort()
        def f(deck):
            deckLen = len(deck)
            if deckLen<2:
                return deck
            listA = []
            if deckLen%2==1:
                listA = deck[:deckLen//2+1]
                listB = f(deck[deckLen//2+1:])
                listB.insert(0, listB.pop())
            else:
                listA = deck[:deckLen//2]
                listB = f(deck[deckLen//2:])
            result = []
            for i in range(deckLen//2):
                result.append(listA[i])
                result.append(listB[i])
            if len(listA) >deckLen//2:
                result.append(listA[-1])
            return result
        return f(deck)
```
