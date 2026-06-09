
![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/593609dcde6a5c395c3dec5fb2888f489e8ed1cd17b9cc042dfae398073581c5-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)
### 代码

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return !(
            //在第一个矩形上方
            rec2[1]>=rec1[3] ||
            //在第一个矩形下方
            rec2[3]<=rec1[1] ||
            //在第一个矩形左方
            rec2[2]<=rec1[0] ||
            //在第一个矩形右方
            rec2[0]>=rec1[2]
        );

    }
}
```