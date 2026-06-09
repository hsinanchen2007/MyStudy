解题思路：
    整个水池走四遍
    1. 从左往右走，以当前最高边为后面储水
    2. 从右往左，同样以最高边储水
    3. 空水池储水一遍
    4. 最高边满水存一遍
    5. 最后结果等于  结果1+结果2-结果3-结果4
    6. 整个过程可以缩减到两次遍历

```
class Solution {
    public int trap(int[] height) {
        int len = height.length;
        if (len == 0 || height == null){
            return 0;
        }
        
        int l = 0;
        int r = 0;
        int left_empty = 0;
        int right_full = 0;
        
        for(int h : height){
            if(h > l){
                l = h;
            }
            left_empty += l - h;
        }
        for(int i = len - 1; i >= 0; i--){
            if(height[i] > r){
                r = height[i];
            }
            right_full += r - l;
        }
        return right_full + left_empty;
    }
}
```
缩减过代码
right_full 表示 结果2-结果4
left_empty 表示 结果1-结果3