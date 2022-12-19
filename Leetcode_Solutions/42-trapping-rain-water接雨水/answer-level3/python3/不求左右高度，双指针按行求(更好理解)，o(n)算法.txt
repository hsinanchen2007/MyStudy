## **思路**
1. 利用左右指针的下标差值计算出每一行雨水+柱子的体积，如图第一行体积为11，第二行为8，第三行为1。累加得到整体体积$tmp=20$（每一层从左边第一个方格到右边最后一个方格之间一定是被蓝黑两种颜色的方格填满的，不会存在空白，这也是为什么能按层求的关键）
2. 计算柱子体积，为$height：[0,1,0,2,1,0,1,3,2,1,2,1]$ 数组之和$SUM=14$（也可以直接用sum()函数，不过时间复杂度就是O(2n)了）
3. 返回结果 $tmp-SUM$就是雨水的体积



## 具体流程
先将整体视为三层
![image.png](https://pic.leetcode-cn.com/0baad78580bd7722e2fce2a9f4571d84dc413b6ab9531585038a3d33be2fdae4-image.png)

初始$left=0，right=11，high=1$，$high=$当前层数。当**左右指针指向的区域高度小于high时，左右指针都向中间移动，直到指针指向区域大于等于high的值。若不小于high，则指针不移动**。
![image.png](https://pic.leetcode-cn.com/ee1e34cb8fc3d5045cc5a19d5827ba22d25608cb6244073158347ee5452e5d15-image.png)
第一层：$high=1$,所以$left$向右移动到$left=1，right$保持不动。所以第一层体积为$tmp1=right-left+1=11$(记得加一奥！)
![image.png](https://pic.leetcode-cn.com/9289eb7719d076ad8861639c7209097be17d31303af8ff5e11d4ee15bcebfb81-image.png)

第二层：$high=2，left$一直向右移动到$left=3，right$向左移动到$right=10$，所以$tmp2=right-left+1=8$
![image.png](https://pic.leetcode-cn.com/c32547d2964a09c0b0c24b31fab690ee10ef3aaa6624cb7c51de865482d108e2-image.png)


第三层：$high=3,left$和$right$向中间移动直至重合，因为重合的时候仍然有体积（所以循环条件里一定要写$left<=right$,而不是$left<right$），所以$tmp3=right-left+1=1$
![image.png](https://pic.leetcode-cn.com/f9eed86c8e4162bc0cbc605bc2eb70b39fb3ec404b1582696ace639d00049d54-image.png)

## 代码

```

class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        left,right=0,n-1
        SUM,tmp,high=0,0,1
        while(left<=right):
            while(left<=right and height[left]<high):
                SUM+=height[left]
                left+=1
            while(right>=left and height[right]<high):
                SUM+=height[right]
                right-=1   
            high+=1
            tmp+=right-left+1      
        return tmp-SUM
```
## 复杂度分析
- 时间复杂度：$O(n)$
- 空间复杂度：$O(1)$

因为没看到有这种解法的，我就写个题解来献丑啦~有什么更好的优化意见欢迎大家提出呀~嘻嘻，笔芯![image.png](https://pic.leetcode-cn.com/a5c9a5c3846fa0ceece6035ed72c7d3a7cfaf4104cfd70b2be9af9966d1e095d-image.png)

