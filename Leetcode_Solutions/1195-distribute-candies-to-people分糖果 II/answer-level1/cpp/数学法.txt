初始化vector 通过数学公式初始前几次完整分配数目
最后分配剩余糖果
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans;
        if(candies==0)return ans;
        int n=(sqrt(1+8*(long)candies)-1)/2;//按规律能分多少人
        int time=n/num_people;//可以完整分几次
        int candies_leave = candies-(1+time*num_people)*time*num_people/2;//剩下的糖
        for(int i=0;i<num_people;i++){
            if(time>0) ans.push_back((i+1)*time+num_people*(time*(time-1)/2));
            else ans.push_back(0);      
        }
        if(candies_leave>0){//有剩余
            for(int i=0;i<num_people;i++){
                if(candies_leave<=(i+1+time*num_people)){
                    ans[i]+=candies_leave;
                    break;
                }else{
                    ans[i]+=(i+1+time*num_people);
                    candies_leave-=(i+1+time*num_people);
                }
            }
        }
        return ans;
    }
};
```
