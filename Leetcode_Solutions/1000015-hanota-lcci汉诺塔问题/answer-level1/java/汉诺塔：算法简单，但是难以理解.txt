### 解题思路
汉诺塔算法是一个经典的递归算法，在上数据结构或者算法导论的时候，老师肯定都会讲的。算法总共就三步
1.如果只有一个碟子，那么直接从A-C
2.如果有n个碟子，那么先将上面n-1个碟子从A由C移到B，再把第n个碟子从A移到C
3.最后把n-1个碟子从B由A移到C


### 代码

```java
class Solution {
    public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
        hanoi(A.size(), A, B, C);
    }

    private void hanoi(int n, List<Integer> A, List<Integer> B, List<Integer> C) {
        if (n > 0) {
            //先将前n-1个碟子由A通过C移到B
            hanoi(n - 1, A, C, B);
            //将第n个碟子由A移到C
            move(A, C);
            //最后将前n-1个碟子由B通过A移到C
            hanoi(n - 1, B, A, C);
        }
    }

    private void move( List<Integer> A, List<Integer> B) {
        B.add(A.remove(A.size() - 1));
    }
}
```