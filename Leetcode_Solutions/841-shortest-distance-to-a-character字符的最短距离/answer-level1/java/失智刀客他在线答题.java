### 解题思路
执行用时 :
9 ms
, 在所有 java 提交中击败了
16.17%
的用户
内存消耗 :
36.3 MB
, 在所有 java 提交中击败了
83.62%
的用户

### 代码

```java
class Solution {
    public int[] shortestToChar(String S, char C) {
     int [] res=new int[S.length()];
	        for(int i=0;i<res.length;i++)res[i]=-1;
	        	
	        char [] S_char=S.toCharArray();
	        ArrayList<Integer> equals=new ArrayList<>();
	        for(int i=0;i<S_char.length;i++) {
	        	if(S_char[i]==C) {
	        		equals.add(new Integer(i));
	        		res[i]=0;
	        	}
	        }
	        for(int n=0;n<S_char.length;n++) {
	        	if(res[n]==-1) {
	        		int min=S_char.length-1;
	        for(int m=0;m<equals.size();m++) {
	        	if(Math.abs(equals.get(m)-n)<min) {
	        		min=Math.abs(equals.get(m)-n);
	        	}
	        	
	        }
	        res[n]=min;
	        	}
	        }
	        
	        return res;
	    }
}
```