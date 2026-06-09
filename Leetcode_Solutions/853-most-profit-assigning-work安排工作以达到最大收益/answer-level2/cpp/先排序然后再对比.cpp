```

#include <map>
#include <iostream>
#include <algorithm>
class Solution {
public:

//并不是难度最高的工作利润最高；难度也不是有序的；工人的能力也不是有序的；
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> difficulty_pro {};//创建带有值对的数组 ；
        for(int h=0;h<difficulty.size();h++){
            difficulty_pro.push_back({difficulty[h],profit[h]});
        }
        sort(difficulty_pro.begin(),difficulty_pro.end());
        int d_p=0;
        int sum =0;
        sort(worker.begin(),worker.end());
        
       
        
        int worker_lever=0;
        int max_p=0 ;
        for(int i =0 ;i< worker.size();i++){
            
            //cout <<"i: "<<i<<'\n';
            
            for(int j=worker_lever;j< difficulty.size();j++){
                //cout <<"j: "<<j<<'\n';
                if( worker[i] >= difficulty_pro[j].first){
                    
                    max_p = max_p>=difficulty_pro[j].second?max_p:difficulty_pro[j].second;
                    //cout <<"max_p: "<<max_p<<'\n';
                    worker_lever = j;
                    //cout <<"worker_lever: "<<worker_lever<<'\n';
                    

                }
                else{
                    break;
                }                
            }
        sum  += max_p;
        //cout <<"sum: "<<sum<<'\n';
        }
        return sum;
    }
};
```





![image.png](https://pic.leetcode-cn.com/eb9dc19c4e51b1c5aba1ce1e57174641551c2d9bd768ab4680832af81c0be8f6-image.png)
```

