### 解题思路
![QQ截图20200303143444.png](https://pic.leetcode-cn.com/76e48c5d361a0d1abf073d339916fb6d0888aee86599184e0a092aea204e1754-QQ%E6%88%AA%E5%9B%BE20200303143444.png)

没啥好写的，就是用zip函数同时遍历列表的相邻元素

### 代码

```python3
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        list_text=text.split(" ")
        i=2
        list_res=[]
        for is_or_not_first,is_or_not_second in zip(list_text,list_text[1:]):
            if is_or_not_first==first and is_or_not_second==second:
                if i < len(list_text):
                    list_res.append(list_text[i] )
                else:
                    pass
            i+=1
        return list_res
```