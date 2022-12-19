### 解题思路
首先理解一下题目：一定要交换位置以后相等才算是true
所以有几种情况返回为true：
1.字符串相等，但是有相同的字母
2.字符串不相等，交换两个字母以后相等

### 代码

```java
class Solution {
    public boolean buddyStrings(String A, String B) {
    	if (A.length() != B.length()) {
			return false;
		}
    	if (A.length() < 2) {
			return false;
		}
    	char[] a = A.toCharArray();
    	char[] b = B.toCharArray();
    	if (A.equals(B)) {
        	for (int i = 0; i < a.length - 1; i++) {
    			for (int j = i + 1; j < a.length; j++) {
    				if (a[i] == a[j]) {
    					return true;
    				}
    			}
    		}
        	return false;
		}
    	for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) {
				for (int j = i + 1; j < b.length; j++) {
					if (a[i] == b[j]) {
						char temp = a[i];
						a[i] = a[j];
						a[j] = temp;
						return Arrays.toString(a).equals(Arrays.toString(b));
					}
				}
				return false;
			}
		}

    	return false;
    }
}
```