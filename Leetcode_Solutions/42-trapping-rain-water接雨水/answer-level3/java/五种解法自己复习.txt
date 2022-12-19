### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //逐行扫描法
    public int trap(int[] height) {
        /*int sum = 0;
        for(int i = 1;i<height.length-1;i++){
            int maxLeft = 0;
            for(int l = i - 1;l >=0;l--){
                if(height[l] > maxLeft){
                    maxLeft = height[l];
                }
            }

            int maxRight = 0;
            for(int r = i + 1;r < height.length;r++){
                if(height[r] > maxRight){
                    maxRight = height[r];
                }
            }

            int minHeight = Math.min(maxLeft,maxRight);

            if(minHeight > height[i]){
                sum+=minHeight - height[i];
            }
        }
        return sum;

        //动态规划解法
        int sum = 0;
        int[] max_left = new int[height.length];
        int[] max_right = new int[height.length];
        
        for (int i = 1; i < height.length - 1; i++) {
            max_left[i] = Math.max(max_left[i - 1], height[i - 1]);
        }
        for (int i = height.length - 2; i >= 0; i--) {
            max_right[i] = Math.max(max_right[i + 1], height[i + 1]);
        }
        for (int i = 1; i < height.length - 1; i++) {
            int min = Math.min(max_left[i], max_right[i]);
            if (min > height[i]) {
                sum = sum + (min - height[i]);
            }
        }
        return sum;
        //左右指针解法
        int sum = 0;
        int max_left = 0;
        int max_right = 0;
        int left = 1;
        int right = height.length - 2; // 加右指针进去
        for (int i = 1; i < height.length - 1; i++) {
            //从左到右更
            if (height[left - 1] < height[right + 1]) {
                max_left = Math.max(max_left, height[left - 1]);
                int min = max_left;
                if (min > height[left]) {
                    sum = sum + (min - height[left]);
                }
                left++;
            //从右到左更
            } else {
                max_right = Math.max(max_right, height[right + 1]);
                int min = max_right;
                if (min > height[right]) {
                    sum = sum + (min - height[right]);
                }
                right--;
            }
        }
        return sum;*/
        //栈
        int sum = 0;
        Stack<Integer> stack = new Stack<>();
        int current = 0;
        while (current < height.length) {
            //如果栈不空并且当前指向的高度大于栈顶高度就一直循环
            while (!stack.empty() && height[current] > height[stack.peek()]) {
                int h = height[stack.peek()]; //取出要出栈的元素
                stack.pop(); //出栈
                if (stack.empty()) { // 栈空就出去
                    break; 
                }
                int distance = current - stack.peek() - 1; //两堵墙之前的距离。
                int min = Math.min(height[stack.peek()], height[current]);
                sum = sum + distance * (min - h);
            }
            stack.push(current); //当前指向的墙入栈
            current++; //指针后移
        }
        return sum;
    }
}
```