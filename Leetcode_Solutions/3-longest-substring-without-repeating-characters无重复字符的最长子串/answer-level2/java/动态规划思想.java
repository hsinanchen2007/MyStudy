### 解题思路
此处撰写解题思路
动态规划思想：f(i)表示第i个字符为结尾的不包含重复字符的最长长度。
（1）若第i个字符之前没有出现过，则f(i)=f(i-1)+1;
(2)若出现过，则分两种情况：1.第i个字符下标和它上次出现位置的距离d<=f(i-1):则f(i)=d;
                        2.d>f(i-1):则f(i)=f(i-1)+1;

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s==null||s.length()==0) {
			return 0;
		}
		//元素值代表出现位置
		int[] position=new int[128];
		for(int i=0;i<128;i++) {
			position[i]=-1;
		}
		char[] chars=s.toCharArray();
		int curLength=0,maxLength=0;
		for(int i=0;i<chars.length;i++) {
			int prevIndex=position[chars[i]];
			if(prevIndex<0||i-prevIndex>curLength) {
				curLength++;
			}else {
				if(curLength>maxLength) {
					maxLength=curLength;
				}
				curLength=i-prevIndex;
				
			}
			position[chars[i]]=i;
			
			
		}
		if(curLength>maxLength) {
			maxLength=curLength;
		}
		return maxLength;
		
		

    }
}
```