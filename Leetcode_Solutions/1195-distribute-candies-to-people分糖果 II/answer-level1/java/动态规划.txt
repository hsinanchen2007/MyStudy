`class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int i = 0;
        int temp =1;
        while(candies>0){
           if(candies > temp){
               ans[i] += temp;
               candies = candies-temp;
               temp =temp+1;
           }else{
               ans[i] += candies;
               candies = 0;
           }
           i = (i+1)%num_people;
        }
        return ans;

    }
}`