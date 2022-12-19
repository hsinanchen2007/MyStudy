### 解题思路
代码就跟思路一样直
### 代码

```java
class Solution {
    public int[] shortestToChar(String S, char C) {
       int count = 0;
		char[] dest = S.toCharArray();
		for(int i = 0;i<dest.length;i++) {
			if(dest[i]==C) {
				count++;
			}
		}
		int[] destc = new int[count];
		int index = 0;
		for(int i = 0;i<dest.length;i++) {
			if(dest[i]==C) {
				destc[index++] = i;
			}
		}
		int[] res = new int[S.length()];
		for(int i =0;i<S.length();i++) {
			int temp = Integer.MAX_VALUE;
			for(int j = 0;j<destc.length;j++) {
				if(Math.abs(i-destc[j])<temp) {
					temp = Math.abs(i-destc[j]);
				}
			}
			res[i] = temp;
		}
		return res;		
    }
}
```