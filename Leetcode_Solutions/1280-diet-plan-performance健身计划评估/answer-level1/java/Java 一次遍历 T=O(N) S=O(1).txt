```
class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int n = calories.length;
        
        int res = 0;
        int T = 0;
        int left = 0;
        
        for(int right =0; right < n; right++){
            T += calories[right];
            if(right - left + 1 == k){
                if(T < lower) res--;
                else if(T > upper) res++;
                T -= calories[left++];
            }
        }
        return res;
    }
}
```
