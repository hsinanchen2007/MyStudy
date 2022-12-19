作为小白，第一次就无脑暴力解题
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size(), mymax=0, mycur=0;
        for(int i=0;i<=len-1;++i)
        {
            for(int j=i+1;j<=len-1;++j)
            {
                mycur=(j-i)*min(height[i],height[j]);
                mymax=max(mymax,mycur);
            }
        }
        return mymax;
    }
};
```
然后执行时间爆炸
改用指针移动法之后
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size(), res=0, cur=0;
        int *front=&height[0], *back=&height[len-1];
        while(front!=back)
        {
            cur=(back-front)*min(*back,*front);
            if(*front<=*back)front++;
            else back--;
            res=max(res,cur);
        }
        return res;
    }
};
```
时间直接变为
![QOII_){\[WE)8H@{MO@IBR5H.png](https://pic.leetcode-cn.com/9c73ce55fac515a3d6fe91962cc55b08bc895e412220e99bac6d4893a8e04a9f-QOII_\)%7B%5BWE\)8H@%7BMO@IBR5H.png)





