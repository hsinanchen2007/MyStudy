### 解题思路
累乘
两次循环，第一次循环将i左边的元素累乘和
第二次循环将i右边的元素累乘

### 代码

```java
class Solution {
	    public static int[] constructArr(int[] a) {
	    	int [] b=new int[a.length];
	    	int left=1;
	    	for(int i=0;i<b.length;i++){
	    		b[i]=left;
	    		left=left*a[i];
	    		
	    	}
	    	int right=1;
	    	for(int j=b.length-1;j>=0;j--){
	    		b[j]=b[j]*right;
	    		right=right*a[j];
	    	}
	    	
	    	return b;
	    }
}
```