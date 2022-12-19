分治法思想就是将问题分解成更小的问题，经过层层递归，最后进行整合

每层递归将数组均匀分成两半，三种情况：

   **1.最大子序和在左边**
   **2.最大子序和在右边**
   **3.最大子序和横跨左右**     
  
Divide：取当前数组的中间位mid将数组分成左右两半
Conquer：递归求解左右两半的最大子序和，当子问题size为 1 时，直接返回
Combine：合并左右两边以及中间的解，向上返回


    class Solution {
        public int maxSubArray(int[] nums) {
            //分治法
            //每层递归将数组均匀分成两半，三种情况：
            //1.最大子序和在左边
            //2.最大子序和在右边
            //3.最大子序和横跨左右       
            return maxSubArray1(nums, 0, nums.length - 1);    
        }
        
        public int maxSubArray1(int[] nums, int l, int r){
            //分解到只有一个数时，返回该值
            if(l == r)
                return nums[l];
            
            int mid = (l + r) / 2;
            //递归求左右最大子序和
            int resL = maxSubArray1(nums, l, mid);
            int resR = maxSubArray1(nums, mid + 1, r);
            
            /*
            从mid向两边求最大子序和maxSumL,maxSumR，第三种情况最大子序和是maxSumL + maxSumR
            */
            int maxSumL = nums[mid]; int maxSumR = nums[mid + 1];
            int sumL = 0; int sumR = 0;
            //计算mid左边的最大子序和
            for(int i = mid; i >= l; i--){
                sumL += nums[i];
                if(sumL > maxSumL)
                    maxSumL = sumL;
            }
            
            //计算mid右边的最大子序和
            for(int j = mid + 1; j <= r; j++){
                sumR += nums[j];
                if(sumR > maxSumR)
                    maxSumR = sumR;
            }
            
            int resM = maxSumL + maxSumR;
            //返回resL, resM, resR三者最大值
            return Math.max(resM, (resL > resR ? resL : resR));  
        }
        
    }