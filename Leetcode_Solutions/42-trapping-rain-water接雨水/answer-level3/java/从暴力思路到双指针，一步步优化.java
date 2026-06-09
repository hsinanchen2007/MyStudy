### 解题思路
1. 暴力方法，迭代计算每一个位置 height[i] 可以接的雨水。
计算每一个位置时，扫描找到左边最大的柱子和右边最大的柱子，若该位置的高度大于 `min(leftMax, rightMax)`, 该位置无法存储雨水，否则该位置可以接的雨水量为 `min(leftMax, rightMax) - height[i]`。时间复杂度为 O(n^2)
```java
/**
 * 暴力解法，每次到一个柱子，先扫描左右两侧的最大值
 * @param height
 * @return
 */
public static int trap2(int[] height) {
    if (height == null || height.length < 3) return 0;

    int sum = 0;
    for (int i = 1; i < height.length - 1; i++) {
        int leftMax = 0, rightMax = 0;
        // 找左侧的最大值
        for (int j = 0; j < i; j++) {
            leftMax = Math.max(leftMax, height[j]);
        }
        // 找右侧的最大值
        for (int j = height.length - 1; j > i; j--) {
            rightMax = Math.max(rightMax, height[j]);
        }
        int currMax = Math.min(leftMax, rightMax);
        sum += Math.max(currMax - height[i], 0);
    }
    return sum;
}
```
2. 备忘录
暴力方法时，每次都要重复计算左右两边的最大值，因此可以用备忘录保存起来，以空间换时间。
```java
/**
 * 暴力解法分备忘录优化
 * @param height
 * @return
 */
public static int trap1(int[] height) {
    if (height == null || height.length < 3) return 0;
    int[] leftArr = new int[height.length];
    int[] rightArr = new int[height.length];

    for (int i = 1; i < height.length; i++) {
        leftArr[i] = Math.max(leftArr[i-1], height[i-1]);
    }

    for (int i = height.length - 2; i >= 0; i--) {
        rightArr[i] = Math.max(rightArr[i+1], height[i+1]);
    }
    int sum = 0;
    for (int i = 1; i < height.length - 1; i++) {
        int currMax = Math.min(leftArr[i], rightArr[i]);
        sum += Math.max(currMax - height[i], 0);
    }
    return sum;
}
```
3. 栈解法
当前高度小于等于栈顶高度，入栈，指针后移。
当前高度大于栈顶高度，出栈，计算出当前墙和栈顶的墙之间水的多少，然后计算当前的高度和新栈的高度的关系，重复第 2 步。直到当前墙的高度不大于栈顶高度或者栈空，然后把当前墙入栈，指针后移。
```java
/**
 * 栈的解法
 * @param height
 * @return
 */
public static int trap0(int[] height) {
    if (height == null || height.length < 3) return 0;
    Stack<Integer> stack = new Stack<>();
    int res = 0;
    for (int i = 0; i < height.length; i++) {
        while (!stack.empty() && height[i] > height[stack.peek()]){
            int top = stack.pop(); //
            if (stack.isEmpty()){
                break;
            }
            int currWidth = i - stack.peek() - 1;
            int currHeight = Math.min(height[i], height[stack.peek()]) - height[top];
            res += currHeight * currWidth;
        }
        stack.push(i);
    }
    return res;
 }
```
4. 使用双指针
`max_left[i]` 和 `max_right[i]` 数组中的元素我们其实只用一次，然后就再也不会用到了。可以不用数组，只用一个元素就行了。

```java
/**
 * 双指针
 * @param height
 * @return
 */
public static int trap(int[] height) {
    if (height == null || height.length < 3) return 0;
    int left = 0, right = height.length - 1;
    int leftMax = 0, rightMax = 0;
    int sum = 0;
    while (left < right){
        leftMax = Math.max(leftMax, height[left]);
        rightMax = Math.max(rightMax, height[right]);
        if (leftMax <= rightMax){
            sum += leftMax - height[left];
            left++;
        } else {
            sum += rightMax - height[right];
            right--;
        }
    }
    return sum;
}
```