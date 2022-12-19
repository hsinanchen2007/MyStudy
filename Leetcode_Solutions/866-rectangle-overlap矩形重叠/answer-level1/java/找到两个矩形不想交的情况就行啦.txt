### 解题思路
此处撰写解题思路
一：两个矩形不想交有四种情况 
1）矩形rec2在矩形rec1的上面 
2）矩形rec2在矩形rec1的下面
3）矩形rec2在矩形rec1的左面
4）矩形rec2在矩形rec1的右面
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1[0]>=rec2[2]){
            return false;
        }
        if(rec1[1]>=rec2[3]){
            return false;
        }
        if(rec1[2]<=rec2[0]){
            return false;
        }
        if(rec1[3]<=rec2[1]){
            return false;
        }
        return true;
    }
}
```