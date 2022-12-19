**前言**：本题最难应该是读懂题目意思吧（奈何我语文水平也很弱鸡，花了好久才读懂题目。

**题目大意**：就是移动首尾端点石子的位置，把它插入到数轴上未占用的点上，来使该石子不再是端点石子。

**举例**：`1,100,102,105,200`
***
**最大移动次数**
我们将首端点石子`1`移动到`[100,200]`中的非占用点，这样就可得到一个结果`A[n-1]-A[1]-n+2`
![image.png](https://pic.leetcode-cn.com/46bde9cf59f8b2287032f8b3d91e1035250131e84a893401242b3edbf8ec641b-image.png)
我们将尾端点石子`200`移动到`[1,105]`中的非占用点，这样就可得到一个结果`A[n-2]-A[0]-n+2`
![image.png](https://pic.leetcode-cn.com/baf8fc2df572d9cac8dd856ef493614063b6e031555934bafb7a1d74218145ce-image.png)
最终的最大移动次数为：`max(A[n-1]-A[1]-n+2, A[n-2]-A[0]-n+2)`
****
**最小移动次数**
使用滑动窗口来记录最小移动次数，当窗口内的石子个数大于n时，我们需要缩小窗口。already_stone来统计窗口内的石子数，剩下来的石子数n-already_stone全部用来移动。注意特殊情况就是类似`3,4,5,6,10`这种前n-1个石子连续，第n个石子不连续，但是我们不能直接将10移到2，应该是3移到8，10移到7，需要两步完成。
***
![image.png](https://pic.leetcode-cn.com/e5d00dddf873e751a82525bcc0bd1e32c657fbfe7fdc593a788de58ef15fe6d3-image.png)

**代码如下：**
```cpp
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        
        int n=stones.size(),minMove=n;
        
        for(int i=0,j=0;j<n;++j)
        {
            //当前窗口的大小大于n
            while(stones[j]-stones[i]+1>n)i++;
            
            //当前窗口的石子个数
            int already_stone=(j-i+1);
            
            //前n-1个石子的顺序连续，最后一个石子不连续，需要移动2步。
            //比如3 4 5 6 10，我们不能直接将10变为2，而是将3变为8，然后10变为7来移动
            if (already_stone==n-1&&stones[j]-stones[i]+1==n-1)
                minMove=min(minMove,2);
            else
                minMove=min(minMove,n-already_stone);
            
        }
        return {minMove,max(stones[n-1]-stones[1]-n+2, stones[n-2]-stones[0]-n+2)};
    }
};
```
