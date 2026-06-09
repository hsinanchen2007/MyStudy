### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int a[8]={3,3,3,3,3,4,3,4};
    char all[8][4]={
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0) return result;
        vector<int> nums;
        for(int i=0;i<digits.length();i++){
            nums.push_back(0);
        }
        while(true){
            //增加
            string s;
            for(int i=0;i<nums.size();i++){
                s+=all[digits[i]-'2'][nums[i]];
            }
            result.push_back(s);
            nums[0]++;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>=a[digits[i]-'2']){
                    nums[i]-=a[digits[i]-'2'];
                    nums[i+1]++;
                }
            }
            if(nums[nums.size()-1]>=a[digits[nums.size()-1]-'2']) return result;
        }
    }
};
```