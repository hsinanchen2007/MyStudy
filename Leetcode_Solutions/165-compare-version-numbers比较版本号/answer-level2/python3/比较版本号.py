### 解题思路
本题类似于字符串比较大小；
1. 首先将`version1`和`version2`分别按字符`'.'`进行分割，生成两个字符列表；
2. 将较短的列表补充字符`'0'`进行补充，使得两个列表长度相等；
3. 从头开始逐个比较两个列表元素的大小；按题意要求返回相应的值；

注意这里可能存在：将字符串转换成数字时字符串太长，转换的数字超过了最大整数范围；因此可以直接用字符串进行比较；

### 代码

```python3
class Solution:
    """
    根据字符'.'将version1和version2分割成列表；
    """
    def compareVersion(self, version1: str, version2: str) -> int:
        version1_list = version1.split('.')
        version2_list = version2.split('.')
        if len(version1_list) < len(version2_list):
            version1_list.extend(['0']*(len(version2_list)-len(version1_list)))
        elif len(version2_list) < len(version1_list):
            version2_list.extend(['0']*(len(version1_list)-len(version2_list)))
        for i in range(len(version2_list)):
            if int(version1_list[i]) > int(version2_list[i]):
                return 1
            elif int(version1_list[i]) < int(version2_list[i]):
                return -1
        return 0
```