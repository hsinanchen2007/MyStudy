```
class Solution {
public:
    bool isRight( vector<int>& a, vector<int>& b){
        for( int i = 0; i < b.size(); i++)
            if( a[i] < b[i])
                return false;
        return true;
    }
    
    void update( int& res_size, int& begin, int left, int right){
        if( res_size > right - left + 1)
            res_size = right - left + 1, begin = left;
    }
    
    string minWindow(string s, string t) {
        vector<int> record_now(128,0), record_target(128,0);
        //将 t 中的所有字符备份到 record_target 中
        for( auto it:t)
            record_target[it]++;
        
        int res_size = INT_MAX, begin = 0;
        //首先到达第一个边界
        int right = 0;
        for( ; right < s.size(); right++){
            record_now[ s[right]]++;
            if( isRight( record_now, record_target)){
                update( res_size, begin, 0, right);
                break;
            }
        }
        
        for( int left = 0; left < right && right < s.size();){
            record_now[ s[left]]--, left++;

            if( isRight( record_now, record_target))
                update( res_size, begin, left, right);
            else
                for( right++; right < s.size(); right++){
                    record_now[ s[right]]++;
                    if( isRight( record_now, record_target)){
                        update( res_size, begin, left, right);
                        break;
                    } 
                }
        }
        
        if( res_size == INT_MAX)    //此时没有匹配的子串
            return "";
        
        return s.substr( begin, res_size);
    }
};
```