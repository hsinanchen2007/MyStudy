开一个数组标记出现次数即可
```
class Solution {
    public int findSpecialInteger(int[] arr) {
    	
    	int[] a=new int[100005];
    	for(int i=0;i<arr.length;i++) {
    		a[arr[i]]++;
    		if(a[arr[i]]>arr.length/4)
    			return arr[i];
    	}
        return 0;
    }
}
```
