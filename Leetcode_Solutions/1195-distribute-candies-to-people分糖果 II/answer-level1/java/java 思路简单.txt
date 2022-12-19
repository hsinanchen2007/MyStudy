思路：一个数组存储每个小孩得到的糖数，下次分糖的时候所拥有的糖=当前拥有的糖加上这次分得的糖。
每次给小孩的糖数取决于，糖数是否足够按照规则区分，不够的话，剩多少糖就给小孩多少糖。



```
public int[] distributeCandies(int candies, int num_people) {
        //存储糖
        int[] dp = new int[num_people];
        Arrays.fill(dp,0);
        //当前已分糖
        int current_candies =0;
        int i=0;
        while(current_candies<candies){
          
            if((current_candies+i+1)<=candies){
                dp[i%num_people]=dp[i%num_people]+ i+1;
                i=i+1;
            }
            else{
                dp[i%num_people]=dp[i%num_people]+ candies-current_candies;
                return dp;
            }
            
            current_candies = current_candies +i;
           

        }
        return dp;

    }

```


    