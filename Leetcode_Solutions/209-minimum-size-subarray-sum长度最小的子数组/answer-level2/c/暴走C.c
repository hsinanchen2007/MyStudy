    int minSubArrayLen(int s, int* nums, int numsSize){
            int start = 0;			//记录当前子数组的头部
            int end = 0;			//记录当前子数组的尾部
            int sum = 0;			//当前记录的连续子数组的长度
            int min = 0;			//最小的长度
            int flag = 0;
            
            for(int i = 0; i < numsSize; i++) { 
                //不管三七二十一我先加上
                end = i;
                sum+=nums[i];
                
                //如果加入后和大于等于s，就判断当前子数组的长度与min的大小，若小于min则更新min
                //然后将sum回退到小于s的状态，直到和小于等于s
                while(sum >= s && start <= end) {
                    if(flag == 0) {
                        min = end-start+1;
                        flag = 1;
                    }else {
                        if((end-start+1) < min) {
                            min = end-start+1;
                        }
                    }
                    sum-=nums[start++];
                }
            }
            return min;
    }