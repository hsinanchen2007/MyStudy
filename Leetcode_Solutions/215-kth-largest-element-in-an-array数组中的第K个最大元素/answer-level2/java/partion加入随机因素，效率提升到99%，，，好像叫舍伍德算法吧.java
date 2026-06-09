    
    class Solution {
        public int findKthLargest(int[] nums, int k) {
            int len = nums.length;
            int left = 0, right = len - 1;
            int res = 0;
            while(true) {
                int start = left;
                int end = right;
                int r = new Random().nextInt(end - start + 1) + start;   // 加入随机因素
                swap(nums, right, r);
                int flag = nums[right];
                while(left < right) {     // left和right相遇后退出
                    while(nums[left] < flag && left < right) {left++;}
                    while(nums[right] >= flag && right > left) {right--;}
                    if(left < right) {
                        swap(nums, left, right);
                    }
                }
                swap(nums, left, end);
                if(len - left == k) {
                    res = nums[left];
                    break;
                }else if(len - left > k) {
                    left = left + 1;
                    right = end;
                }else {
                    right = left - 1;
                    left = start;
                }
            }
            return res;
        }

        public void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }