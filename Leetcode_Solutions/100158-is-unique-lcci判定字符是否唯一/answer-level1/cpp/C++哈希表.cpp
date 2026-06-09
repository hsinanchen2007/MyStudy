```
class Solution {
public:
    bool isUnique(string astr) {
        unordered_map <char,int> hmap;
        for(int i=0;i<astr.length();i++){
            if(hmap.find(astr[i])!=hmap.end()){
                return false;
            }
            hmap.insert(unordered_map<char,int>::value_type(astr[i],i));
        }
        return true;
    }
};
```
