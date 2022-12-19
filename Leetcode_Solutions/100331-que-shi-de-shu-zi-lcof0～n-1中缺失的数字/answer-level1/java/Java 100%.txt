思路很简单 ，常规的二分查找，因为一直风格都是两端都闭合，所以右边减一，取等号，但要解决一个难点边界越界问题，要打补丁判断一下

public int missingNumber(int[] nums) {
   int l=0,h=nums.length-1;
     while(l<h){
         int m=l+(h-l)/2;
         if(nums[m]>m){h=m;
         System.out.println(h);
         }
         else{ l=m+1;
         System.out.println(l+",l");
         }
     }return nums[l]==l?nums.length:l;
    }