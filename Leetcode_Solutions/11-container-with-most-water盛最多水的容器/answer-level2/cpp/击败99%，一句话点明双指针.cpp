### 解题思路
注释那里是最关键的说明


### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int heightSize = int(height.size());
        int leftIndex = 0;
        int rightIndex = heightSize - 1;

        while (leftIndex != rightIndex)
        {
            int tmpHeight;
            int tmpWidth = rightIndex - leftIndex;
            //短的一侧向中间移动,直到该侧出现更大的（因为若小的这侧没有出现更大的，则不可能组成面积比当前的更大的情形）
            if (height[leftIndex] < height[rightIndex])
            {
                tmpHeight = height[leftIndex];
                do{
                    leftIndex++;
                }
                while(leftIndex != rightIndex && height[leftIndex] < tmpHeight);
            }
            else
            {
                tmpHeight = height[rightIndex];
                do{
                    rightIndex--;
                }
                while(leftIndex != rightIndex && height[rightIndex] < tmpHeight);
            }
            int tmpResult = tmpWidth * tmpHeight;
            if (tmpResult > result)
            {
                result = tmpResult;
            }
        }
        return result;
    }
};
```