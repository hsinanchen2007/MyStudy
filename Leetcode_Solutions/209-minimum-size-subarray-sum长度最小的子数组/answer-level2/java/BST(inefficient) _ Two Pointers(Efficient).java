```
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int n = nums.length;

        // corner case
        if (n == 0) return 0;

         // ****************************************
         //  BST
         // *********************************
         /**
        int[] prefixSum = new int[n+1];
        for (int i = 0; i < n; i++) {
            if (i == 0) prefixSum[i] = nums[i];
            else prefixSum[i] = prefixSum[i-1] + nums[i];

        }

        TreeSet<Integer> bst = new TreeSet<>((i, j) -> prefixSum[i] - prefixSum[j]);
      
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (prefixSum[i] >= s) {
                   
                    res = 1;
                }
                bst.add(i);
            } else {
                if (prefixSum[i] >= s) {
                    if (i + 1 < res ){
                        res = i+1;
                    }

                    prefixSum[n] = prefixSum[i] - s;
                    
                    Integer prev = bst.floor(n);
                    if (prev != null) {
                            if (i - prev < res) {
                                res = i- prev;
                            } 
                    }
                    
                }
                bst.add(i);
            }
        }

        return res == Integer.MAX_VALUE ? 0 : res;
 **/
        //***************************************************
        // 2 pointers
        //  执行用时 :2 ms, 在所有 java 提交中击败了92.40% 的用户
        //  内存消耗 :37.4 MB, 在所有 java 提交中击败了95.08%的用户
        // *****************************************************
        int left = 0;
        int sum = 0;
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            while (sum >=  s) {
                res = Math.min(res , i - left + 1);
                sum -= nums[left++];
            }
        }

        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
```
