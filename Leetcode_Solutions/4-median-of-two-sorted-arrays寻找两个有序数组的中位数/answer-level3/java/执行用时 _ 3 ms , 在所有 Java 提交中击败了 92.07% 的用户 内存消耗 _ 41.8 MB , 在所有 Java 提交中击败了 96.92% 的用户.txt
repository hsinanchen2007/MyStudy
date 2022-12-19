```
class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {

		
		int alen=a.length;
		int blen=b.length;
		int length=a.length+b.length;
		
		boolean isOu=false;
		int mid=0;
		if (length%2==0) {
			isOu=true;
		}
		mid=length/2;
		
		
		int i=0,j=0;
		int last=0,lastPre=0;
		
		while (i+j<=mid) {
			
			lastPre=last;
			if (i>=alen) {
				last=b[j];
				j++;
				continue;
			}
			if (j>=blen) {
				last=a[i];
				i++;
				continue;
			}
			if (a[i]>b[j]) {
				last=b[j];
				j++;
			}else {
				last=a[i];
				i++;
			}
			
		}

		if (isOu) {
			return ((double)lastPre+(double)last)/2;
		}
		return (double) last;
	
    }
}
```
