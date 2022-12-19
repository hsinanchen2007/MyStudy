```
#include <algorithm>
class Solution {
public:
    bool compare(int A, int B) {
        
        string x1 = to_string(A) + to_string(B);
        string x2 = to_string(B) + to_string(A);
        for(int i = 0; i < x1.size(); ++i) {
            if(x1[i] < x2[i]) {
                return false;
            } else if (x1[i] > x2[i]){
                return true;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        for(int i = nums.size() - 1; i > 0; --i) {
            for(int j = nums.size() - 1; j > nums.size() - 1 - i; --j) {
                if(compare(nums[j], nums[j - 1]) == true) {
                     swap(nums[j], nums[j - 1]);
                }
            }
        }
        string forend;
        if(nums[0] == 0) {
            return to_string(0);
        }
        for(int m = 0; m < nums.size(); ++m) {            
            cout << nums[m] << " ";
            forend = forend + to_string(nums[m]);
        }
        return forend;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5bfea9ec1282093f3b3eded0c24d9750fa8e6601d92ebf6bd95b1a3b929fe4c6-image.png)
