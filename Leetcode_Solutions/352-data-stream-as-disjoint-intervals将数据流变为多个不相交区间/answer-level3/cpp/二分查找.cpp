```
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val){
        auto it1 = fore.upper_bound(val);
        if(it1 == fore.begin()){
            fore[val] = val;
        }else if(it1 == fore.end()){
            if(fore.size() == 0){
               fore[val] = val; 
            }else{
               auto it2 = it1;
                it1--;
                if(it1->second  == val - 1){
                    int l = it1->first;
                    int r = val;
                    fore.erase(l);
                    fore[l] = r;
                }else if(it1->second < val - 1){
                    fore[val] = val;
                }
            }
        }else{
            auto it2 = it1;
            it1--;
            if(val != it2->first-1 && val != it1->second + 1){
                fore[val] = val;
            }else if(it2->first == val+1 && it1->second == val-1){
                int l = it1->first;
                int r = it2->second;
                fore.erase(it1->first);
                fore.erase(it2->first);
                fore[l] = r;
            }else if(it2->first == val+1){
                int l = val;
                int r = it2->second;
                fore.erase(it2->first);
                fore[l] = r;
            }else if(it1->second == val-1){
                int l = it1->first;
                int r = val;
                fore.erase(it1->first);
                fore[l] = r;
            } 
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        vector<int> seg(2,0);
        
        for(auto f : fore){
            seg[0] = f.first;
            seg[1] = f.second;
            res.push_back(seg);
        }
        
        return res;
    }
private:
    map<int,int> fore;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
```