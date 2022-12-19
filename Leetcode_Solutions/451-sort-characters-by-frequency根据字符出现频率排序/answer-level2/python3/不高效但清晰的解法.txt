
### 代码

```python3
class Solution:
    def frequencySort(self, s: str) -> str:
        dic = {}
        for i in s:
            dic[i] = dic.get(i, 0) + 1  # 建立字典存储字符和频率
        new_dic = sorted(dic.items(),key=lambda x:(x[1],x[0]),reverse=True)  # 按value倒序排序
        #print(new_dic)
        out = []
        for i in range(len(new_dic)):
            for j in range(new_dic[i][1]):
                out.append(new_dic[i][0])  # 二元组第一项为字符第二项为循环次数
        out = ''.join(out) # 转换为字符
        return out
```