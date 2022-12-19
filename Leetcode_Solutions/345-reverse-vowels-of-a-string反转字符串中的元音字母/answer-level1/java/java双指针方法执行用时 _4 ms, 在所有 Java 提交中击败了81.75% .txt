### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
		char[] ch = s.toCharArray();
		char temp=' ';
		for(int i=0,j=ch.length-1;j>i;i++,j--) {
			int a = 0;//是否是元音字母
			if(isVowel(ch[i])) {
				i--;
				a++;
			}
			if(isVowel(ch[j])) {
				j++;
				a++;
			}
			if(a==2) {
				i++;
				j--;
				temp =ch[i];
				ch[i]=ch[j];
				ch[j]=temp;
			}
		}
        return new String(ch);
    }
    public static boolean isVowel(char ch) {
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'
		   ||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') {
			return true;
		}else {
			return false;
		}
	}
}
```