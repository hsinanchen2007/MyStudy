用队列存滑动窗口的值，但是每次滑动的时候做两个判断，判断左边划过的值是否是最大值，如果不是，那么只要比较最大值和新进入的数谁比较大，就可以得出当前滑动窗口的最大值了，可以不用遍历。如果左边划过的值是最大值，那么就要重新找队列中的最大值，这时候需要遍历队列。因为左边划过的值是最大值的可能性只有1/k，因此判断了左边划过的值是否最大值再决定是否遍历，而不是直接遍历队列找最大值，会大大缩短代码的执行时间。
记得要先判断特殊情况哦~
```
public int[] maxSlidingWindow(int[] nums, int k) {
        int n,index=0;
        n=nums.length+1-k;
        int[] re=new int[n];
        Queue<Integer> req=new LinkedList<Integer>();
        int max=Integer.MIN_VALUE;
        if(nums==null || nums.length==0) {
        	return new int[0];
        }
        if(k==1) {
        	return nums;
        }
        for(int j=0;j<k;j++) {
    		req.offer(nums[j]);
    		if(nums[j]>max) {
    			max=nums[j];
    		}
    	}
        re[index]=max;
        index+=1;
        for(int i=0;i<nums.length-k;i++) {
        	int flag=req.peek();
        	int f=i+k;
        	req.poll();
        	if(flag<max) {
        		if(nums[f]>max) {
        			max=nums[f];
        		}
        		re[index]=max;
    			index+=1;
    			req.offer(nums[f]);
        	}else {
    			req.offer(nums[f]);
    			max=Integer.MIN_VALUE;
        		for(int q:req) {
        			if(q>max) {
        				max=q;
        			}
        		}
        		re[index]=max;
    			index+=1;
        	}
        }
        return re;
    }
```
