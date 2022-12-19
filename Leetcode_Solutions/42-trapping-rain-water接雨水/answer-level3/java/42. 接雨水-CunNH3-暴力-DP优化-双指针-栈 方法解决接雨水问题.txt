### 1 brute force
对于每一个height[i]向左向右遍历,找到左右的最大值
两个最大值的短板就是当前水的高度
减去柱子高度就是水的容量
```
// brute force
class Solution {
    public int trap(int[] height) {
        int res = 0;
        int N = height.length;
        for(int i = 0; i < N; i++){
            int leftmax = height[i];
            int rightmax = height[i];
            for(int j = i - 1; j >= 0; j--){
                leftmax = Math.max(leftmax, height[j]);
            }
            for(int j = i + 1; j < N; j++){
                rightmax = Math.max(rightmax, height[j]);
            }
            res += Math.min(leftmax, rightmax) - height[i];
        }
        return res;
    }
}
```
### 2 DP优化
用两个数组记录左右最大值
```
//DP初级, 用空间换取时间 
使用left[],right[]数组来保存当前结点的左右最大值
class Solution {
    public int trap(int[] height) {
         if (height == null || height.length < 3) {
            return 0;
        }
        int res = 0;
        int N = height.length;
        int[] left = new int[N];
        int[] right = new int[N];
        
        left[0] = height[0];
        right[N - 1] = height[N - 1];
        
        for(int i = 1; i < N; i++){
            left[i] = Math.max(left[i-1], height[i]);
        }
        for(int i = N - 2; i >= 0; i--){
            right[i] = Math.max(right[i + 1], height[i]);
        }
        for(int i = 1; i < N; i++){
            res += Math.min(left[i], right[i]) - height[i];
        }
        return res;
    }
}
```
#### 3 双指针
[来自于Lucien的分析
](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/327718)
1. 双指针算法由上述算法优化而来
2. 维护四个指针`leftmax,left,right, rightmax`
    left_max：左边的最大值，它是从左往右遍历找到的
    right_max：右边的最大值，它是从右往左遍历找到的
    left：从左往右处理的当前下标
    right：从右往左处理的当前下标

3. 对于位置left而言，它左边最大值一定是left_max，**右边最大值“大于等于”right_max，这时候，如果left_max<right_max成立，那么它就知道自己能存多少水了。无论右边将来会不会出现更大的right_max，都不影响这个结果。** 所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。

定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。

定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。（见下图，由于中间状况未知，对于left下标而言，right_max未必就是它右边最大的值）

定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。
```
                                   right_max
 left_max                             __
   __                                |  |
  |  |__   __??????????????????????  |  |
__|     |__|                       __|  |__
        left                      right
```
```
// 双指针
class Solution {
    public int trap(int[] height) {
        int res = 0;
        int N = height.length;
        
        int left = 0, right = N - 1;
        int leftmax = 0, rightmax = 0;
        
        while(left <= right){
            if(leftmax < rightmax){
                leftmax = Math.max(leftmax, height[left]);
                res += leftmax - height[left];
                left++;
            }
            else{
                rightmax = Math.max(rightmax, height[right]);
                res += rightmax - height[right];
                right--;
            }
        }
        return res;
    }
}
```
### 4 单调栈的应用
```
// 栈的应用
class Solution {
    public int trap(int[] height) {
        if(height == null){
            return 0;
        }
        int N = height.length;
        Stack<Integer> stack = new Stack<>();
        int res =  0;
        for(int i = 0; i < N; i++){
            while(!stack.isEmpty() && height[stack.peek()] < height[i]){
                int curIdx = stack.pop();
                while(!stack.isEmpty() && height[stack.peek()] == height[curIdx]){
                    stack.pop();
                }
                if(!stack.isEmpty()){
                    int stackTop = stack.peek();
                    res += (Math.min(height[stackTop], height[i]) - height[curIdx]) * (i - stackTop - 1);
            }
                
            }

            stack.push(i);
        }
        return res;
    }
}
```

