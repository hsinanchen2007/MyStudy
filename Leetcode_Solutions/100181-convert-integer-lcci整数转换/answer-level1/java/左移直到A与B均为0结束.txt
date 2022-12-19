### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int convertInteger(int A, int B) {
        int count = 0;
		System.out.println(1<<31);
		while ((A!=0) || (B!=0)) {
			if ((A & (1<<31)) != (B & (1<<31))) {
				count++;
			}
			A <<= 1;
			B <<= 1;
		}
		return count;
    }
}
```