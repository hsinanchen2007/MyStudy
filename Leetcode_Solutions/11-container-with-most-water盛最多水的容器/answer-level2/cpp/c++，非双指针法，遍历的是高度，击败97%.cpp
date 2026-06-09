首先这个算法是我自己想到的，看了官方和精选题解，没有提到这个方法，就写出来，如有重复，多多包涵。
![盛最多水的容器.JPG](https://pic.leetcode-cn.com/a307437f07024bffced5e26423d295a872de45804a09483de98a3ff709d8bcda-%E7%9B%9B%E6%9C%80%E5%A4%9A%E6%B0%B4%E7%9A%84%E5%AE%B9%E5%99%A8.JPG)


此方法不是横向遍历数组，而是纵向遍历高度，求出每个高度对应的最大盛水量，取最大值即可。

首先遍历一遍height，找出高度的最低值和最高值。
定义一个最大盛水量maxarea。
再从最低高度到最高高度，分别计算当前高度curheight的最大盛水量，方法就是从height数组两头分别找第一个不低于这个高度的线段，这两条线段的距离与当前高度的乘积就是当前高度的最大盛水量。
就像根据curheight的高度画一条线，找两端交点。
比如要计算水面高度为5时的最大水量，从height数组两边分别把小于5的线段过滤掉，两端分别第一个不低于5的线段构成的区间与5相乘，就作为高度为5时的最大盛水量，与maxarea相比，更新maxarea。

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxheight = 0, minheight = 0x7fffffff;
        for(int i = 0; i != height.size(); ++i)
        {
            maxheight = max(height[i], maxheight);
            minheight = min(height[i], minheight);
        }
        //计算每个高度对应最大面积
        long maxarea = 0;
        //这里left和right放在循环外面，可以重用，是降低复杂度的关键
        //因为便利高度是从低到高，也就是高度为4时过滤掉的height数组两端小于4的线段，当计算高度为5时，上次循环小于4的线段肯定也会小于5，所以left和
        //right可以继续重用，大大降低复杂度
        int left = 0, right = height.size() - 1;
        for(int curheight = minheight; curheight <= maxheight; curheight++)
        {
            while(left < right && height[left] < curheight)
                left++;
            while(left < right && height[right] < curheight)
                right--;
            if(left < right)
            {
                maxarea = max((right - left) * (long)curheight, maxarea);
            }
        }
        return maxarea;
    }
};
```
时间复杂度：O(N)，首先遍历一遍数组，N；遍历高度时，left和right都被重用不回退，最多到相遇，几个循环加起来最多N步。
空间复杂度：O(1)，用到了常数额外空间。