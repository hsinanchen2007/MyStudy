### 解题思路
这题说到底就是模拟，模拟括号生成的过程。题目要求生成`n`对有效括号，我们就模拟我们手动生成的过程：
> 对于`2 * n`个位置，一个位置一个位置去放，每个位置上**左括号**和**右括号**都尝试放一次，每次放完`2 * n`个括号判断这个括号串是否有效，有效就记录下来，然后换一种放法重新来，直到所有的放法都尝试了一遍。

这不就是一个回溯的过程嘛，代码很简单：
```java
/**
 * 回溯核心代码
 * @param index  当前放置括号的位置
 * @param currStr  已经生成的字符串
 * @param n  最终需要生成的括号对数
 */
void backtrack(int index, String currStr, int n) {
    if (index == 2 * n) {
        // TODO: 判断currStr是否是有效串，如果是就加入到结果集中
        return;
    }
    // 添加左括号
    backtrack(index + 1, currStr + "(", n);
    // 添加左括号
    backtrack(index + 1, currStr + ")", n);
}
```
上述代码应该很容易得出来，但是显然这种方法有点机械，因为有些时候前期就可以判断得不到有效串，但是仍继续放置：比如在**第一个位置放了右括号**，后面再怎么放最后得到的括号串都是**无效的**。所以我们需要制定一些放置规则来避免这种情况。
我们知道对于一个有效的括号串`str`，左右括号数都是一样的，并且对于`str`中的任意一个位置`i`，在`i`之前，左括号数一定大于或等于右括号数，也就是说我们应该优先放左括号。
基于此，我们可以制定下列规则：
- 如果放置过程中，**左括号数**或**右括号数**超过了**总长度**的一半，显然是不满足条件的；
- 如果**左括号数**不超过**总长度**一半，我们优先放置**左括号**；
- 如果**右括号数**小于**左括号数**，那么可以考虑放置**右括号**；

那么我们可以在第一版回溯方法上加两个参数就行了，记录生成的**左括号数**和**右括号数**，然后在函数体中加上上面的规则就行了。
> ps:  在`Java`中，对于字符串拼接，如果不考虑线程安全，可以考虑用`StringBuilder`，性能比较好

### 代码

```java
class Solution {

    List<String> ans = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        if (n <= 0) {
            return ans;
        }
        generate(0, new StringBuilder(), 0, 0, n);
        return ans;
    }

    
    /**
     * 模拟生成括号
     * @param index   记录当前生成的括号数量
     * @param strBuilder  当前已生成的字符串
     * @param leftCount  生成的左括号数量
     * @param rightCount 生成的右括号数量
     * @param n 最后生成括号的对数
     */
    private void generate(int index, StringBuilder strBuilder, int leftCount, int rightCount, int n) {
        // 左括号数量和右括号数量大于总长度一半，显然不满足
        if (leftCount > n || rightCount > n) {
            return;
        }
        // 已经生成了2 * n个括号，递归结束
        if (index == 2 * n) {
            ans.add(strBuilder.toString());
            return;
        }
        // 如果当前左括号数量小于一半，优先添加左括号
        if (leftCount < n) {
            strBuilder.append("(");
            generate(index + 1, strBuilder, leftCount + 1, rightCount, n);
            strBuilder.deleteCharAt(strBuilder.length() - 1);
        }
        // 如果当前右括号数量小于左括号数量，就添加右括号
        if (rightCount < leftCount) {
            strBuilder.append(")");
            generate(index + 1, strBuilder, leftCount, rightCount + 1, n);
            strBuilder.deleteCharAt(strBuilder.length() - 1);
        }
    }
}
```