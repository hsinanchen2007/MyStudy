### 解题思路 1.0
方法：以正整数序列中的每一个元素为起始进行遍历，找到符合条件的序列
步骤：
1. 判断target是否满足范围 1 <= target <= 10^5
2. 判断target奇偶，计算待遍历的正整数序列上限
3. 遍历正整数序列，以当前遍历的元素为起始值，内循环遍历累加，找到满足条件的序列
4. 若循环遍历的过程中，当前序列不满足条件，则将临时遍历值还原，跳出内循环
5. 判断序列是否至少含有两个数，若满足，则将序列添加至输出结果的列表内
6. 返回结果
### 执行结果
超出时间限制
### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        if target >= 1 and target <= 10 ** 5:
            result = []
            result_temp = []
            n = 0
            temp = target

            if target % 2 != 0:
                n = target // 2 + 1
            else:
                n = target // 2

            for element in range(1, n):
                for num in range(element, n + 1):
                    
                    if num <= temp:
                        result_temp.append(num)
                    elif num > temp and temp != 0:
                        result_temp = []
                        break
                    else:
                        break

                    temp -= num

                if temp == 0 and len(result_temp) >= 2:
                    result.append(result_temp)

                result_temp = []
                temp = target

            return result
```

### 解题思路 2.0
优化：减少执行时间
方法：
1. 利用数学公式 (首项 + 末项) * 项数 / 2 和 求根公式
2. 字典的方法 dict.get(key)
步骤：
1. 判断target是否满足范围 1 <= target <= 10^5
2. 判断target奇偶，计算待遍历的正整数序列上限
3. 将待遍历的正整数索引序列转存为字典，键为元素，值为索引
4. 遍历正整数序列，当前遍历元素作为数学公式中的首项，利用求根公式计算得末项数值
5. 用字典的方法找到末项是否存于字典内，若存在，则将首项与末项范围内的序列存于临时列表
6. 判断临时列表是否至少含有两个数，若满足，则将序列添加至输出结果的列表内，且将临时列表还原
7. 返回结果
### 执行结果
执行用时：160 ms
内存消耗：19.8 MB
### 代码

```python
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        if target >= 1 and target <= 10 ** 5:
            result = []
            result_temp = []
            num_dict = {}
            n = 0
            end = 0
            temp = 0

            if target % 2 != 0:
                n = target // 2 + 1
            else:
                n = target // 2

            for i, element in enumerate(list(range(1, n + 1))):
                num_dict[element] = i

            for element in range(1, n):
                end = abs((0.25 + element ** 2 - element + 2 * target) ** 0.5 - 0.5)
                temp = num_dict.get(end)

                if temp is not None:
                    result_temp = list(range(element, temp + 2))
                else:
                    continue

                if len(result_temp) >= 2:
                    result.append(result_temp)

                result_temp = []

            return result
```