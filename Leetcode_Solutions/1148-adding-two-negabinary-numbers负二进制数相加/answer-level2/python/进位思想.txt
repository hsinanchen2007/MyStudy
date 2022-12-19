### 解题思路
先直接将arr1和arr2加起来，得到的结果列表只包含0，1，2，然后从左边开始向右（方向一定要这样，否则会出现其他数字）扩散进位：
1.为2的情况只要将当前位置0，左边一位减1即可，即：2*(-2)**a == -1*(-2)**(a+1), a代表当前位置，下同
这样处理最多只会使前一项-1，当前位置0，所以从左到右处理后最多只会出现新数字-1，不会有其他情况
此时如果出现-1：即结果列表只包含0，1，-1
2.为-1的情况只要将当前位置1，前一位加1即可，即：(-1)*(-2)**a == 1*(-2)**(a+1) + 1*(-2)**a
这样处理最多只会使前一项+1，当前位置1，所以从左到右处理后最多只会出现新数字2，不会有其他情况
然后重复这个操作直到只剩下0，1。
最后删除开头多余的0即可。
注意：从右向左看这个操作时，你会发现每个循环的最后一次操作一定会使结果为2或-1的最后一位改为正确结果，所以这个操作重复几回下去一定会得到正确结果

### 代码

```python3
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        if len(arr1) > len(arr2):  #先将两部分直接相加
            result_1 = arr1[:len(arr1) - len(arr2)]
        else:
            result_1 = arr2[:len(arr2) - len(arr1)]
        result_2 = []
        for i in range(min(len(arr1), len(arr2))):
            result_2.insert(0, arr1[-i - 1] + arr2[-i - 1])
        result = result_1 + result_2   
        while (-1) in result or 2 in result:
            for i in range(len(result)):
                if result[i] == -1:
                    if i == 0:
                        result[i] = 1
                        result.insert(0, 1)
                    else:
                        result[i - 1] += 1
                        result[i] = 1
                if result[i] == 2:
                    if i == 0:
                        result[i] = 0
                        result.insert(0, -1)
                    else:
                        result[i - 1] -= 1
                        result[i] = 0
        while result[0] == 0 and len(result) > 1:  #删除多余0
            del result[0]
        return result
```