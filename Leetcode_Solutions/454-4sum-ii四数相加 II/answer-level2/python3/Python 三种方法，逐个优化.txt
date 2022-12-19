**一、暴力法（超时）**
最直观的方法就是逐个遍历
```
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        hash_set = set()
        for ia in range(len(A)):
            for ib in range(len(B)):
                for ic in range(len(C)):
                    for j in range(len(D)):
                        if A[ia] + B[ib] + C[ic] + D[j] == 0:
                            hash_set.add((ia, ib, ic, j))
        return len(hash_set)
```
一般情况下，这种方法的时间复杂度是O(A×B×C×D)，ABCD分别表示四个列表中的元素个数；题目假设四个列表的长度均为N，则时间复杂度为O(N^4)，肯定会超时。


**二、优化的暴力法（超时）**
使用暴力法时第一个超时的测试样例是第20个，第20个样例中ABCD都是好多0组成的：
A = [0,0,0,0,0,0,......]
B = [0,0,0,0,0,0,......]
C = [0,0,0,0,0,0,......]
D = [0,0,0,0,0,0,......]
这是因为对于这些重复的元素，我们仍然进行了重复遍历，其实是不必要的。通过对每个列表构建哈希表，可以避免重复元素的遍历，哈希表的键是列表中的不重复元素，值是该元素在该列表中出现的次数。
    假设A = [1,1,2,3,3,3,3]，我们对A构建的哈希表应该是{1:2, 2:1, 3:4}
    然后对每个哈希表的键进行暴力组合，如果其和为0，则将对应的值相乘，最后相加即可得结果。
```
import collections
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        hash_a = collections.defaultdict(int)
        for i in A:
            hash_a[i] += 1
        hash_b = collections.defaultdict(int)
        for i in B:
            hash_b[i] += 1
        hash_c = collections.defaultdict(int)
        for i in C:
            hash_c[i] += 1
        hash_d = collections.defaultdict(int)
        for i in D:
            hash_d[i] += 1
        
        cnt = 0
        for ka, va in hash_a.items():
            for kb, vb in hash_b.items():
                for kc, vc in hash_c.items():
                    for kd, vd in hash_d.items():
                        if ka + kb + kc + kd == 0:
                            cnt += (va*vb*vc*vd)
        return cnt
```
这个算法是我们在暴力法的基础上，针对重复元素很多的情况下进行的优化。我们构建四个哈希表的时间消耗为O(4N)，假设A、B、C、D中分别有a、b、c、d个不重复元素，则暴力组合的时间消耗为O(a×b×c×d)，这样算下来，整体的时间消耗为O(4N+a×b×c×d)。但是，我们知道a、b、c、d的值是可变的，这导致算法很不稳定。
- 在最好的情况下，即A中的所有元素都是重复的（a=b=c=d=1），BCD也都是重复的，此时时间复杂度为O(4N)→O(N)；
- 在最坏情况下，即列表没有重复元素时（a=b=c=d=N），优化的暴力法时间复杂度仍然为O(N^4)，这种方法仍然会超时。


**三、哈希表/分治**
我们假设从A、B、C、D中分别取了e1,e2,e3,e4，由题意可知，目标就是找到所有满足式（1）的组合数量。
    e1 + e2 + e3 + e4 = 0 （1）
式（1）可以化为
    e1 + e2 = -e3 - e4  （2）
由于加法的结合律，所以式（2）中的任意两个元素都可以互相交换（但是要注意变号），比如可以换成
    e1 + e3 = -e2 - e4
但是无论如何改变元素的位置，我们的要求都是一样的，即等号左边应该等于等号右边。以此结论为基础，我们不妨令e1 + e2 = target，再找到满足 -e3 - e4 = target 的e3、e4即可。换言之，我们将一个大问题分成了两个子问题。

算法思路为：
1. 暴力求解A和B的所有可能的e1+e2的值，将其存到哈希表里，哈希表的键为e1+e2，值为e1+e2出现的次数。
    假设A=[1,2],B=[1,2]，我们嵌套地遍历A和B，应该有1+1=2,1+2=3,1+2=3,2+2=4，那么构建的哈希表应该是{2:1, 3:2, 4:1}
2. 暴力求解C和D的所有可能的-e3-e4的值，与哈希表的键进行对比，如果该值在哈希表的键中，那么说明e3和e4有解，解的数量是键的值，我们将这个值添加到一个新的list中。
    仍以第1.步的例子为例，假设C=[-1,-3],D=[-2,-1]，我们嵌套地遍历C和D，应该有-(-1)-(-2)=3,-(-1)-(-1)=2,-(-3)-(-2)=5,-(-3)-(-1)=4；
    对于-(-1)-(-2)=3，哈希表中键3的值为2，此时list=[2]
    对于-(-1)-(-1)=2，哈希表中键2的值为1，此时list=[2,1]
    对于-(-3)-(-2)=5，哈希表中没有键5，此时list=[2,1]
    对于-(-3)-(-1)=4，哈希表中键4的值为1，此时list=[2,1,4]
3. 对list求和，即为答案
下面贴代码
```
import collections
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        hash_map = collections.defaultdict(int)
        result = []
        
        for a in A:
            for b in B:
                hash_map[a+b] += 1
        
        for c in C:
            for d in D:
                if -c-d in hash_map:
                    result.append(hash_map[-c-d])
                    
        return sum(result)
```
这种方法的时间复杂度是O(N×N+N×N)→O(N²)，显然比暴力法的O(N^4)快了不少，而且与优化的暴力法相比非常稳定。但是如果四个列表中都存在大量重复元素，那么优化的暴力算法可能会比这种方法更好。