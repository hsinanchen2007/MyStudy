public int[] intersect(int[] nums1, int[] nums2) {
	        int[]nums=new int[Math.min(nums1.length, nums2.length)];
	        int[]mask1=new int[nums1.length];
	        int[]mask2=new int[nums2.length];
	        for(int i=0;i<nums1.length;i++) {
	        	mask1[i]=0;
	        }
	        for(int i=0;i<nums2.length;i++) {
	        	mask2[i]=0;
	        }
	        int t=0;
	        for(int i=0;i<nums1.length;i++) {
	        	for(int j=0;j<nums2.length;j++) {
	        		if(nums1[i]==nums2[j]) {
	        			if(mask2[j]!=1&&mask1[i]!=1) {
	        			nums[t]=nums1[i];
	        			t++;
	        			mask1[i]=1;
	        			mask2[j]=1;
	        			}
	        		}
	        	}
	        }
	        int[]finalnums=new int[t];
	        for(int i=0;i<t;i++) {
	        	finalnums[i]=nums[i];
	        }
	        return finalnums;
	}