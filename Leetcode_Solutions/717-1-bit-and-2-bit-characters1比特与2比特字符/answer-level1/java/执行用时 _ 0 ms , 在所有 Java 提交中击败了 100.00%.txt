### 解题思路
判断最后一个元素是否是10
从头遍历数组，遇到1就跳过下一个

### 代码

```java
class Solution {
    public boolean isOneBitCharacter(int[] bits) {

        for(int i=0;i<bits.length;i++) {
			int count =0;
			if(bits[i]==1) {
				i++;
				count++;
			}
			if(i==bits.length-1) {
				return count==0;
			}
		}
		return false;
    }
}
```