class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        /*
         *1 2 3 ... n
         *n+1 n+2 n+3 ... n+n
         *2n+1...
        */
        int round = 1;//能来回几轮
        //来回完整的round轮，所需糖果数目为 round * (round - 1) / 2*n + round*(n+1)*n/2
        //首先计算round值
        while(true){
            int neededCandies = round * (round - 1) / 2 * num_people * num_people + round * (num_people + 1) * num_people / 2;
            //System.out.println(neededCandies);
            if(neededCandies < candies){
                round++;
            }else{
                break;
            }
        }
        System.out.println(round);
        //对于前round-1轮，每个人已经发了
        //(round-1) * (round - 2) / 2 * num_people + index *  (round - 1);
        //共发了(round-1) * (round - 2) / 2 * num_people* num_people + (round-1) * (num_people + 1) * num_people / 2;
        //还剩candies - 已发的
        int restCandies = candies-(round-1)*(round-2)/2 * num_people * num_people - (round-1) * (num_people + 1) * num_people /2;
        System.out.println(restCandies);
        int[] ans = new int[num_people];
        //分配前round-1轮的糖果
        for(int i = 1; i <= num_people; i++){
            ans[i - 1] = (round-1) * (round - 2) / 2 * num_people + i * (round - 1);
            System.out.print(ans[i - 1]);
        }
        //分配最后一轮的糖果
        for(int i = 1; i <= num_people; i++){
            if((restCandies - (num_people * (round - 1) + i)) < 0){
                ans[i - 1] += restCandies;
                break;
            }else{
                ans[i - 1] += num_people * (round - 1) + i;
                System.out.print(ans[i - 1]);
                restCandies -= num_people * (round - 1) + i;
                System.out.print(restCandies);
            } 
        }
        return ans;
    }
}