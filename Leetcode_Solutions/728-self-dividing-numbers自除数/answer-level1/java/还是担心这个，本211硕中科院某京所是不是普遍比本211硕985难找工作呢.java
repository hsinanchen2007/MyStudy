### 解题思路
执行用时 :
9 ms
, 在所有 java 提交中击败了
19.51%
的用户
内存消耗 :
35.5 MB
, 在所有 java 提交中击败了
52.03%
的用户

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res_list=new ArrayList<>();
    	x:for(int num=left;num<=right;num++) {
    		if(num<10) {
    			res_list.add(new Integer(num));
    		}else {
    			char [] char_num=String.valueOf(num).toCharArray();//取各位
    			
    			for(int j=0;j<char_num.length;j++) {
    				if(char_num[j]=='0') {
    					continue x;
    				}
    				int chushu=Integer.parseInt(String.valueOf(char_num[j]));
    				if(num%chushu!=0) {
    					
    					continue x;
    				}
    			}
    			res_list.add(new Integer(num));
    			
    			
    		}
    	}
    	
    	
    	
    	
    	return res_list;
    }
}
```