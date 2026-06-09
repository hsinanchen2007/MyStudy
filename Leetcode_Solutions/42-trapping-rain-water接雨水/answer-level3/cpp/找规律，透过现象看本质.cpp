### 解题思路
接完雨水，很容易看出这个数组有什么特点，就像一个山峰一样。
在最大值左边不严格递增，右边不严格递减。
因此只需要把原数组变成符合这样要求的数组就行了，改变的量就是接的雨水。

具体实现只需要先找到最大值索引，左右各自遍历一遍
两边都维护一个值来表示之前的最大值以保证单调性，
如果比最大值小，雨水量就加上这个差值，
如果大于等于，就更新最大值。
![image.png](https://pic.leetcode-cn.com/67e7b6d9c91f43c521300e34d43cb53d13f1a396f3bb14d8e050d1ad14c0b729-image.png)


### 代码

```cpp
class Solution {
public:
    //以最大值分界，左边非减，右边非增
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int m=max_element(height.begin(),height.end())-height.begin();
        //遍历最大值左边
        int res=0,cur=height[0];
        for(int i=1;i<m;i++)
        {
            if(height[i]<cur)
                res+=cur-height[i];
            else
                cur=height[i];
        }
        //遍历最大值右边
        cur=height[n-1];
        for(int i=n-2;i>m;i--)
        {
            if(height[i]<cur)
                res+=cur-height[i];
            else
                cur=height[i];
        }
        return res;
    }
};
```