### 解题思路
1.双指针遍历
2.遍历时对每个字符执行赋值 
3.所谓赋值是若为字母统一转为小写，为非法字符返回空格 

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int head=0;
		int end=s.length()-1;
		char[] ch = s.toCharArray();
		while(head<end) {
			ch[head]=tr(ch[head]);
			ch[end]=tr(ch[end]);
			if(ch[head]!=' '&&ch[end]!=' ') {
				if(ch[head]!=ch[end]) {
					return false;
				}
                head++;
                end--;
			}else {
				head=ch[head]!=' '?head:head+1;
				end=ch[end]!=' '?end:end-1;
			}
		}
		return true;
    }
    public static char tr(char c) {
		if((c>=48&&c<=57)||(c>=65&&c<=91)) {
			return c;
		}
		if((c>=97&&c<=123)) {
			c=(char) (c-32);
			return c;
		}
		return ' ';
	}
}
```