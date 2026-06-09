### 解题思路
思路比较简单：
- 先对数组进行从小到大排序
- 依次遍历每一个元素，若当前元素与前一个元素相等，则单独放入一个临时数组中（记为queue），该用以记录需要进行递增的元素；
- 若当前元素与前一个元素相差1，则直接进行下一个元素的遍历；
- 若当前元素与前一个元素之间的间隔大于1（标记为b - a > 1），则说明可以将queue中的元素，按照先入先出的规则，依次递增至[a+1, b-1]，并统计递增的步数；
- 上述情况需要注意，queue中的元素数量跟区间[a+1, b-1]所包含的元素数量可能不等，所以需要进行大小判别；

因为题目要求是递增，所以本题只需要向后看；如果说既可以递增又可以递减，那么本题的解法暂不适用。
思路比较直白，欢迎讨论
 

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        
        lgth = len(A)
        if lgth <= 1:
            return 0

        A.sort()

        queue = []   # the elements needed to increase
        qcnt = 0     # the number of queue

        rst = 0

        prev = A[0]
        idx = 1

        while idx < lgth:
            if A[idx] == prev:
                queue.append(prev)
                qcnt += 1
            elif A[idx] - prev > 1:
                j = 0
                tmp = min(A[idx]-prev-1, qcnt)
                while j < tmp:
                    rst += (prev+1+j) - queue[0]
                    queue.pop(0)
                    qcnt -= 1
                    j += 1

            prev = A[idx] + 0
            idx += 1
        
        for k in range(qcnt):
            rst += (prev+1+k) - queue[k]

        return rst


            

            

```