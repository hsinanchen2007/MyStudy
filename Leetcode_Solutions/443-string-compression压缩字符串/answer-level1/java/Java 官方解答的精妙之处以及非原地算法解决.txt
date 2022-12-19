### 解题思路

![IMG_0461.PNG](https://pic.leetcode-cn.com/845dd0dc1eb9d06215515935ad6a7df8977ffd45f51d997983fe7d2f497bfd7c-IMG_0461.PNG)


### 代码

```java
class Solution {
    public int compress(char[] chars) {
    	int anchor=0;
    	int write=0;
    	for(int i=0;i<chars.length;i++) {
		//这一点很好，只有需要写的时候再写，再计算该字符出现了几次
    		if(i==chars.length-1 || chars[i+1]!=chars[i] ) {
    			// 将这个单词起始的字符写下来
    			chars[write]=chars[anchor];
    			write++;
    			if(i>anchor) {
					//这一点也很巧妙，论如何将一个数字转化为char类型
    				for(char c:((i-anchor+1)+"").toCharArray()) {
    					chars[write]=c;
    					write++;
    				}
    			}
    			anchor=i+1;
    		}
    	}
    	return write;
    }
}
```