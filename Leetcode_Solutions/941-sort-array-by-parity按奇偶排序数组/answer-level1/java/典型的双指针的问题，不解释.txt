### 解题思路
1、设出双指针
2、左指针用于存储
3、右指针用于比较
4、右指针到达数组尽头的时候，便把数组分成了一半偶数，一半是奇数

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int c1=0;
	     int c2=0;
	     while(c2<A.length)
	     {
	    	 if(A[c2]%2==0)
	    	 {
	    		int tmp=A[c1];
	    		A[c1]=A[c2];
	    		A[c2]=tmp;
	    		c1++;
	    		c2++;
	    	 }
	    	 else 
	    	 {
	    		 c2++;
	    	 }
	    	
	     }
	     return A;
    }
}
```