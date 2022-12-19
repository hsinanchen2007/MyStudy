## 思路:

跟上一题一样[118. 杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/),

模拟过程

## 代码:

```python [1]
    def getRow(self, rowIndex: int) -> List[int]:
        tmp = []
        for _ in range(rowIndex + 1):
            tmp.insert(0, 1)
            for i in range(1, len(tmp) - 1):
                tmp[i] = tmp[i] + tmp[i+1]
        return tmp
```

 

```java [1]
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> tmp = new LinkedList<>();
        for (int i = 0; i <= rowIndex; i++) {
            tmp.add(0, 1);
            for (int j = 1; j < tmp.size() - 1; j++)
                tmp.set(j, tmp.get(j) + tmp.get(j + 1));
        }
        return tmp;
    }
}
```

