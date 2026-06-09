## 思路:

模拟过程

简单实现过程

```python
def generate(self, numRows: int) -> List[List[int]]:
        res = []
        while numRows:
            tmp = [1]
            if not res:
                res.append(tmp)
            else:
                n = len(res[-1])
                for i in range(n - 1):
                    tmp.append(res[-1][i] + res[-1][i+1])
                tmp.append(1)
                res.append(tmp)
            numRows -= 1
        return res
```

接下来, 我们把代码简化!

相似题型:[119. 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

## 代码:

```python [1]
def generate(self, numRows: int) -> List[List[int]]:
        res = []
        tmp = []
        for _ in range(numRows):
            tmp.insert(0, 1)
            for i in range(1, len(tmp) - 1):
                tmp[i] = tmp[i] + tmp[i+1]
            res.append(tmp[:])
        return res
```



```java [1]
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new LinkedList<>();
        List<Integer> tmp = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            tmp.add(0, 1);
            for (int j = 1; j < tmp.size() - 1; j++) {
                tmp.set(j, tmp.get(j) + tmp.get(j + 1));
            }
            res.add(new ArrayList<>(tmp));
        }
        return res;
    }
}
```

