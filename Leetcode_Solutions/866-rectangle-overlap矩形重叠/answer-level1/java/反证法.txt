### 解题思路
对于数学题，正向解有时过于麻烦，比如说这个题。反证法是一个很好的解题思路。不必纠结于正向if要什么条件，这题返回true的情况太多啦！（亲测几十行if以上，死亡if）
不返回true的情况就很简单了：rec2整个在rec1的上下左右，分别列出条件就好啦
不过我有点奇怪鸭，为什么内存消耗只打败5%的人呢？明明没有怎么开拓新空间？

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec2[0]>=rec1[2]){
            return false;
        }
        if(rec2[1]>=rec1[3]){
            return false;
        }
        if(rec2[3]<=rec1[1]){
            return false;
        }
        if(rec2[2]<=rec1[0]){
            return false;
        }
        return true;
    }
}
```