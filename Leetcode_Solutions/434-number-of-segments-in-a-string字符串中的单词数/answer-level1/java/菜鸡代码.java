### 解题思路
没有思路，垃圾一个

### 代码

```java
class Solution {
	  public int countSegments(String s) {
String ss=s.strip();
int length=ss.length();
int count=0;
if(length==0) return 0;
		for(int i=0;i<length;i++) {
			if(ss.charAt(i)==' '&&ss.charAt(i+1)!=' ') {
				count++;
			}
			
		}
		if(ss.charAt(length-1)!=' '){
			count++;
		}
		
		return count;
    }
}
```