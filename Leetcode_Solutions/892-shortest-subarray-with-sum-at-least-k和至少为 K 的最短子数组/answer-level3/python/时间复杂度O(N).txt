1. 由题可初步得出一个思路：采用滚动素组，计算A[i] +...+A[j]的和sum, i <= j，如果sum >= k，则i += 1，sum -= A[i]，然后计算所有可能的 i ~ j 的距离的最小值。
2. 继续思考1的方法，会存在一个问题： A[i] + ...A[a] + ... +A[b] +... +A[j]，i <= a<= b <= j，其中A[a] +...+A[b] < 0，也就是意味着当 i不断右移(i+=1)后到达a位置时，此时必须直接跳到位置b+1, 因为A[b+1] +...+A[j] > A[a]+...+A[b]+..+A[j]，而b~j的距离最短，所以如何记录所有的a~b并且当i右移到a时直接跳到b+1就成为需要解决的。
3. 根据2的思考，可以通过当A[b] < 0时，由b出发找到位置a，然后采用队列记录(a,b)，并在i由移动的过程中判断i >= a，如果是，i直接跳到b+1，对应的(a,b) 出队列，再找寻下一个(a,b)

```
Code fence
class Solution(object):
    def shortestSubarray(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        import collections
        left = 0
        count = 0
        minLen = 999999999
        dq = collections.deque()
        for i in range(len(A)):
            count += A[i]
            if A[i] < 0:
                total = A[i]
                j = i
                while total < 0 and j >= 0:
                    j -= 1
                    total += A[j]
                j += 1
                while j <= left and left <= i:
                    count -= A[left]
                    left += 1
                while len(dq) > 0 and j <= dq[-1][0]:
                    dq.pop()
                dq.append((j, i))

            while count >= K and i >= left:
                minLen = min(minLen, i - left + 1)
                count -= A[left]
                left += 1
                while len(dq) > 0 and dq[0][0] <= left:
                    a, b = dq.popleft()
                    while a <= left and left <= b:
                        count -= A[left]
                        left += 1

        return -1 if minLen == 999999999 else minLen

if __name__ == '__main__':
    print Solution().shortestSubarray([-34,37,51,3,-12,-50,51,100,-47,99,34,14,-13,89,31,-14,-44,23,-38,6], 151)
```