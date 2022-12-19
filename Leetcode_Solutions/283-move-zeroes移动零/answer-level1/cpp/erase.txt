方法一
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeronums=0;
        for(vector<int>::iterator it=nums.begin();it!=nums.end();){
            if(*it==0){
                it=nums.erase(it);
                zeronums++;
            }
            else it++;
        }
        while(zeronums>0){
            nums.emplace_back(0);
            zeronums--;
        }
    }
};
```
