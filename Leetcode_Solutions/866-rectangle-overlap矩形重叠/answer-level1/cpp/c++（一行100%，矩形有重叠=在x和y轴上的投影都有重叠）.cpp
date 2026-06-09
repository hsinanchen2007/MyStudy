- 思路：
  - **矩形有重叠 = 在x和y轴上的投影都有重叠**
  - 两个线段是否重叠：**右端的最小值大于左端的最大值**
- 结果:
  - 用时：100%（0ms）
  - 内存：7%（9.4MB）
```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (min(rec1[2],rec2[2])>max(rec1[0],rec2[0]) && min(rec1[3],rec2[3])>max(rec1[1],rec2[1]));
    }
};
```
> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------