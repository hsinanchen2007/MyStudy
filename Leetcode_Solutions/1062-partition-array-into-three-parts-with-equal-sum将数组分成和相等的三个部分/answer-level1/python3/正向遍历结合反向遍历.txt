### 解题思路
    
![image.png](https://pic.leetcode-cn.com/a88c5b2976843fc4a81e5baf9b99326823f3d3a6a6b2bb1bae9084eb28a0c0b0-image.png)
    首先判断sum（A）能否被3整除，若不能则直接输出False，接着判断三段元素和的第一段是否存在，具体操作为计算正向遍历后的元素累加值是否能等于sum（A）/3；然后判断三段元素和的最后一段是否存在，具体操作为在排除正向遍历使用过的元素的情况下，计算反向遍历后的元素和能否等于sum（A）/3，同时还得至少留下一个元素作为三段元素和的中间一段。




### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        A_average=sum(A)/3
        forward_sum=0
        forward_bool=False
        backward_sum=0
        backward_bool=False
        n_forward=0

        if sum(A)%3 !=0:
            return(False)
        else:
            for i in range(len(A)-2):
                n_forward +=1
                forward_sum +=A[i]
                if forward_sum==A_average:
                    forward_bool=True
                    break
            for i in range(len(A)-1,n_forward,-1):
                backward_sum +=A[i]
                if backward_sum==A_average:
                    backward_bool=True
                    break
        if forward_bool and backward_bool:
            return(True)
        else:
            return(False)


```