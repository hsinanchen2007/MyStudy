```java
class Solution {
    public int numTeams(int[] rating) {
        if(rating == null || rating.length <= 2){
            return 0;
        }
        int n = rating.length;

        int[] dpLeftMin = new int[n];
        int[] dpLeftMax = new int[n];

        int[] dpRightMax = new int[n];
        int[] dpRightMin = new int[n];
        
        for(int i=1;i<n-1;i++){
            for(int j=i-1;j>=0;j--) {
                if (rating[j] < rating[i]) {
                    dpLeftMin[i] ++;
                }
                if(rating[j] > rating[i]){
                    dpLeftMax[i] ++;
                }
            }

            for(int j=i+1;j<n;j++) {
                if (rating[i] > rating[j]) {
                    dpRightMin[i] ++;
                }
                if(rating[i] < rating[j]){
                    dpRightMax[i] ++;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<n-1;i++){
            ans += dpLeftMax[i] * dpRightMin[i];
            ans += dpLeftMin[i] * dpRightMax[i];
        }
        return ans;
    }
}
```