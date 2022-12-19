### 解题思路
如果前两个(几个)数相等, 就向后移动,直到找到两个不相等的数,来确定单调性

### 代码

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length==1)return true;
        int index=0;
		while(true){
			if (A[index]>A[index+1]){
				for(int i=1;i<A.length;i++){
					if (A[i-1]<A[i]) 
						return false;			
				}
				return true;
			}
			else if(A[index]<A[index+1]){
				for(int i=1;i<A.length;i++){
					if (A[i-1]>A[i]) 
						return false;	
				}
				return true;
			}
			else{
				index ++;
				if(index==A.length-1)
					return true;
			}
		}
    }
}
```