执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.1 MB, 在所有 Java 提交中击败了5.49%的用户
### 解题思路
题目求重叠，我们思考不重叠的情况，那么剩下的只能是重叠的情况。
### 代码
```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
		// 排除不重叠的情况，则其他情况全都重叠。
		
		if(rec1[1]>=rec2[3]||rec2[1]>=rec1[3]||rec1[2]<=rec2[0]||rec2[2]<=rec1[0])
			return false ;
		
		return true;
    }
}
```