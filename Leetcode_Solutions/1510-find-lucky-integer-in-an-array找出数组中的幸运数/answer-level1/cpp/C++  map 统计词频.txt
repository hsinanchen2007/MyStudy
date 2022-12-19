```
class Solution {
public:
    int findLucky(vector<int>& arr) {
        if(arr.empty())  return -1;
        map<int, int> nums;
        for(auto &i : arr){
            ++nums[i];
        }
        auto it = nums.cbegin();
        int result = 0;
        while(it != nums.cend()){
            if((it -> first == it -> second) && (it -> first > result))
                     result = it -> first;
            it++;
        }
        if(result)  return result;
        else return -1;
    }
};
```

