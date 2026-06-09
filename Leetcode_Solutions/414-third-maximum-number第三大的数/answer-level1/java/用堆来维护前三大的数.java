    
    class Solution {
        // 用堆来维护前三大的数
        public int thirdMax(int[] nums) {
            PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
            for(int i = 0;i < nums.length;i++) {
                if(!queue.contains(nums[i])) {
                    if(queue.size() == 3) {
                        if(queue.peek() < nums[i]) {      // 剔除小的数
                            queue.poll();
                        }else {
                            continue;
                        }
                    }
                    queue.add(nums[i]);
                }
            }
            if(queue.size() == 2) {
                queue.poll();
                return queue.peek();
            }
            return queue.peek();
        }
    }