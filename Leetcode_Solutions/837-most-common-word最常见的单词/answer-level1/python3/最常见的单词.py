### 解题思路

### 代码

```python3
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # 1：去标点符号
        punc = '.!,;:?"\''
        for item in paragraph:  
            if item in punc:
                paragraph= paragraph.replace(item, ' ')

        # 2: 切割并字母小写
        words = paragraph.strip().lower().split()
      
        # 3: 统计
        dic = collections.Counter(words)

        # 4: 按照value从大到小排序，注意得到的是元组的列表，而不是字典
        sortedDic = sorted(dic.items(),key = lambda x:x[1],reverse = True)
        
        if len(banned) == 0:
            return sortedDic[0][0]

        # 5: 出现次数多的是否在banned list里
        for key,value in sortedDic:
            if key in banned:
                continue
            else:
                return key
```