### 解题思路
d

### 代码

```python3
class Solution:
    def countBits(self, num: int) -> List[int]:
        if num==0:
            return [0]
        
        res=[0,1]
        i=1  #代表第i+1层,从第二层开始,根节点为第0层
        curr=2   #从二开始
        while curr<=num:
            k=2**i   #代表第i层元素个数
            for j in range(1,k+1):
                if curr>num:
                    break
                if j<=k//2:   #k//2为上一层的元素
                    res.append(res[curr-k//2])   #对应位置为j-k//2+1
                else:
                    res.append(res[curr-k//2]+1)
                
                curr = curr+1
            i+=1  #层数+1
        return res
```