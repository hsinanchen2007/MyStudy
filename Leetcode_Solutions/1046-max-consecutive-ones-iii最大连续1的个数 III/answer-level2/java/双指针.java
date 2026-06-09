执行用时 :4 ms, 在所有 java 提交中击败了98.71%的用户
内存消耗 :40.7 MB, 在所有 java 提交中击败了94.74%的用户
```
class Solution {
    public int longestOnes(int[] A, int K) {
        int[] nums;
        int count, last, i, j, n, k, ones, answer;

        nums = new int[A.length];
        count = 0;
        last = A[0];
        n = 0;
        for(i = 0; i < A.length; i++){
            if(A[i] == last){
                count++;
            }else{
                if(last == 0)
                    nums[n++] = -count;
                else
                    nums[n++] = count;
                count = 1;
                last = A[i];
            }
        }
        if(last == 0)
            nums[n++] = -count;
        else
            nums[n++] = count;
        if(nums[0] < 0)
            i = 1;
        else
            i = 0;
        j = i;
        ones = nums[i];
        k = K;
        answer = 0;
        while(j < n){
            if(j + 2 < n){
                if(k + nums[j+1] >= 0){
                    ones += nums[j+2] - nums[j+1];
                    k += nums[j+1];
                    j += 2;
                }else{
                    answer = Math.max(answer, ones + k);
                    if(K + nums[j+1] < 0){
                        j += 2;
                        i = j;
                        k = K;
                        ones = nums[i];
                    }else{
                        k -= nums[i+1];
                        ones -= nums[i] - nums[i+1];
                        i += 2;
                    }
                }
            }else{
                answer = Math.max(answer, ones + k);
                break;
            }
        }
        return Math.min(answer, A.length);
    }
}
```
