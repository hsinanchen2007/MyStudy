### 解题思路
1. 对数组进行遍历，并声明一个变量j，使得i+j=n.
2. 通过使用list(str())操作，对一个整数值进行划分，例如输入9909，将得到['9','9','0','9']
3. 然后通过判断字符'0'是否存在在相应的列表中
4. 如果不存在，则返回相应的两个数值i和j作为结果

### 代码

```python3
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        # 对数组进行遍历，并声明一个变量j，使得i+j=n.
        # 通过使用list(str())操作，对一个整数值进行划分，例如输入9909，将得到['9','9','0','9']
        # 然后通过判断字符'0'是否存在在相应的列表中
        # 如果不存在，则返回相应的两个数值i和j作为结果
        result = []
        for i in range(1, n):
            j = n-i
            if '0' not in list(str(j)) and '0' not in list(str(i)):
                result.append(j)
                result.append(i)
                break
        # 另一种写法
        # i = 1
        # while(i<n):
        #     j = n-i
        #     if '0' not in list(str(j)) and '0' not in list(str(i)):
        #         result.append(j)
        #         result.append(i)
        #         break
        #     i += 1
        return result

        


```