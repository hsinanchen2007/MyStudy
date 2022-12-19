### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> commonChars(String[] A) {
      StringBuffer[] sb = new StringBuffer[A.length];
        ArrayList<String> list = new ArrayList<String>();
        for(int i=0;i<A.length;i++) {
        	sb[i]=new StringBuffer(A[i]);
        }
        for(int i=0;i<sb[0].length();i++) {
        	int j=1;
        	for(j=1;j<sb.length;j++) {
        		if(sb[j].indexOf(sb[0].charAt(i)+"")==-1) {
        			break;
        		}else {
        			sb[j].deleteCharAt(sb[j].indexOf(sb[0].charAt(i)+""));
        		}
        	}
        	if(j==sb.length) {
        		list.add(sb[0].charAt(i)+"");
        	}
        }
		return list;  
    }
}
```