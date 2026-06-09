1.计算N次小孩都能拿满糖果以及剩余的糖果p
2.每个小孩的糖果=N次拿满+剩余的糖果能拿到的最大糖果

```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people,0);
        int count = 0;
        int p = candies;
        while(candies>0)
        {
            int left = count*num_people+1,right=(count+1)*num_people;
            candies -= (left+right)*num_people/2;
            if(candies>0) count++;
        }
        p -= (1+count*num_people)*count*num_people/2;
      
        for(int i = 0;i<num_people;i++)
        {
            ans[i] = (i+1+(count-1)*num_people+1+i)*count/2;
            if(p>count*num_people+1+i) 
            {
                ans[i]+=1+count*num_people+i;
                p-=1+count*num_people+i;
            }
            else{
                ans[i]+=p;
                p=0;
            }
        }
        return ans;
    }
};
```


