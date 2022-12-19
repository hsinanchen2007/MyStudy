执行用时 : 13 ms, 在ZigZag Conversion的Java提交中击败了89.85% 的用户

内存消耗 : 40.4 MB, 在ZigZag Conversion的Java提交中击败了84.30% 的用户

第一行和最后一行的规律为 a0=当前行，an = an-1+ 2*numRows-2

其他行为 a0=当前行， 偶数列 an = an-1+(numRows-当前行)*2 ，奇数列an = an-1+当前行*2

所以根据以下规律

```java []
int length = s.length();
    	if(numRows == 1) {
    		return s;
    	}
        char[] c = s.toCharArray();
    	StringBuffer result = new StringBuffer();
        for(int i = 1 ; i <= numRows; i++ ) {
        	int n = i-1;
        	if(i == 1 || i == numRows) {
        		while(n < length) {
        			result.append(c[n]);
        			n += 2*numRows-2;
        		}
        	}else {
        		int j = 2;
        		while(n < length) {
        			result.append(c[n]);
        			if(j%2 == 0) {
        				n += (numRows-i)*2;
        			}else {
        				n +=(i-1)*2;
        			}
;        			j++;
        		}
        		
        	}
        	
        }
        return result.toString();
```
