### 执行结果
用时0ms,击败了100.00%的用户;
内存39.9MB,击败了100.00%的用户;
### 解题思路
先遍历出数组的大小，记得换算空格处的大小；
再将字符串中的元素填到数组中去。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        int j=0;
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)==' ') {
				j+=3;
			}else {
				j++;
			}
		}
		char [] arr= new char[j];
		int h=0;
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)==' ') {
				arr[h]='%';
				arr[h+1]='2';
				arr[h+2]='0';
				h+=3;
			}else {
				arr[h]=s.charAt(i);
				h++;
			}
		}
		return String.valueOf(arr);
    }
}
```