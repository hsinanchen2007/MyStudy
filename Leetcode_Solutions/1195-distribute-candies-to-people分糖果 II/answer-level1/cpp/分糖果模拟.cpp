很简单的模拟就行了
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int curnum = 1;
        while(candies > 0){
            for(int i=0;i<num_people;i++){
                if(candies < curnum){
                    ans[i] += candies;
                    candies = 0;
                    break;
                }
                ans[i] += curnum;
                candies -= curnum;
                curnum++;
            }
        }
        return ans;
    }
};
```
