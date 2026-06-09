```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计对应次数的map
        unordered_map<int,int> map;
        //统计对应次数对应的数字
        unordered_map<int,vector<int>> mapfrequent; 
        vector<int> vi;
        int size = nums.size();
        //次数添加数字
        for(int i = 0; i<size;i++){
            map[nums[i]] = map[nums[i]] + 1;
        }
        //次数对应数字添加
        for ( auto it = map.begin(); it != map.end(); ++it ){
            
            if(mapfrequent.find(it->second) == mapfrequent.end()){
                vector<int> v;
                v.push_back(it->first);
                mapfrequent[it->second] = v;
            }else{
                mapfrequent[it->second].push_back(it->first);
            }
        }
        int ks = 0;
        int po = size;
        //找到三个数字
       while(ks<k){
            if(mapfrequent.find(po)== mapfrequent.end()){po--;continue;}
            vector\<int> vv = mapfrequent[po];
            for(int i = 0;i<vv.size();i++){
                if(ks<k){vi.push_back(vv[i]);}
                ks++;    
            }
            po--;
        }
        return vi;    
    }
};
```
