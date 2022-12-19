### 解题思路

![QQ截图20200315161150.png](https://pic.leetcode-cn.com/1290109cb90ee99126ae8d1cf0cfe1d65d39963ff765d5f10f30424ef30381b3-QQ%E6%88%AA%E5%9B%BE20200315161150.png)

参考下面仁兄的间隔法，把间隔从大大小遍历，避免了最后一步翻转list，快了30%：

作者：quantumdriver
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/xiang-jie-hua-dong-chuang-kou-fa-qiu-gen-fa-jian-g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target<3:
            return []
        b=[];
        i=((1+8*target)** 0.5-1)/2
        if int(i)==i:
            i=i-1
            i=int(i)
        else:
            i=int(i)
        while(i>=1):
            x=(target-i*(i+1)//2)/(1+i)
            if int(x)==x:
                x=int(x)
                b=b+[[a for a in range(x,x+i+1)]]
            i=i-1
            
        return b

```