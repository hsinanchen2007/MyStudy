### 解题思路
思路比较简单，使用了快速排序的思想：
- 假设当前数组为arys, 索引起点为start, arys的长度为end；
- 以数组arys左侧元素为基准进行比较，小于基准的元素放入临时数组left，大于等于基准的元素放入另一个临时数组right中；
  - 若临时数组left中的元素数量等于K，则直接返回left；
  - 若left中的元素数量大于K，则说明，最小的K个数在left数组中，继续按照上述方法划分数组left;
  - 若left中的元素小于K，则保留left数组元素，同时在right数组中继续按照上述方法寻找前K-left.length小的元素；
- 这样依次递归寻找，便可以满足要求；
- 需要注意的是，在每次遍历数组元素与基准进行比较的时候，要先把基准单独拎出来，避免陷入无限递归的，举个例子，当数组=[3,2,1,4,5], k=3的时候，可以尝试下看看；

### 代码

```python3
class Solution:

    def find(self, arys, start, end, K):
        if end - start <= 1:
            return arys
        base = arys[start]
        left = []
        right = []
        cnt = 0
        for i in range(start+1, end):
            if arys[i] < base:
                left.append(arys[i])
                cnt += 1
            else:
                right.append(arys[i])
        
        left += [base]
        cnt += 1
        if cnt == K:
            return left
        elif cnt > K:
            return self.find(left, 0, cnt, K)
        else:
            return left + self.find(right, 0, end-start-cnt, K-cnt)
        pass

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        lgth = len(arr)
        if k == lgth:
            return arr
        
        return self.find(arr, 0, lgth, k)
        

```