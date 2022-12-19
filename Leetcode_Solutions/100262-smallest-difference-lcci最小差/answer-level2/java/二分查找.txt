大致思路，根据二分查找 找到a中一个数 对应b中的最小绝对差，每次查找的复杂度是log n
排序的复杂度是nlogn，总复杂度 nlogn
![捕获.PNG](https://pic.leetcode-cn.com/edf1d20ea10173ed7701d2b2e1e7048e719ad7277c2adc2ceaeb07f7a1f635da-%E6%8D%95%E8%8E%B7.PNG)


```
 public int smallestDifference(int[] a, int[] b) {
           Arrays.sort(b);
           int res=Integer.MAX_VALUE;
           for (int num:a) {
			res=Math.min(res, erfen(b, num));
		}
           return res;
	    }
	 public int erfen(int[] b,int target) {
		 Arrays.sort(b);
		 int left=0;int right=b.length-1;
		 if(target<b[left]) {return Math.abs(b[left]-target)>=0?Math.abs(b[left]-target):Integer.MAX_VALUE;}
		 if(target>b[right]) {return Math.abs(target-b[right])>=0?Math.abs(target-b[right]):Integer.MAX_VALUE;}
		 while(left<right-1) {
			 int mid=(left+right)>>1;
		     if(target>b[mid]) {left=mid;}
		     else if(target==b[mid]) {return 0;}
		     else {right=mid;}
		 }
		 return Math.min(Math.abs(target-b[left]), Math.abs(target-b[right]));
		 
	 }
```
看见测试的MAX和MIN就想吐
