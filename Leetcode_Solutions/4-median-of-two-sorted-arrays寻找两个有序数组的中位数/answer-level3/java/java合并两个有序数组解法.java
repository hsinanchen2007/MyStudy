class Solution {
    public double findMedianSortedArrays(int[] array1, int[] array2) {
        double result=0;
		int l1=0,l2=0,l3=0;
        int lengths=array1.length+array2.length;
		int[] array3=new int[lengths];
		while(l1<array1.length&&l2<array2.length) {
			if(array1[l1]<array2[l2]) {
				array3[l3++]=array1[l1++];
			}else {
				array3[l3++]=array2[l2++];
			}
		}
		while(l1<array1.length) {
			array3[l3++]=array1[l1++];
		}
		while(l2<array2.length) {
			array3[l3++]=array2[l2++];
		}
		//得到最终合并有序数组
		int mid=(array3.length)%2;
		if(mid==0) {
			int index=(array3.length)/2;
			double value=array3[index-1]+array3[index];
			double b2=2.00;
			result=value/b2;
		}else {
			int index=(array3.length)/2;
			result=array3[index];
		}
		return result;
    }
}