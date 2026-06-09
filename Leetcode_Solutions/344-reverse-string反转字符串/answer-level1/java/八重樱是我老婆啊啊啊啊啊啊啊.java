### 解题思路
执行用时 :
1 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
50.7 MB
, 在所有 java 提交中击败了
82.42%
的用户

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        char temp;
    	int middle=s.length/2-1;
    	int dur=0;
    	if(s.length%2==0) {
    		dur=1;
    	}else {
    		dur=2;
    	}
    	
        for(int i=0;i<s.length/2;i++) {
        	temp=s[middle-i];
        	s[middle-i]=s[middle+i+dur];
        	s[middle+i+dur]=temp;
        }
        
        
    }
}
```