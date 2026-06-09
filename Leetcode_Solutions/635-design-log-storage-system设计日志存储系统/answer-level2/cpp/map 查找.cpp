1. 写的有点复杂；
2. 主要找到结束时间和开始时间；

```
class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        logs[timestamp].push_back(id);
    }
    
    static int myStoi(const string & str){
        int res = 0;
        
        for(int i = 0;i < str.size(); ++i){
            res = res*10 + str[i] - '0';
        }
        
        return res;
    }
    
    static vector<int> tsToInt(string timestamp){
        vector<int> ans(6,0);
        
        /*year*/
        ans[0] = myStoi(timestamp.substr(0,4));
        /*month*/
        ans[1] = myStoi(timestamp.substr(5,2));
        /*day*/
        ans[2] = myStoi(timestamp.substr(8,2));
        /*hour*/
        ans[3] = myStoi(timestamp.substr(11,2));
        /*minute*/
        ans[4] = myStoi(timestamp.substr(14,2));
        /*second*/
        ans[5] = myStoi(timestamp.substr(17,2));
        
        return ans;
    }
    
    static string intToTs(vector<int> & arr){
        string ans;
        
        /*year*/
        ans += to_string(arr[0]) + ":";
        /*month*/
        ans += (arr[1] > 9 ? "":"0") + to_string(arr[1]) + ":";
        /*day*/
        ans += (arr[2] > 9 ? "":"0") + to_string(arr[2]) + ":";
        /*hour*/
        ans += (arr[3] > 9 ? "":"0") + to_string(arr[3]) + ":";
        /*minue*/
        ans += (arr[4] > 9 ? "":"0") + to_string(arr[4]) + ":";
        /*Second*/
        ans += (arr[5] > 9 ? "":"0") + to_string(arr[5]);
        
        return ans;
    }
    
    static bool isLeapYear(int year){
        if(year%4 == 0 && year%100 != 0){
            return true;
        }else if(year%100 == 0 && year%400 == 0){
            return true;
        }else{
            return false;
        }
    }
    
    static int monthOfDay(int year,int month){
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear(year)&&month == 2){
            return 29;
        }else{
            return days[month-1];
        }
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> start = tsToInt(s);
        vector<int> end = tsToInt(e);
        vector<int> res;
        
        if(gra == "Year"){
            /*start*/
            start[1] = 0;
            start[2] = 0;
            start[3] = 0;
            start[4] = 0;
            start[5] = 0;
            /*end*/
            end[1] = 12;
            end[2] = 31;
            end[3] = 23;
            end[4] = 59;
            end[5] = 59;
        }else if(gra == "Month"){
            /*start*/
            start[2] = 0;
            start[3] = 0;
            start[4] = 0;
            start[5] = 0;
            /*end*/
            end[2] = 30;
            end[3] = 23;
            end[4] = 59;
            end[5] = 59;
        }else if(gra == "Day"){
            /*start*/
            start[3] = 0;
            start[4] = 0;
            start[5] = 0;
            /*end*/
            end[3] = 23;
            end[4] = 59;
            end[5] = 59;
        }else if(gra == "Hour"){
            /*start*/
            start[4] = 0;
            start[5] = 0;
            /*end*/
            end[4] = 59;
            end[5] = 59;
        }else if(gra == "Minute"){
            /*start*/
            start[5] = 0;
            /*end*/
            end[5] = 59;
        }
        
        auto it1 = logs.lower_bound(intToTs(start));
        auto it2 = logs.upper_bound(intToTs(end));
        for(auto it = it1; it != it2; ++it){
            for(int i = 0;i < it->second.size(); ++i){
                res.push_back(it->second[i]);
            }
        }
        
        return res;
    }
private:
    map<string,vector<int>> logs;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
```