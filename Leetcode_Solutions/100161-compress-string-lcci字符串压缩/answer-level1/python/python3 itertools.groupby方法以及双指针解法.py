### 解题思路
此处撰写解题思路
两种方法，一个双指针，注意边界即可。
另一个是itertools的groupby方法，写起来比较简易。
### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        # ans = []
        # for k,g in itertools.groupby(S):
        #     ans.append(k)
        #     ans.append(str(len(list(g))))
        # if len(ans)<len(S):
        #     return "".join(ans)
        # else:
        #     return S

        i,j=0,1
        ans = []
        while j<len(S):
            while j<len(S) and S[i]==S[j]:
                j+=1
            # print(i,j)
            ans.append(S[i])
            ans.append(str(j-i))
            i=j
            
        if ans and len(ans)<len(S):
            return "".join(ans)
        else:
            return S

```