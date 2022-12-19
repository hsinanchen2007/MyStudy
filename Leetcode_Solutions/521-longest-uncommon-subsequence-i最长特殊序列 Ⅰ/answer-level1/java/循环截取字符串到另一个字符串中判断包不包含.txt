### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findLUSlength(String a, String b) {
        int max = Integer.MIN_VALUE;
        String tmp = "";
        for(int i=0;i<a.length()-1;i++) {
			for(int j=i+1;j<a.length();j++) {
				tmp = a.substring(i, j+1);
				if(b.indexOf(tmp)==-1&&j-i+1>max) {
					max = j-i+1;
				}
			}
		}
        for(int i=0;i<b.length()-1;i++) {
			for(int j=i+1;j<b.length();j++) {
				tmp = b.substring(i, j+1);
				if(a.indexOf(tmp)==-1&&j-i+1>max) {
					max = j-i+1;
				}
			}
		}
        return max==Integer.MIN_VALUE?-1:max;
    }
}
```