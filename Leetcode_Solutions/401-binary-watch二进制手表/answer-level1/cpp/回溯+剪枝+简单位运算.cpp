```
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        string subre;
        unsigned int mask = 0;
        backtrack(num, 0, result, mask);  
        return result;      
    }
    void backtrack(int num, int idx, vector<string>& result, unsigned int& mask){
        if((mask & 15) > 11 || (mask>>4) > 59) return ;
        if(num == 0)
        {
            string subre = convert(mask);
            result.push_back(subre);
            return ;
        }

        if(idx >=10) return ;

        mask |= (1<<idx);
        backtrack(num-1, idx+1, result, mask);        
        mask &= ~(1<<idx);
        backtrack(num, idx+1, result, mask);        

    }
    string convert(unsigned int mask){
        string re;
        int hour = (mask & 15);
        int mint = (mask >> 4);

        re = to_string(hour)+":";
        if(mint < 10)
        {
            re += "0"+ to_string(mint);
        }
        else
        {
            re += to_string(mint);
        }
        return re;
    }
};
```
