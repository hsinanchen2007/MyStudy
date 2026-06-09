### 解题思路
我的思路：代码写的有些杂乱，我的思路就是存入字典判断，，，
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        dicts = {}
        temp = {}
        for i in range(len(A)):
            for m in A[i]:
                if i == 0:
                    if m not in dicts:
                        dicts[m] = 1
                    else:
                        dicts[m] += 1
                else:
                    if m in dicts:
                        if m not in temp:
                            temp[m] = 1
                        else:
                            temp[m] += 1
            if i:
                for key in dicts:
                    if key in temp:
                        min_num = min(dicts[key],temp[key])
                        dicts[key] = min_num
                    elif key not in temp:
                        dicts[key] = 0
            temp = {}

        result = []
        for key in dicts:
            if dicts[key]:
                for _ in range(dicts[key]):
                    result.append(key)
        return result
                
```