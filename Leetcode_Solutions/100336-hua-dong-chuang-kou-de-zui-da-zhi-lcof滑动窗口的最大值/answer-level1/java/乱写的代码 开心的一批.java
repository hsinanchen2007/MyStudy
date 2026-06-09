```
    class Solution {

        public int[] maxSlidingWindow(int[] nums, int k) {

            int i = 0, j = k - 1;
            
           if(k == 0) return new int[0]; //因为忘记处理空数组错的地方, 粗心~

            int[] res = new int[nums.length - k + 1];
            
            for(; j < nums.length; ){

                res[i] = maxNum(nums, i++, j++); 

            }
            return res;
        }

// 求最值的方法, 我当时到底在想什么..
        public int maxNum(int[] nums, int f, int t){

            while(f < t){
                if(nums[f] > nums[t])
                    t--;
                else
                    f++;
            }
            return nums[f];
        }

    }
```
