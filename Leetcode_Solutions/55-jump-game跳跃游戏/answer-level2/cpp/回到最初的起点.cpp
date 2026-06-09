第一次写题解，格式可能会有些不规范^_^
![image.png](https://pic.leetcode-cn.com/223747e166512e3da687c47cc6748db18d73d5faa4ae6f1ac30857603ffc9334-image.png)

引理：某一点A，可以跳跃到终点，如果A前边的点B可以跳跃到A，那么B也可以跳跃到终点。
方便起见，我们把这种点称作 “可解点”。如果最开始的点是“可解点”，那么这个问题就返回true。

所以我们从倒数第二个点开始往前推，如果倒数第二个点可以跳跃到终点，那么它就是“可解的”；如果倒数第三个点可以跳跃到倒数第二个点，那么它也是“可解的”（注意想一下为什么这里比较倒数第二个点，而不是更远的倒数第一个点）。依次往前推
我在这里定义了一个leftPoint，来指向最左边的一个“可解点”。初始指向终点，不断更新。若最后leftPoint==0，函数返回true
代码如下
    
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int leftPoint=nums.size()-1;
        for(int index=nums.size()-2;index>=0;index--){
            if(nums[index]>=leftPoint-index){
                leftPoint=index;
            }
        }
        return leftPoint==0?1:0;
    }
};
```

谢谢，喜欢就点赞鼓励下吧~
