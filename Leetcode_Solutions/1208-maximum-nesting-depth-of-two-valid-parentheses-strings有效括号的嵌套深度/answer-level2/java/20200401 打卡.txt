### 解题思路
维护两个栈分别保存A，B两个序列中没有被匹配到的"("
而后开始遍历字符串,seq[i] 无非就是两种情况
    1. seq[i]='(' 时，挑选一个栈进入，因为题目要求A，B的整体深度最小，所以这个时候，应该挑选栈内元素最少的进栈
    2. seq[i]=')' 时，挑选一个栈将栈顶弹出，完成配对，因为题目要求A，B的整体深度最小，所以这个时候应该挑栈内元素最多的出栈


### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        char[] seqArray = seq.toCharArray();
        Stack<Character> stackA = new Stack<>();
        Stack<Character> stackB = new Stack<>();
        res[0] = 0;
        stackA.push(seqArray[0]);
        for (int i = 1; i < seqArray.length; i++) {
            if (seqArray[i] == '(') {
                if (stackA.size() > stackB.size()) {
                    res[i] = 1;
                    stackB.push('(');
                } else {
                    res[i] = 0;
                    stackA.push('(');
                }
            } else {
                if (!stackA.isEmpty() && !stackB.isEmpty()) {
                    if (stackA.size() < stackB.size()) {
                        stackB.pop();
                        res[i] = 1;
                    } else {
                        stackA.pop();
                        res[i] = 0;
                    }
                } else if (!stackA.isEmpty()) {
                    stackA.pop();
                    res[i] = 0;
                } else {
                    stackB.pop();
                    res[i] = 1;
                }
            }
        }
        return res;
    }
}
```