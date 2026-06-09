### 解题思路
此处撰写解题思路
分几种情况：
1.长度相等直接判断
2.长度相差2肯定不行
3.长度只差1，双指针遍历判断
### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if first==second:
            return True
        elif len(first)==len(second):
            cnt =0
            for i in range(len(first)):
                if first[i]!=second[i]:
                    cnt+=1
                if cnt>1:
                    return False
            return True
        elif abs(len(first)-len(second))>1:
            return False
        else:
            i,j=0,0
            cnt = 0
            while i<len(first) and j<len(second):
                if first[i]!=second[j]:
                    if len(first)>len(second):
                        i+=1
                    else:
                        j+=1
                    cnt+=1
                else:
                    i+=1
                    j+=1
                if cnt>1:
                    return False
            return True



```