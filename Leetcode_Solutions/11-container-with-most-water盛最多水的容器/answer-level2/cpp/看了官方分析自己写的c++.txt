### 解题思路
我理解是不是可以看成是贪心法？每次都是移动较短的那一边。没有严格证明。

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start(0), end(height.size()-1), max_a(0);
        int area_tmp(0);
        while(start < end){
            area_tmp = min(height[start], height[end]) * (end - start); 
            max_a = max_a > area_tmp ? max_a:area_tmp;
            if(height[start] > height[end]) end--;
            else start++;
        }
        return max_a;
    }
};
```