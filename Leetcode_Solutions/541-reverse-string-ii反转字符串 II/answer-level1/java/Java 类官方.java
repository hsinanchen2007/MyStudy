### 解题思路

![4.png](https://pic.leetcode-cn.com/5c7583dafae7b51f5f9cc49a2a81e6dabf7ef143d6f34804f156e725ddaadd94-4.png)


### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        char a[] = s.toCharArray();
		for(int start = 0; start<s.length();start+=2*k) {
			int i = start;
			int j = Math.min(start+k-1, s.length()-1);
			for(;i<j;i++,j--) {
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		return new String(a);
    }
}
```