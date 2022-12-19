### 解题思路
这个解法性能虽然没有双指针那么好，但也可以通过

因为面积由短板决定

所以对于每块板，从两端开始找第一块比它长的木板，

这样就能保证两块木板一定是左边和右边距离短板最远的

然后取最远的那块木板，更新ans。

### 代码

```cpp
class Solution {
public:

    int maxArea(vector<int>& height) 
    {
        int n = height.size(), ans = 0;

        for(int i = 0; i < n; i++)
        {
            int j, k;
            for(j = 0; j < i ; j++)
            if(height[j] >= height[i])
                break;

            for(k = n - 1; k > i && k - i >=  i - j; k--)
            if(height[k] >= height[i])
                break;
            
            ans = max(ans, height[i] * max(k - i, i - j));
        }

        return ans;
        
    }
};
```