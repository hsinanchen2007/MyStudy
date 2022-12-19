### 解题思路
a/d 可以由a/b * b/d或者a/c * c/d或者 a/e * e/d 计算得到，或者是无结果。
所以维护一个二维数组（map），储存a,b,c,d,e之间的除法结果，如果两者之间无结果，则存-inf进行区别。
不停遍历这个map，保证没有新的结果能计算出来，最后根据要求查询map即可

### 代码

```python3
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        dic = {}
        map = []
        index = 0
        for index_i, i in enumerate(equations):
            if i[0] not in dic:
                dic[i[0]] = index
                L = len(map)
                map.append([float("-inf") for i in range(L)])
                for j in range(L + 1):
                    map[j] += [float("-inf")]
                map[index][index] = 1.0
                index += 1
            if i[1] not in dic:
                dic[i[1]] = index
                L = len(map)
                map.append([float("-inf") for i in range(L)])
                for j in range(L + 1):
                    map[j] += [float("-inf")]
                map[index][index] = 1.0
                index += 1
            map[dic[i[0]]][dic[i[1]]] = values[index_i]
            map[dic[i[1]]][dic[i[0]]] = 1.0 / values[index_i]
        has_change = 1
        L = len(map)
        LL = len(map[0])
        while has_change:
            has_change = 0
            for i in range(L):
                for j in range(LL):
                    if map[i][j] > float("-inf"):
                        for k in range(LL):
                            if map[j][k] > float("-inf") and map[i][k] == float("-inf"):
                                map[i][k] = map[i][j] * map[j][k]
                                map[k][i] = 1.0 / map[i][k]
                                has_change = 1
        output = []
        for i in queries:
            if i[0] not in dic or i[1] not in dic:
                output.append(-1.0)
            else:
                if map[dic[i[0]]][dic[i[1]]] > float("-inf"):
                    output.append(map[dic[i[0]]][dic[i[1]]])
                else:
                    output.append(-1.0)
        return output
```