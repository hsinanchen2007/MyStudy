### 解题思路
如果两个矩形不相交，那么有且仅有以下四种情况：A在B左边，B在A左边，A在B上边，B在A上边。
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int zuo1=rec1[0];
        int xia1=rec1[1];
        int you1=rec1[2];
        int shang1=rec1[3];
        int zuo2=rec2[0];
        int xia2=rec2[1];
        int you2=rec2[2];
        int shang2=rec2[3];
        if(zuo1>=you2||you1<=zuo2||shang1<=xia2||xia1>=shang2)
        return false;
        return true;
    }
}
```