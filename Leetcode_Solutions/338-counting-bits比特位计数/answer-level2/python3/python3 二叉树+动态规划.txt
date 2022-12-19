### 解题思路
动态规划+二叉树，二叉树根节点为1。二叉树编码方式借鉴霍夫曼树，任意节点左孩子节点编码为0，右孩子节点编码为1。统计curr所在节点的右分支数量即可。加上使用动态规划，第curr个节点可以有之前的第curr-k//2个节点推出，其中k为curr所在层数所拥有的的节点数。
![微信截图_20200117145319.png](https://pic.leetcode-cn.com/afe85fa7f9399f0779510bbf2e94e209bd58d0a210beb8f9c2af74c62995900d-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200117145319.png)


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
            for j in range(1,k+1):  #求解第i+1层的第j个元素
                if curr>num:
                    break
                if j<=k//2:   #k//2为上一层的元素个数
                    res.append(res[curr-k//2])   #对应位置为j-k//2+1
                else:
                    res.append(res[curr-k//2]+1)
                
                curr = curr+1  #当前元素+1
            i+=1  #层数+1
        return res
```