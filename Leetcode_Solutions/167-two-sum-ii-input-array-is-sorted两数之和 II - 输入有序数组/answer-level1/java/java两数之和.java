解法：设置左指针(left)与右指针(right)，如果numbers[left]+numbers[right]>target;那么右指针像左移动，反之小于左指针向右移动，```
代码块
int [] index = new int[2];
        int left = 0;
        int right = numbers.length-1;
        while(left<right){
        	int sum = numbers[left]+numbers[right];
        	if(sum==target){
        		index[0]=left+1;
        		index[1]=right+1;
        		return index;
        	}else if(sum>target){
        		right--;
        	}else if(sum<target){
        		left++;
        	}
        }
        return index;
