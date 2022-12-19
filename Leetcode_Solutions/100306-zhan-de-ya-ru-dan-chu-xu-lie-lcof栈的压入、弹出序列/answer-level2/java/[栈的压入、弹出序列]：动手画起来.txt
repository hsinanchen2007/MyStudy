*会不会有同学（我承认那个人是我哈哈）第一时间在想：进栈序列是`{1,2,3,4,5}`出栈序列难道不肯定是 `{5,4,3,2,1}`吗？*

---
拿示例 1 ：进栈` {1,2,3,4,5}` ,出栈 `{4,5,3,2,1}` 来说

出栈的第一个数字是 4。也就是说 1 进栈，呆着不动，2 进栈，呆着不动，3 进栈，呆着不动，4 进栈，然后发现现在第一个要出栈的是 4 自己，于是 4 出栈。见下图。
![image.png](https://pic.leetcode-cn.com/a68afeb9d5216b2465e4664074ad164b5b9cb7b3290b79906df8c6c4dd183003-image.png)
![image.png](https://pic.leetcode-cn.com/fb1d3a8d9e15c0204336ac816375c23bdd2a83af086ae148dd1cb24655e44b2b-image.png)
![image.png](https://pic.leetcode-cn.com/7730da47d11a196bc753fdb15382be40f0a5fc66baabeab465ce9cd879f5bdde-image.png)
![image.png](https://pic.leetcode-cn.com/9886db71d77d062c2f0de8cbab9cbb5621341d055da6f8884c7e7b1b8a3e2ea3-image.png)
![image.png](https://pic.leetcode-cn.com/447caf709fd497353bd14ab01d8e8ce06ab4faeef591a79d939d91bcedd06ef9-image.png)
![image.png](https://pic.leetcode-cn.com/8376406ebafc9a17297f04518752d480bec15424d75e79753d96b47186321ce2-image.png)
4出完栈，下一个要出栈的数字变成了 5。现在栈里又没有 5，所以继续进栈。（下图）

![image.png](https://pic.leetcode-cn.com/97f2ff3a83d44bc200cd1621e842f956cb8a9c7d43b11e3a15eb971841151ed6-image.png)
接下来由于栈顶变成了 5，而即将出栈的也是 5，所以 5 出栈。栈顶变成了 3，而下一个出栈变成 3，所以 3 出栈。如此往复。（下图）
![image.png](https://pic.leetcode-cn.com/632b6c08e81c865738f8ad1803c94ff332da53bfbf439a27d9720efd743c2282-image.png)
![image.png](https://pic.leetcode-cn.com/e15c7573b4922048fc5808398d81fceba22dbd46d8dc1d2d0ce1ae2aa28ea0cb-image.png)
![image.png](https://pic.leetcode-cn.com/5a6729d5c5347e0e9bbb5608394f6c0bfa20a2653e1b077f5cfc74cd82f9a8a0-image.png)
![image.png](https://pic.leetcode-cn.com/4a068d3481ee28d420c75050ea065439101573af8f1d1da6730123ca1714ad77-image.png)
![image.png](https://pic.leetcode-cn.com/8e3ab79bd55b615d4f635225e99887590f6a392fac2331df49df500ff8b30744-image.png)

那么什么时候返回 false 呢？就是当最后栈中还有剩下的元素。

附代码：
```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {

        Stack<Integer> stack=new Stack<>();
        int j=0;
        for(int push:pushed){
            stack.push(push);
            while(!stack.isEmpty()&&stack.peek()==popped[j]){
                stack.pop();
                j++;
            }
        }
        
        return stack.isEmpty();
    }
}
```
























