
**update: 公众号和知乎专栏刚刚更新了[《接雨水问题的超完全手册》](https://mp.weixin.qq.com/s/f9ebzbwym8jQeUDxjeCDA)从暴力、dp、双指针、单调栈，吐血总结，秒懂～～**

-----

🙋🙋今日打卡

🖤大佬们随手关注下我的wx公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】 
更多题解干货等你来～～

单调栈不太好说，我做了gif图，下面也有单调栈的实际计算过程，希望有助于理解。

我们可以先看一下gif图：
![water.gif](https://pic.leetcode-cn.com/7d5ff9af88634d417d7925e8987b7db92d3a26766bd9078215ab63df424fa745-water.gif)

看gif图我们可以发现，遍历到某些柱子的时候，会由于和之前的某个柱子形成凹形的坑，接住雨水。
这道题目可以用单调栈来做。**单调栈就是比普通的栈多一个性质，即维护一个栈内元素单调。**
比如当前某个单调递减的栈的元素从栈底到栈顶分别是：`[10, 9, 8, 3, 2]`，如果要入栈元素`5`，需要把栈顶元素pop出去，直到满足单调递减为止，即先变成`[10, 9, 8]`，再入栈`5`，就是`[10, 9, 8, 5]`。


我们为这道题演示一下`[4, 3, 1, 0, 1, 2, 4]`是怎么接雨水的，下图是最终的接雨水效果，蓝色部分是雨水。
![image.png](https://pic.leetcode-cn.com/1d1c62807d886ac9a10229cbae229465989bd6aa707449e9620a639772ba3f07-image.png)

可以看下下面的图示。图示最上方是每个柱子的高度。左侧是单调栈的元素，`0`是栈顶。图中有红色边框的柱子是存在单调栈里的元素。
遍历到图示中箭头所指向的位置时，栈内元素是`[4, 3, 1, 0]`。由于当前的柱体的`1`大于栈顶元素`0`，那就可以接住雨水。接住雨水的量的高度是栈顶元素和左右两边形成的高度差的min。宽度是`1`。

![image.png](https://pic.leetcode-cn.com/83b78b42212c09b06452e8da21cd137d4a80bbdfbfcd34adff57bceba1003836-image.png)

到下一个柱体高度为`2`时，栈内元素是`[4, 3, 1, 1]`。由于当前的柱体的`2`大于栈顶元素`1`，那就可以接住雨水。由于栈顶元素有相等的情况，所以可以把`1`全都pop出去，变成`[4, 3]`。此时最后一个pop出去的是`1`，高度是此时的栈顶元素和当前`2`柱体的高度的min再减去当前的`1`，宽度是`1`那个数字的位置和当前`2`柱体所在位置的差值。 可以算出来此次接住的雨水是1 * 3。

![image.png](https://pic.leetcode-cn.com/ff41c19058478bcbb2bef149e336360dec67f7941428b99fe46026e4e010d991-image.png)

在下一个柱体高度为`4`时，栈内元素是`[4, 3, 2]`，先把`2`pop出来，栈顶元素`3`所在位置和当前的`4`可以接住雨水，雨水量是 1 * 4。

![image.png](https://pic.leetcode-cn.com/3a812e3ba8322a8addd6870cc04690b761c52f1b8effbcd9cc67f6dc3e8cf2c3-image.png)

但是由于栈顶元素`3`仍然小于当前的`4`,再pop出`3`。栈顶元素`4`所在位置和当前的`4`可以接住雨水，雨水量是 1 * 5：
![image.png](https://pic.leetcode-cn.com/236d6cd02def72dcadf1aaa0f7bbbc767da161795d6702523835127002381a0f-image.png)

这样每个部分的雨水量都可以算出来，加在一起就可以了。由于每个柱体最多入栈出栈一次，所以时间复杂度是 $O(n)$


```java
public class Solution {
    public int trap(int[] height) {
        if (height == null) {
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        int ans = 0;
        for (int i = 0; i < height.length; i++) {
            while(!stack.isEmpty() && height[stack.peek()] < height[i]) {
                int curIdx = stack.pop();
                // 如果栈顶元素一直相等，那么全都pop出去，只留第一个。
                while (!stack.isEmpty() && height[stack.peek()] == height[curIdx]) {
                    stack.pop();
                }
                if (!stack.isEmpty()) {
                    int stackTop = stack.peek();
                    // stackTop此时指向的是此次接住的雨水的左边界的位置。右边界是当前的柱体，即i。
                    // Math.min(height[stackTop], height[i]) 是左右柱子高度的min，减去height[curIdx]就是雨水的高度。
                    // i - stackTop - 1 是雨水的宽度。
                    ans += (Math.min(height[stackTop], height[i]) - height[curIdx]) * (i - stackTop - 1);
                }
            }
            stack.add(i);
        }
        return ans;
    }
}

```

为了加强理解，你还可以去做 [84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)。

为了刷题数，你可以去做 [面试题 17.21. 直方图的水量](https://leetcode-cn.com/problems/volume-of-histogram-lcci/)。ctrl+c，ctrl+v => 通过+1。


以上谢谢大家，**求赞求赞求赞！**

🖤大佬们随手关注下我的wx公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】 
更多题解干货等你来～～