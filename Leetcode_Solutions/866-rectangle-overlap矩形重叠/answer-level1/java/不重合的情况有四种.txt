### 解题思路
分四种情况讨论
1. 第二个在第一个的右边，即第二个的左边的x >= 第一个右边的x
2. 在左边，第一个左边的x >= 第二个右边的x
3. 上下同理
### 代码

```java
class Solution {
	    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
	        boolean a =  rec2[0]>=rec1[2]||rec2[2]<=rec1[0]||rec2[1]>=rec1[3]||rec2[3] <=rec1[1];
	        return !a;
	   }   }
```