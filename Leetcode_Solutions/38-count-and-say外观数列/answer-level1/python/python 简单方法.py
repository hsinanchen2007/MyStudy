### 解题思路

 - 先对每个数字计数,其实报数规则就是把 number + the number（即数目加对应的数）
 - 下面的数是上面的数得到的
 - 计数完事儿之后其实结果显而易见，直接得出就好

### 复杂度分析：

- 执行用时 :32 ms, 在所有 python3 提交中击败了97.45%的用户
- 内存消耗 :12.6 MB, 在所有 python3 提交中击败了99.45%的用户


**算法复杂度为：**

- $O((n-1)*N)$

### 代码

```python3

class Solution:
    def countAndSay(self, n: int) -> str:

        result={1:'1'}
        for i in range(2,n+1):
            s=result[i-1]
            new_r=[]
            record=None
            c=0
            while s!='':
                if record==None or record==s[0]:
                   record=s[0]
                   c+=1
                else:
                    new_r.append(str(c)+record)
                    record=s[0]
                    c=1
                s=s[1:]
                if len(s)==0:
                    new_r.append(str(c)+record)
            result[i]=''.join(new_r)
        return result[n] 

```