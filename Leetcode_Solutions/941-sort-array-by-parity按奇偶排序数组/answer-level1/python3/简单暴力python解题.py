### 解题思路
1、首先创建一个空列表；
2、先遍历完第一遍将偶数元素先添加到新数组中；
3、再遍历第二遍，将奇数元素添加到偶数元素后面
4、最后返回数组B
时间中规中矩吧。。。毕竟我才刚学python
![TIM截图20200407120100.png](https://pic.leetcode-cn.com/49e6dea5b74cc488917c7e4e80648586f8f0438475f34ba20480ca037f388bb2-TIM%E6%88%AA%E5%9B%BE20200407120100.png)

### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        B=[]
        for i in A:
            if i%2==0:
                B.append(i)
        for j in A:
            if j%2 != 0:
                B.append(j)
        return B

```