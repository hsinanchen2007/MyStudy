class Solution {
    public int trap(int[] height) {
      int max=0,sum=0;  //最大值和雨水总数
	  int l=0,r=0;  //左边和右边
   
      for(int j = 0; j<height.length;j++) {
		
	  if(j<=0) {
		  max= height[j];                     //获取数组的最大数
	  }
	  else {
		if(max<=height[j]) {
			max=height[j];
		}  
	  }
	  // System.out.print(height[j]+" ");
	   
	  }

	   //System.out.print("\n");

     for(int q1=0;q1<max;q1++) {            //第一层遍历 ：从底层开始，以一层为单位的形式算出雨水
		 
		 
		 for(int q2=0;q2<height.length;q2++) {    //第二层遍历：查出一层中每列的数
		   if(q2!=0&&q2!=height.length-1) {
			 if((height[q2]-q1)==0) {
				 for(int u = q2-1; u>=0 ; u--) {
					 if(height[u]-q1>0) {
						 l=1;
						 break;
					 }else {
						 l=0;
					 }
				 }
				 for(int f=q2+1;f<height.length;f++) {
					 if(height[f]-q1>0) {
						 r=1;
						 break;
					 }
					 else {
						 r=0;
					 }
				 }
				 if(l==1&&r==1) {
					// System.out.println("第"+(q1+1)+"层"+"中第"+(q2+1)+"列有雨水");
					 ++sum;
					 ++height[q2];
				 }

			 }
		 }
		   
		   
		 }
	 }
     return sum;
    }
}