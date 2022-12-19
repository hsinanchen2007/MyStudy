### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
         if(rec1[0]>=rec2[2]){
            return false;
        }else if(rec1[1]>=rec2[3]){
            return false;
        }else if(rec1[3]<=rec2[1]){
            return false;
        }else if(rec1[2]<=rec2[0]){
            return false;
        }else{
            return true;
        }
   }
}
```