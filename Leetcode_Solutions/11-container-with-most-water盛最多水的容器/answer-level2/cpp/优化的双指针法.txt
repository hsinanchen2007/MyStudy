官方题解中的双指针法，每次移动较短的一边，假设移动后的那一边比移动前的那一边要短的话，所盛的水一定不会比原来多，因为桶矮了并且桶也窄了。
我的解决方法里，每次移动较短的一边，并且一直移动直到找到一个比移动前高的板。
12ms，99.52%。

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int tmpv = 0, maxv = 0;
        int m, n;

        while (i < j)
        {
            tmpv = (j - i) * min(height[i], height[j]);
            maxv = (tmpv > maxv) ? tmpv : maxv;

            if (height[i] < height[j])
            {
                m = i + 1;
                while (m < j && height[m] <= height[i])
                {
                    ++m;
                }
                
                i = m;
            }
            else
            {
                n = j - 1;
                while(n > i && height[n] <= height[j])
                {
                    --n;
                }

                j = n;
            }
        }

        return maxv;
    }
};
```
