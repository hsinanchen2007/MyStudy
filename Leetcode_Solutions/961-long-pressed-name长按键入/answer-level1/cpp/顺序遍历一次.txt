```
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int first=0,second=0;
        while(first<name.size()){
            int num_first=0,num_second=0;
            if(name[first]!=typed[second]){
                return false;
            }
            while(first+num_first<name.size()&&name[first+num_first]==name[first]){
                ++num_first;
            }
            while(second+num_second<typed.size()&&typed[second+num_second]==typed[second]){
                ++num_second;
            }
            if(num_first>num_second){
                return false;
            }
            first+=num_first;
            second+=num_second;
        }
        return second==typed.size();
    }
};
```
