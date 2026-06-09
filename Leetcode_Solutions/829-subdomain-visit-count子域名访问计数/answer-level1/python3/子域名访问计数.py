### 解题思路
字典统计次数

### 代码

```python3
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        # 构造一个字典,键为字符串,值为次数
        dicts = {}
        for x in cpdomains:
            string = x.split(' ', 1)
            str_number = int(string[0])
            if string[1] not in dicts:
                dicts[string[1]] = str_number
            else:
                dicts[string[1]] += str_number
            str_child = string[1].split('.', 2)
            if len(str_child) == 3:
                temp = str_child[1]+'.'+str_child[2]
                if temp not in dicts:
                    dicts[temp] = str_number
                else:
                    dicts[temp] += str_number
                if str_child[2] not in dicts:
                    dicts[str_child[2]] = str_number
                else:
                    dicts[str_child[2]] += str_number
            elif len(str_child) == 2:
                if str_child[1] not in dicts:
                    dicts[str_child[1]] = str_number
                else:
                    dicts[str_child[1]] += str_number
        result = []
        for key in dicts:
            string = str(dicts[key]) + ' ' + str(key)
            result.append(string)
        return result
                
```