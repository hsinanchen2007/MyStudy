### 解题思路
首先height的长度len小于2，不能构成容器，盛水凉为0；
接下来是我的思路：将整个盛水量分割成一个个独立的容器盛水量之和，每个容器分为两端和中间部分，两端高度值较小的为容器的盛水高度，中间部分与盛水高度之差的和为容器的盛水量。
首先，将height[0] 放入cur中作为容器的最低点(也就是盛水高度)，最低点指针curp=0，接下来要寻找容器的另一端，用i从height[1]开始到height[len-1]进行遍历，如果height[i]<盛水高度cur，则该容器盛水量sum+=cur-height[i],直到找到容器另一端height[i]>=cur为止，如果找到容器另一端说明构成了一个容器，将该容器的容量加入雨水总量当中去ans+=sum，接着将这一点视为新容器的起始端cur=height[i]，指针curp=i,接着进行遍历。但是后面会有一个问题，那就是遍历到最后一次容器找不到另一端，也就是构不成一个容器，也就是height[curp]比后面的所有值都要大。。。
![微信图片_20200404220043.jpg](https://pic.leetcode-cn.com/d4e5f24a94779477a10b53e6b8a2b16ef092a3a37bebce0c440069e195c0755b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200404220043.jpg)


### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        if(len<=1) return 0;
        int cur=height[0];
        int curp=0;
        int ans=0;int sum=0;
        for(int i=1;i<len;++i)
        {
            if(height[i]<cur) sum+=cur-height[i];
            else
            {
                ans+=sum;   //累加结果
                sum=0;   //清空计数和
                cur=height[i];
                curp=i;
            }
        }
        sum=0;
        if(curp!=len-1)   //末尾无效
        {
            cur=height[len-1];
            for(int i=len-2;i>=curp;--i)
            {
                if(height[i]<cur) sum+=cur-height[i];
                else{
                    ans+=sum;
                    sum=0;
                    cur=height[i];
                }
            }
        }
        return ans;
    }
};
```