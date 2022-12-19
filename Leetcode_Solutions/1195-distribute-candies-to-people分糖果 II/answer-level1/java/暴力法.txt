```
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int len = num_people;
        int[] ans = new int [len];
        int give = 1;
        while(candies>0 && len>0){
            for(int i=0;i<len;i++){
                if(candies > give){
                    ans[i] = ans[i] + give;
                    candies = candies - give;
                    give++;
                }else{
                    ans[i] = ans[i] + candies;
                    return ans;
                }

            }
        }
        return ans;
    }
}
```
