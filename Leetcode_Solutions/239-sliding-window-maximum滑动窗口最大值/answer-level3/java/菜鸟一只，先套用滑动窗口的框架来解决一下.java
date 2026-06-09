    
    class Solution {
        public int[] maxSlidingWindow(int[] nums, int k) {
            List<Integer> list = new ArrayList<>();
            int left = 0, right = 0;
            TreeMap<Integer,Integer> tm = new TreeMap<>(new Comparator<Integer>() {

                @Override
                public int compare(Integer o1, Integer o2) {
                    return o2 - o1;    //这个是逆序
                }
                
            });
            while(right < nums.length) {
                tm.put(nums[right], tm.getOrDefault(nums[right], 0) + 1);
                while(right - left + 1 == k) {
                    int temp = nums[left++];
                    list.add(tm.firstKey());
                    tm.put(temp, tm.get(temp) - 1);
                    if(tm.get(temp) == 0) {
                        tm.remove(temp);
                    }
                }
                right++;
            }
            int[] res = new int[list.size()];
            for(int i = 0;i < res.length;i++) {
                res[i] = list.get(i);
            }
            return res;
        }
    }