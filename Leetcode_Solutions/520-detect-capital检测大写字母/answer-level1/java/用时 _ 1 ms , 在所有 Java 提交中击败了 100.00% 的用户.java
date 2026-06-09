### 解题思路
先判断除了首字母后的字母是否全为大写或小写
判断首字母是否为大写
为大写判断后面是否全为小写或大写
为小写判断是否全为小写

### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        char[] ch = word.toCharArray();
		boolean allBig =true;
		boolean alllow =true;
		boolean res ;
		for(int i=1;i<ch.length;i++) {
			if(ch[i]-'a'<0) {
				alllow=false;
			}else {
				allBig=false;
			}
		}
		if(ch[0]-'a'<0) {
			res = allBig||alllow?true:false;
		}else {
			res = alllow?true:false;
		}
		return res;
    }
}
```