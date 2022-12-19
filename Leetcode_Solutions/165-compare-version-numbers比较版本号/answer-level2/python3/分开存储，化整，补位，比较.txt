### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:    
        #分开春促
        version1_list=version1.split('.')
        version2_list=version2.split('.')
        #每一段化为整数（处理类似于001的数据）
        for i in range(len(version1_list)):
            version1_list[i]=int(version1_list[i])
        for i in range(len(version2_list)):
            version2_list[i]=int(version2_list[i])
        #list位数不同时补位
        if len(version1_list)>len(version2_list):
            dif=len(version1_list)-len(version2_list)
            version2_list+=[0]*dif
        if len(version2_list)>len(version1_list):
            dif=len(version2_list)-len(version1_list)
            version1_list+=[0]*dif
        #list中相同idx比较大小 如若从头到尾都相同输出0
        for i in range(len(version1_list)):
            if version1_list[i]>version2_list[i]:
                return 1
            if version1_list[i]<version2_list[i]:
                return -1
        return 0
```