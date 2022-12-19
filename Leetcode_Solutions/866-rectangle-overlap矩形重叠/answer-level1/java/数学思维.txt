### 解题思路
要先把题意理解了才能做

### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        // if(rec1.length == 0 || rec2.length == 0){
        //     return false;
        // }
        // if((rec1[0] > rec1[2] || rec1[1] > rec1[3]) && (rec2[0] > rec2[2] || rec2[1] > rec2[3])){
        //     return false;
        // }
        // if(!(rec2[0] > rec1[0] && rec2[1] > rec1[1])){
        //     return false;
        // }else{
        //     if(!(rec2[0] < rec1[2] && rec2[1] < rec1[3])){
        //         return false;
        //     }else{
        //         return true;
        //     }
        // }
        return !(rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3]);
    }
}
```