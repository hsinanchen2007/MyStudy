## 题目讲解
**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 递归


**【思路】**
* 假设有n个盘子需要移动
* 首先将最上面的n-1个盘子从A移到B柱子
* 然后将最下面的一个盘子从A移到C柱子
* 最后将n-1个盘子从B移到C柱子
* 以上是汉诺塔的整体操作，其中移动n-1个盘子的操作是递归操作


**【代码】**
```java
class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        move(A.size(),A, B, C);
    }
    public void move(int n, List<Integer> A, List<Integer> B, List<Integer> C){
        if(n == 1){
            C.add(A.remove(A.size() - 1));
            //注意：题目给的盘子是从大到小给的，所以这里remove的是【A.size() - 1】
            return;
        }
        move(n-1,A,C,B);
        C.add(A.remove(A.size() - 1));
        move(n - 1, B, A, C);
    }
}
```

**【备注】**
* 还有一个超级取巧的方法，我们是不建议读者使用的，但是写出来博大家一乐

```java
public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
    C.addAll(A);
    A.clear();
}
```
**【关注我，带你拿大厂offer】**
![logo_gif.gif](https://pic.leetcode-cn.com/92ba708453458754d5f3e512ad8d5003802b3ce5c97987665f883d10556f8a66-logo_gif.gif)
