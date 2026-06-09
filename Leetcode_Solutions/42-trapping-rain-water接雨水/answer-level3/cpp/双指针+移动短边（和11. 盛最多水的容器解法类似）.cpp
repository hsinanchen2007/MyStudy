![Screen Shot 2020-01-31 at 11.45.36 PM.png](https://pic.leetcode-cn.com/307136c35bb8c0bd757f5db11f64d627f6989128584696c5977599e681cd5f7a-Screen%20Shot%202020-01-31%20at%2011.45.36%20PM.png)

解题思路：
1. 水坑的深度总是由短边决定，指针在两端，记录短边，向中间移动短边指针。（从浅到深遍历水坑，时间复杂度O(n)。）
2. 比较短边和当前水坑深度，如果短边小于水坑深度，说明短边在水坑内，面积+=水坑深度-短边高度。
3. 如果短边高于水坑深度，说明可能出现更深的水坑，水坑深度=短边高度。


C++代码：
```
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()<3) return 0;
        int l=0,r=height.size()-1;
        int ret=0;
        int p;
        int depth=0;
        while (l<r){
            if (height[l]<=height[r]){
                p=l;
                l++;
            }else{
                p=r;
                r--;
            }
            depth=max(depth,height[p]);
            if (depth>height[p]){
                ret+=depth-height[p];
            }
        }
        return ret;
    }
};

```