递增排序的数组字典序最小，当出现I时，保持顺序不变，当出现一段连续的D时，将这段D对应的数组反转即可。
```c++
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> nums;
        for(int i=0; i <= s.length(); i++){
            nums.push_back(i+1);
        }
        auto left = nums.begin();
        auto right = nums.begin();
        for(int i=0; i <= s.length(); i++){
            if(s[i] == 'I' || i == s.length()){
                reverse(left, right+1);
                left = right = nums.begin()+i+1;
            }
            if(s[i] == 'D'){
                right += 1;
            }
        }
        return nums;
    }
};
```