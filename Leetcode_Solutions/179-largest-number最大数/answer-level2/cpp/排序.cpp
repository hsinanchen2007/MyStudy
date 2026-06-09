重写排序比较器，调用STL排序，然后拼接成string.
```
class Solution {
    static bool greater(const int &i, const int &j){
        return to_string(i)+to_string(j)>to_string(j)+to_string(i);
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater);
        string res;
        for(int i=0; i<nums.size(); res.append(to_string(nums[i++])));
        if(res.length()<0 || res[0]=='0') res="0";
        return res;
    }
};
```
