```
class Solution {
public:
    struct info{
        int m_freq = 0;
        int m_left_pos = 0;
        int m_right_pos = 0;

       
    };
    int findShortestSubArray(vector<int>& nums) {
        
        //key ->nums[i]
        //value -> <频度，第一次出现坐标,最后一次出现坐标>
        map<int,info> nums_map;

        for(int i=0;i<nums.size();i++){
            if(nums_map.find(nums[i]) != nums_map.end()){
                nums_map[nums[i]].m_freq += 1 ;
                nums_map[nums[i]].m_right_pos = i;
            }else{
                nums_map[nums[i]] = {1,i,i};
            }
        }

        //nums[i],freq,degree
        vector<tuple<int,int,int>> nums_vec;
        for(auto& num:nums_map){
            int freq = num.second.m_freq;
            int degree = num.second.m_right_pos - num.second.m_left_pos + 1;
            nums_vec.emplace_back(make_tuple(num.first,freq,degree));
           //cout<<num.first<<" "<<num.second.m_right_pos<<" "<<num.second.m_left_pos<<endl;
        }

        //按频度排序,频度相同按度
        auto min_iter = min_element(nums_vec.begin(),nums_vec.end(),
            [](auto& tuple1,auto& tuple2){
                int t1_f,t1_d;
                int t2_f,t2_d;
                tie(std::ignore,t1_f,t1_d) = tuple1;
                tie(std::ignore,t2_f,t2_d) = tuple2;
                if(t1_f != t2_f){
                    return t1_f > t2_f;
                }else{
                    return t1_d < t2_d;
                }
            });
    
        return get<2>(*min_iter);



    }
};
```
