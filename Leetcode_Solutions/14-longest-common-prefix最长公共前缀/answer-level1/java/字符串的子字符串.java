### 解题思路
此处撰写解题思路
在字符串数组里，取第一个字符串里的子字符串（第一次长度为1），从后面的字符串里找当前子字符串得索引，索引为0，说明找到了相同位置的子字符串，索引是其他的就说明没有这个相同位置的子字符串。
还有一个问题是当没找到时就不需要在继续进行下去，这时候内部for循环结束，外部for循环也应该停止，而外部for循环停止必须得是内部没找到时候的停止，而不是内部全部循环一遍都找到的这种停止，所以设计了标志位flag。flag=0是当前的子字符串全部找到，把这个子字符串复制出来；flag=1是当前的子字符串没有在所有字符串中的相同位置，结束当前的外部for循环。
### 代码

```java
class Solution {
    public static String longestCommonPrefix(String[] strs) {
        if(strs.length==0) return "";
        if(strs.length==1) return strs[0];
		int index=1;
		int d = 0;
		int flag = 0;//设置的标志位，用于当没有找到相同位置时，作为后续的判断标志。
		for(;index<=strs[0].length();index++) {
			String p = strs[0].substring(0, index);//取的子字符串，
			for(int i=1;i<strs.length;i++) {
				int k = strs[i].indexOf(p);
	        	if(k!=0) {
	        		flag =  1;
	        		break;
	        	}
	        }
			if(flag==0) d = index;
			if(flag==1) break;
		}
        return strs[0].substring(0, d);
        
    }
}
```