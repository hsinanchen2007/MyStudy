    
    class Solution {
        public int lengthOfLIS(int[] nums) {
            TreeSet<Integer> ts = new TreeSet<>();
            for(int i = 0;i < nums.length;i++) {
                Integer c = ts.ceiling(nums[i]);
                if(c != null) {
                    ts.remove(c);
                }
                ts.add(nums[i]);
            }
            return ts.size();
        }
    }