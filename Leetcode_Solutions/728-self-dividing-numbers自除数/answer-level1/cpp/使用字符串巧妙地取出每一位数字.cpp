
```
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int item=left; item<=right; item++){
            string str = to_string(item);
            bool flag = true; 
            int tmpNum = item;
            for(auto ch : str){  
                int item = ch - '0';
                if(item == 0 || tmpNum % item !=0) {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                result.push_back(item);
        }
        return result;
    }
};
```
