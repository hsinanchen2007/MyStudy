####  方法：栈
如果不会发生碰撞那么一排小行星是处于稳定的状态。若在右边增加一个新的小行星后，在它再次稳定之前，可能会发生更多的碰撞，而所有的这些碰撞（如果发生的话）都必须从右到左发生。这种情况非常适合用栈解决。

**算法：**
- 假设栈中顶部元素为 `top`，一个新的小行星 `new` 进来了。如果 `new` 向右移动（`new>0`），或者 `top` 向左移动（`top<0`），则不会发生碰撞。
- 否则，如果 `abs(new) < abs(top)`，则新小行星 `new` 将爆炸；如果 `abs(new) == abs(top)`，则两个小行星都将爆炸；如果 `abs(new) > abs(top)`，则 `top` 小行星将爆炸（可能还会有更多小行星爆炸，因此我们应继续检查）。

```Python
class Solution(object):
    def asteroidCollision(self, asteroids):
        ans = []
        for new in asteroids:
            while ans and new < 0 < ans[-1]:
                if ans[-1] < -new:
                    ans.pop()
                    continue
                elif ans[-1] == -new:
                    ans.pop()
                break
            else:
                ans.append(new)
        return ans
```

```Java [ ]
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack();
        for (int ast: asteroids) {
            collision: {
                while (!stack.isEmpty() && ast < 0 && 0 < stack.peek()) {
                    if (stack.peek() < -ast) {
                        stack.pop();
                        continue;
                    } else if (stack.peek() == -ast) {
                        stack.pop();
                    }
                    break collision;
                }
                stack.push(ast);
            }
        }

        int[] ans = new int[stack.size()];
        for (int t = ans.length - 1; t >= 0; --t) {
            ans[t] = stack.pop();
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是行星的数量。
* 空间复杂度：$O(N)$，`ans` 使用的空间。