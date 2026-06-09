### 解题思路
![QQ截图20200214185628.png](https://pic.leetcode-cn.com/a8ec0b6ced46a32ddd6ea370af5086cd1c610baf42548fe8bbac3e405080de2b-QQ%E6%88%AA%E5%9B%BE20200214185628.png)
居然用了拷贝


### 代码

```python3
class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        i = 0
        while i < len(arr) - 1:
            if arr[i] == 0:
                temp=arr[i+1:].copy()
                t=0
                for j in range(i+2,len(arr)):
                    arr[j]=temp[t]
                    t+=1
                arr[i + 1] = 0  # 复写0
                i += 1
            else:
                pass
            i += 1

```