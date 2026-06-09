![image.png](https://pic.leetcode-cn.com/6d8e967fd928009349738fb035e60d2472b318e7c7837561e0c821d6eefe84d0-image.png)

第一次遍历找出最高的柱子index，并记录下高度，然后分别从开头和结尾向index遍历，加上每一个块

```c++ []
class Solution {
public:
    int trap(vector<int>& height) {
        int hightest = 0;
        int index = 0;
        int result = 0;
        if(height.size()<3)
            return 0;
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i]>hightest)
            {
                index = i;
                hightest = height[i];
            }
        }
        
        int temp = height[0];
        for(int i = 1; i < index; i++)
        {
            if(height[i]<temp)
            {
                result+=temp-height[i];
            }
            else
                temp = height[i];
        }
        temp = height[height.size()-1];
        for(int i = height.size()-1; i >= index; i--)
        {
            if(height[i]<temp)
            {
                result+=temp-height[i];
            }
            else
                temp = height[i];
        }
        return result;
    }
};
```




