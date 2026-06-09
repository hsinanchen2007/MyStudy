### 解题思路
双指针移动短板

### 代码

```java []
class Solution {
    public int maxArea(int[] height) {
        int N = height.length;
        assert(N >= 2);
        int i = 0, j=N-1;
        int maxV = 0;
        while(i<j){
            int curV = Math.min(height[i], height[j])*(j-i);
            if(curV > maxV){
                maxV = curV;
            }else{
                // move pointers
                if(height[i] > height[j]){
                    --j;
                }else{
                    ++i;
                }
            }
        }
        return maxV;
    }
}
```
```python []
class Solution:
    def maxArea(self, height: List[int]) -> int:
        N = len(height)
        assert(N>=2)

        i, j = 0, N-1
        maxV = 0
        while i<j:
            curV = min(height[i], height[j])*(j-i)
            if curV > maxV:
                maxV = curV
            else:
                if height[i]<height[j]:
                    i+=1
                else:
                    j-=1

        return maxV
```
```c++ []
#include <cassert>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        assert(N>=2);
        // 双指针方法求解
        int i=0, j=N-1;
        int maxV = min(height[i], height[j])*(N-1);
        while(i < j){
            int curV = min(height[i], height[j])*(j-i);
            if(curV > maxV){
                maxV = curV;
            }else{
                if(height[i] > height[j])
                    --j;
                else
                    ++i;
            }
        }
        return maxV;
    }
};
```