### 解题思路
1. 这个图画得好哇，看着看着就来灵感了
2. 双指针时间复杂度O（n），空间复杂度O（1）
3. 先遍历一遍，找到最高点，记录高度imax和坐标h
4. 再分别从两边两个指针往中间扫，以当前遍历中遇到的最高点的高度为标准stan
5. 再往中间走，如果当前的坐标高度小于stan，就说明当前坐标能接的雨水为stan-height[i]
![image.png](https://pic.leetcode-cn.com/f8ef33c41cf71ca6cea2db089b144c66fdd2be7d46d2d817b20d9492fdf839d6-image.png)

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int imax=-1,h;
        for(int i=0;i<height.size();i++)//找到最高点和它的高度
        {
            if(height[i]>imax)
            {
                imax=height[i];
                h=i;
            }
        }
        int stan=0,ans=0;
        for(int i=0;i<h;i++)//从前遍历到最高点
        {
            if(height[i]>stan)
            {
                stan=height[i];
                continue;
            }
            else  ans+=stan-height[i];
        }
        stan=0;//stan归零
        for(int i=height.size()-1;i>h;i--)//从后遍历到最高点
        {
            if(height[i]>stan)
            {
                stan=height[i];
                continue;
            }
            else ans+=stan-height[i];
        }   
        return ans;  
    }
};
```
如果觉得对你有点用的话，给我点个赞吧
艾薇波弟让我看到你的双手