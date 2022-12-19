写的可能比较差，但是是自己基于三个数之和（第15题写的）首先是对数组进行排序，引入双指针，但在java中没有指针这么一说，可以理解成双下标箭头吧。主题思想是：依次比较，当遇到大于目标值的值的时候，首先是设置一个标志位，属于第一次赋值，以后每次若大于目标值，就把这个值与上一次赋的值进行比较，比他小就保存下来，同理当遇到小于目标值的时候也一样，只不过以后每次若大于上一次赋值的就保存下来，最后再进行最后一次保存的大值与小值与目标值的差距比较即可。个人感觉的总体的时间复杂度为O（n2）
        Arrays.sort(nums);
        int length = nums.length;
        int smallNumber = 0,bigNumber=0;
        boolean small=false;
        boolean big = false;
        if(nums==null ||nums.length<3){
        	throw new IllegalArgumentException("数组有问题");
        }else if(nums[0]+nums[1]+nums[2]>= target){//最小三个数之和大于target
    		return nums[0]+nums[1]+nums[2];
    	}else if(nums[length-1]+nums[length-2]+nums[length-3]<= target){//最大的三个数之和小于target
    		return nums[length-1]+nums[length-2]+nums[length-3];
    	}
        for(int i=0;i<length;i++){
        	int left =i+1;
        	int right = length-1;
        	while(left < right){
        		int sum = nums[i]+nums[left]+nums[right];
        		if(sum < target){
        			if(small==false){
        				smallNumber = sum;
        				small = true;
        			}
        			if(sum >= smallNumber) smallNumber = sum;
        			left++;	
        		}else if(sum == target){
        			return sum;
        		}else if(sum > target){
        			if(big == false){
        				bigNumber = sum;
        				big = true;
        			}
        			if(sum <= bigNumber) bigNumber = sum;
        			right--;
        		}
        	}
        }
		if((target-smallNumber) > (bigNumber-target)){
			return bigNumber;
		}else{
			return smallNumber;
		}
