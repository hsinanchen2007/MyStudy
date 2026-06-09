### 题解

> 括号序列和树就是一体两面，这属于 well-known fact          ——SAM Qingchuan Zhang [@QingchuanZhang-Microsoft](/u/qingchuanzhang-microsoft/)

---
     
大白话： 这层给a，下层给b，层数奇偶，保证嵌套深度最大值最小，最优也就切一半，看图比较好理解，$(\ )$ 就是根，里面几个同级括号就是几个子节点，碰到左括号说明有子节点，level+1，碰到右括号，level-1。
![image.png](https://pic.leetcode-cn.com/4f19df3c097633d66dbfae414dd8a6d022bcd68e06274eb71e9973981f486be1-image.png)




```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] res = new int[n];
        int level = 0;
        for(int i = 0; i < n; i++){
            if(seq.charAt(i) == '('){
                res[i] = level % 2;
                level++;
            }else{
                level--;
                res[i] = level % 2;
            }
        }
        return res;
    }
}
```