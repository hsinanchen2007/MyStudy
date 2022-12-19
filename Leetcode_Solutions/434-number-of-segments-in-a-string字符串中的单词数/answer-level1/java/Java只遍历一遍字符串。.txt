![2019122901.PNG](https://pic.leetcode-cn.com/e7754d5007b7a84d503d4c452464f58cbeeb94d5410551a4956de59077643781-2019122901.PNG)

### 解题思路
1)考虑字符串的长度为0;
2)考虑字符串长度为1;
3)考虑遍历到字符串最后一个字符时的情况
### 代码

```java
class Solution {
    public int countSegments(String s) {
    	int right=0;
    	int count = 0;
    	//字符串长度为0;返回0
    	if(s.length()==0) {
    		return 0;
    	}
    	//字符串长度为1:若该字符不为空,则返回1;若该字符为空则返回0
    	if(s.length()==1) {
    		if(s.charAt(0)!=' ') {
    			return 1;
    		}else {
    			return 0;
    		}
    	}
    	//字符串长度大于1
    	if(s.length()>1) {
        	while(right <s.length()) {
        		if(s.charAt(right) !=' ') {
        			if(right==s.length()-1) {
            			if(s.charAt(right-1)!=' '||s.charAt(right)!= ' ') {//字符串遍历到最后一个字符不为空的情况
            				count ++;
            			}
        			}
        			right ++;
        		}else if(s.charAt(right) ==' ') {
        			if(right>0) {
            			if(s.charAt(right-1)!=' ') {
            				count ++;
            			}
        			}
        			right ++;
        		}
        	}
    	}
    	return count;
    }
}
```