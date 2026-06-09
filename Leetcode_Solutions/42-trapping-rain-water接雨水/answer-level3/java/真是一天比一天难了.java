### 解题思路
此处撰写解题思路

### 代码

暴力解法
```java
class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int maxLeftHeight = 0;
        int maxRightHeight = 0;
        for(int i = 1; i < height.length - 1; i++){
            maxLeftHeight = height[i];
            for(int j = i; j >=0; j--){
                maxLeftHeight = Math.max(height[j], maxLeftHeight);
            }
            maxRightHeight = height[i];
            for(int j = i; j < height.length; j++){
                maxRightHeight = Math.max(height[j], maxRightHeight);
            }
            ans += Math.min(maxLeftHeight, maxRightHeight) - height[i];
        }
        return ans;
    }
}
```
单调栈
```java
class Solution {
    public int trap(int[] height) {
        int ans = 0;
        LinkedList<Integer> stack = new LinkedList<>();
        for(int i = 0; i < height.length; i++){
            while(!stack.isEmpty() && height[stack.peek()] < height[i]){
                int curIdx = stack.pop();
                while(!stack.isEmpty() && height[curIdx] == height[stack.peek()]){
                    curIdx = stack.pop();
                }

                if(!stack.isEmpty()){
                    ans += (Math.min(height[stack.peek()], height[i]) - height[curIdx]) * (i - stack.peek() - 1);
                }
            }
            stack.push(i);
        }
        return ans;
    }
}
```

韦恩图
```java
public class Solution {
    public int trap(int[] height) {
        int leftMax = 0;
        int rightMax = 0;
        int s1 = 0, s2 = 0;
        int n = height.length;
        for(int i = 0; i < n; i++){
            if(height[i] > leftMax){
                leftMax = height[i];
            }
            s1 += leftMax;
            if(height[n - i - 1] > rightMax){
                rightMax = height[n - i - 1];
            }
            s2 += rightMax;
        }

        int sum = 0;
        for(int i: height){
            sum += i;
        }
        return s1 + s2 - leftMax*n - sum;
    }
}
```