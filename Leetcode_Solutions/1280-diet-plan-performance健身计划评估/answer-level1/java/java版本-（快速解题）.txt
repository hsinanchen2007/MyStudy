![2.jpg](https://pic.leetcode-cn.com/b6982dcbabc2062bdda2eccb2a4aa7cf4ae4d87d2426234efe1af327d24fb6fa-2.jpg)


思路：利用滑动窗口思想，这个题目解释不行，实际上相当于每隔K个位置（1~k,2~k+1,...依次类推），加起来的值判断是否是大于upper，或者小于lowers什么的。算法主要优化就是加过的值不要再重复加了，每次减去最开始的起点位置的值，加上最新位置的值。

 
```
 public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
		  int sum  = 0;
		  int count =0;
		  int res =0;
		  int cnt =0;
		 for(int i =0;i<calories.length;i++) {
			 count++;
			if(count==k) {
				sum+=calories[i];
				if(sum>upper) {res++;}
				else if(sum<lower) {res--;}
				else {}
				count -=1;
				sum-=calories[cnt++];
				
			}
			else {
				sum +=calories[i];
			}
			 
		 }
		 
		 
		 return res;
	        
	    }
```

