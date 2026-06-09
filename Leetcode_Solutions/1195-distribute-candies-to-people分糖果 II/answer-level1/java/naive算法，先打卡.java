    
    class Solution {
        public int[] distributeCandies(int candies, int num_people) {
            int[] res = new int[num_people];
            int cur = 1;
            int i = 0;
            while(cur <= candies) {
                res[i] += cur;
                candies -= cur;
                cur++;
                i = (i + 1) % num_people;
            }
            res[i] += candies;
            return res;
        }
    }