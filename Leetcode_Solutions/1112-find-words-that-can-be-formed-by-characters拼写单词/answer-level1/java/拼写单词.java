### 解题思路
此处撰写解题思路
直接暴力法
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
		int length=0,num;
		char[] ch1=chars.toCharArray();
		char[] ch2=new char[ch1.length];
		for(int i=0;i<words.length;i++) {
			for(int t=0;t<ch1.length;t++) {
				ch2[t]=ch1[t];
			}
			num=0;
			char[] ch=words[i].toCharArray();
			for(int j=0;j<ch.length;j++) {
				for(int k=0;k<ch2.length;k++) {
					if(ch2[k]==ch[j]) {
						ch2[k]=' ';
						num++;
						break;
					}
				}
				if(num==0) {
					break;
				}
			}
			if(num==ch.length) {
				length+=num;
			}
		}
		return length;
    }
}
```