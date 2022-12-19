# 方法一：暴力
遍历每个元素，寻找右侧第一个比当前元素大的元素，如果找到了，位置记为$biggerIndex$,那么从$biggerIndex$开始的右侧所有元素都要比当前元素大，否则不合法。原因就是能找到右侧比他大的元素，也就是二叉搜索树中到达了右子树，那么就要保证当前元素要比右子树所有元素小。

```java
    public boolean verifyPreorder(int[] preorder) {
        // 遍历每个元素，右侧发现比这个元素大之后，后面必须都要比这个元素大
        int len = preorder.length;
        for (int i = 0; i < len; i++) {
            boolean isBeginBigger = false;
            for (int j = i+1; j < len; j++) {
                if (isBeginBigger && preorder[j] < preorder[i]) {
                    return false;
                }
                if (preorder[j] > preorder[i]) {
                    isBeginBigger = true;
                }
            }
        }

        return true;
    }
```
**复杂度**
时间复杂度：$O(n^2)$
空间复杂度：$O(1)$

# 方法二：单调栈
维护一个单调递减栈（从栈底到栈顶），如某一状态下栈元素为$[5,4,3]$。若碰到一个6的时候，说明从左子树（或者没有左子树）到达了右子树，此时将小于6的元素都pop掉，栈变成$[6]$,并且记录一个最小值为5，由于6是右子树，因此6右侧的元素都必须大于5，否则不合法。
```java
 // 用单调栈的方式，递减栈，当碰到一个数比栈顶元素大的时候，说明从左子树到了右子树。
    // 此时要删掉左子树的所有节点，并且保留子树的根为最小值，此时遍历的所有右子树的节点都必须大于这个根，否则非法
    public boolean verifyPreorder(int[] preorder) {
        int len = preorder.length;
        int[] stack = new int[len];
        int top = -1;
        int min = Integer.MIN_VALUE;

        for (int value : preorder) {
            if (value < min) {
                return false;
            }

            while (top > -1 && value > stack[top]) {
                min = stack[top];
                top--;
            }

            stack[++top] = value;
        }

        return true;
    }
```
**复杂度**
时间复杂度：$O(n)$
空间复杂度：$O(1)$
说明，这里有人会有疑问，代码里头不是有两重循环吗？时间复杂度不是应该是$O(n^2)$？其实不是的虽然有两重循环，但是这里每个元素最多只会进栈一次和出栈一次，也就是复杂度应该是$O(2*n)$，去掉系数也就是$O(n)$，所有单调栈的题目都是类似的。


