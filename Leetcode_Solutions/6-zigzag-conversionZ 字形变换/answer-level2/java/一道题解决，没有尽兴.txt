### 解题思路
思路比较简单，StringBuilder

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if(null==s || s.length()<=1 || numRows==1)
			return s;
		
		StringBuilder[] array = new StringBuilder[numRows];
		
		for (int i = 0; i < array.length; i++) {
			array[i] = new StringBuilder();
		}
		
		int flag = 1;
		int index = 0;
		char[] chars = s.toCharArray();
		
		for(Character c : chars){
			array[index].append(c);
			index += flag;
			if(index==numRows-1 || index==0){
				flag = -flag;
			}
		}
		
		StringBuilder res = new StringBuilder();
		for (int i = 0; i < array.length; i++) {
			res.append(array[i]);
		}
		return res.toString();
    }
}
```
![image.png](https://pic.leetcode-cn.com/692a1b5c99e663f2fffd54e9075af34b3105a27d50ef8d2269e28378019d2cdf-image.png)
