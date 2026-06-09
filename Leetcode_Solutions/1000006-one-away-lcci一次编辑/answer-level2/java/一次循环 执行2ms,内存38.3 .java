### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/093517e8997678833ea0c4a8c99414375c15d267afe6ea57936ab1671b24aa62-image.png)
循环长的，如果相同，就长短都看下一个。如果不相同，长的看下一个。如果出现2次不同，则失败。
前面先过滤掉长度相差2个以上的。

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
		if(first==null||second==null)return false;
		int firstLen = first.length();
		int secondLen = second.length();
		boolean isSameLen = firstLen == secondLen;
		if(firstLen+1<secondLen || firstLen > secondLen + 1)return false;
		if("".equals(first) || "".equals(second))return true;
		String longStr, shortStr;
		if(secondLen>firstLen){
			longStr = second;
			shortStr = first;
		}else{
			longStr = first;
			shortStr = second;
		}
		boolean hasNotSame = false;
		for(int i=0,j=0;i<longStr.length();i++){
			if(longStr.charAt(i) == shortStr.charAt(j)){
				if(++j==shortStr.length())return true;
			}else{
				if(hasNotSame)return false;
				hasNotSame = true;
				if(isSameLen){
					if(++j==shortStr.length())return true;
				}
			}
		}
        return true;
    }
}
```