### 解题思路
由于输入合法，先把字符串拆分为数字列表，然后把长度用0补齐，开始比较。

### 代码

```python3
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1_list = version1.split('.')
        v2_list = version2.split('.')
        int_v1_list = [int(v) for v in v1_list]
        int_v2_list = [int(v) for v in v2_list]

        diff = len(int_v1_list) - len(int_v2_list)
        tmp = [0] * abs(diff)
        if diff < 0:
            int_v1_list.extend(tmp)
        elif diff > 0:
            int_v2_list.extend(tmp)

        if int_v1_list == int_v2_list:
            return 0
        elif int_v1_list < int_v2_list:
            return -1
        
        return 1

```