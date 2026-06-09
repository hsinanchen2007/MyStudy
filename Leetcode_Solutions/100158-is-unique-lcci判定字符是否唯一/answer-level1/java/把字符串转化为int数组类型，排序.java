### 解题思路
创建一个int数组类型对象s,把字符串中的字符全转化为ASCII或其他数字形式并赋值给s,对s进行排序，遍历s，判断s有没有相等的数字

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
		if(astr.length()<2)return(true);else{
		int []s = new int[100];
		for(int i = 0 ; i < astr.length() ; i++){
			s[i] = astr.codePointAt(i);
		}
		Arrays.sort(s,0,astr.length());
		for(int j = 1 ; j < astr.length() ; j++){
			if(s[j]==s[j-1]){
				return(false);
			}
		}
		return(true);
		}
    }
}
```