比较直观的方法就是借助于hash map
```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //edge case
        if(time.size() <= 1) return 0;

        int res = 0;
        unordered_map<int, int> record;
        for(auto& t:time) t = t % 60;
        for(auto t:time){
            int residue = (60 - t) % 60;
            if(record.find(residue) != record.end()){
                res += record[residue];
            }
            record[t] += 1;
        }
        return res;
    }
};
```
