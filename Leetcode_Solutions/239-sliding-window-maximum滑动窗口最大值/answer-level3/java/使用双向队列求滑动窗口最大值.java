```
    public int[] maxSlidingWindow(int[] nums, int k) {
        //进行判空        
        if (nums.length == 0 || k == 0){
            return new int[0];
        }
        //存储窗口内的下标        
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        //保存最后的结果        
        int res[] = new int[nums.length-k+1];
        for (int i=0;i<nums.length;i++){
            //如果队列长度等于k之后，这时往后移则超过，所以要先进行队首移除操作            
            if (i>=k && deque.getFirst()<=i-k){
                deque.removeFirst();
            }
            //如果队列左侧的数据比新来的元素小则不停的出队
            while (deque.size()>0 && nums[deque.getLast()]<=nums[i]){
                deque.removeLast();
            }
            //将新的下标入队            
            deque.add(i);
            if (i>=k-1){
                res[i+1-k]=nums[deque.getFirst()];
            }
        }
        return res;
    }
```
