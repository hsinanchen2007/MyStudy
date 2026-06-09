### 解题思路
第I次使用I-1次的结果

### 代码

```java
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> l = new ArrayList<Integer>();
		
//		if(rowIndex == 1) {
//			l.add(1);
//			l.add(1);
//			return l;
//		}
		int[] n = new int[rowIndex/2+1];
		n[0]=1;
		for(int i=2;i<rowIndex+1;i++) {
			for(int j=0;j<i/2+1;j++) {
				if(j==0) {
					n[i/2]=(i)%2==1?n[i/2]+n[i/2-1]:n[i/2-1]*2;
					continue;
				}
				if(j==i/2) {
					n[i/2-j]=1;
					continue;
				}
				n[i/2-j]=n[i/2-j]+n[i/2-j-1];
			}
		}
		
		for(int i=0;i<n.length;i++) {
			l.add(n[i]);
		}
		for(int i=rowIndex%2==1?0:1;i<n.length;i++) {
			l.add(n[n.length-1-i]);
		}
		return l;
    }
}
```