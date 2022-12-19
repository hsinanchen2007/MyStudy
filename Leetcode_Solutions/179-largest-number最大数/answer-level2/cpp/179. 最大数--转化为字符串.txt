### 解题思路

执行用时 :20 ms, 在所有 C++ 提交中击败了39.88%的用户

### 代码

```cpp
bool cmp(string a, string b){
        return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty()) return "";
        vector<string> nums_string;
        for(int num: nums){
            string tmp = to_string(num);
            nums_string.push_back(tmp);
        }
        sort(nums_string.begin(), nums_string.end(), cmp);
        string rt;
        for(string str: nums_string){
            rt += str;
            if(nums_string[0]=="0") break;
        }
        return rt;
    }
};
```