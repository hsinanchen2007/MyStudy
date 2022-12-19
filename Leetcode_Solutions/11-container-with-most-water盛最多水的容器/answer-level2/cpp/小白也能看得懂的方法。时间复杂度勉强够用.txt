### 解题思路

# 面积=(i-j)*min(height[i],height[j])
想要面积大，有两种办法：
   ** 1.让水池的长度更长
   ** 2.让水池的宽度更宽****

如果我们记录最长隔板的长度为height[left];   这个隔板所在位置为left

那么我们在遍历的时候，就不用管left右边的隔板了
因为它们不满足 上面的 1，2条
只需要判断左边的for(j=0;j<=left;j++)

详细代码如下
希望大家多提宝贵意见，让我的描述更加清楚

### 代码

```cpp
class Solution {
public:
int min(int x,int y)
    {
        if(x<y)
        return x;
        else 
        return y;
    }
    int maxArea(vector<int>& height) 
    {  
        int i;
        int j;
        int left=0;
        int max=0;
        int length=height.size();
        for(int i=0;i<length;i++)
        {
            for(j=0;j<=left;j++)
            {
                int x=(i-j)*min(height[i],height[j]);
                if(x>max)
                max=x;
            }
            if(height[i]>height[left])
            {
                left=i;
            }
        }
        
        return max;
        
    }
    
};
```