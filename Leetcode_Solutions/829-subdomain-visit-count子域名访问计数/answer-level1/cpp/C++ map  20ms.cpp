### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        for(int i = 0; i < cpdomains.size(); i++){
            int times = 0;
            int j = 0;
            for(j = 0; j < cpdomains[i].length(); j++){
                if(isdigit(cpdomains[i][j])){
                    times = times*10 + cpdomains[i][j] - '0';
                }
                else{
                    break;
                }
            }
            string address = "";
            for(int k = cpdomains[i].length()- 1; k >= j; k--){
                if(cpdomains[i][k] == '.'){
                    count[address] += times;
                    address = '.' + address;
                }
                else if(isalpha(cpdomains[i][k])){
                    address = cpdomains[i][k] + address;
                }
            }
            count[address] += times;
        }
        vector<string> res;
        for(auto i = count.begin(); i != count.end(); i++){
            string cur = "";
            cur = to_string(i -> second) + " " + i -> first;
            res.push_back(cur);
        }
        return res;
    }
};
```