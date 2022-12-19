### 解题思路
 1.第一眼看题意觉得挺麻烦，只给了两个点，太复杂
 2.注意看提示，只考虑正着摆放,就很容易理解了
 3.根据题意，点和线相交都不算交集，反向思维，找出不交集的情况，取反就行了
 4.不交集的情况，就是放在另外一个方形的外面（左边 上边 右边 下边）

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1 == null || rec2 == null){
            return false;
        }
        // 从题意要考虑交集，且都是正着摆放,考虑不没有交集的情况 左 上 右 下
        //  (x1,y2)    (x2,y2)      (n1,m2)    (n2,m2)
        //  (x1,y1)    (x2,y1)      (n1,m1)    (n2,m1)

        boolean isLeft = rec1[2] <= rec2[0];
        boolean isTop = rec1[1] >= rec2[3];
        boolean isRight = rec1[0] >= rec2[2];
        boolean isBottom = rec1[3] <= rec2[1];
        return !(isLeft || isTop || isRight || isBottom);
    }
}
```