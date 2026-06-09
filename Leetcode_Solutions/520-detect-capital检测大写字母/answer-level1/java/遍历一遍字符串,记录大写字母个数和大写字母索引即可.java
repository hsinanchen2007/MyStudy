![2020020701.PNG](https://pic.leetcode-cn.com/a7ab9763d9eb90d61768b30a836a1752dcea8d2776c8074c6c7f048dc7d7e389-2020020701.PNG)

### 解题思路
声明cnt记录大写字母的个数;
声明index记录大写字母的位置索引;
当cnt==word.length,即所有字母都大写,返回true;
或者,当cnt==1,且index==0,即只有首个字母是大写时,返回true;
或者,当cnt==0,即所有字母均小写时,返回true;
当cnt>1且cnt<word.length时,返回false;
当cnt==1,但index!=0,即有一个大写字母,但该大写字母不在首位,返回false;
### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int cnt = 0;
    	int index = 0;
    	for(int i = 0;i<word.length();i++) {
    		if(word.charAt(i)-'A'<=25) {
    			cnt++;
    			index = i;
    		}
    	}
    	if((cnt==word.length())||(cnt==1&& index ==0)||(cnt==0)) {
    		return true;
    	}
    	if((cnt>1&&cnt<word.length())||(cnt==1&&index!=0)) {
    		return false;
    	}
    	return false;
    }
}
```