### 解题思路
一次遍历，分情况处理

### 代码

```python3
class Solution:
    def myAtoi(self, str1: str) -> int:
        is_start = False  # 表示是否开始计算结果
        flag = 1
        nums_list = [str(i) for i in range(10)]
        res_list = []

        for char in str1:
            # print(char)
            # 如果先遇到字母，则返回0
            if char != ' ' and char != '+' and char != '-' and char not in nums_list and is_start == False:
                # print('情况1')
                break

            # 以正负号开始
            if (char == '-' or char == '+') and is_start == False:
                # print("情况2")
                if char == '-': flag = -1
                is_start = True
                continue
            
            # 以数字开始
            if char in nums_list and is_start == False:
                # print("情况3")
                res_list.append(char)
                is_start = True
                continue

            # 遍历过程中
            if char in nums_list and is_start:
                # print("情况4")
                res_list.append(char)
                continue

            # 终止
            if char not in nums_list and is_start:
                # print("情况5")
                break
        # print(res_list)

        res = 0
        for char in res_list:
            res = res*10 + int(char)
        # print(res)
        
        res = res * flag
        if res > (1 << 31) -1:
            return (1 << 31) - 1
        if res < -1 * (1 << 31):
            return -1 * (1 << 31)
        return res
```