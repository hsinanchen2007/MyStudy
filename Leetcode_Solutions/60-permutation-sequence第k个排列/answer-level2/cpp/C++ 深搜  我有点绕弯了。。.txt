### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    string tmp;
    string res;
    vector<char> nums;
    int num = 0;

public:
    string getPermutation(int n, int k) {
        int n1 = 1;
        for (int i = 2; i < n; i++) {
            n1 *= i;
        }
        int n2 = k / n1;
        k -= n1 * n2;
        if (k > 0) {
            n2++;
        } else {
            k = n1;
        }
        
        res += n2 + '0';
        for (int i = 0; i < n2 - 1; i++) {
            nums.push_back(i + 1 + '0');
        }
        for (int i = n2; i < n; i++) {
            nums.push_back(i + 1 + '0');
        }

        generate(n, k, nums);

        return res;      
    }

    void generate(int n, int k, vector<char> nums) {
        if (num == k) {
            return;
        }
        if (nums.size() == 0) {
            num++;
            if (num == k) {
                res += tmp;
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            vector<char> one = nums;
            one.erase(one.begin() + i);
            tmp.push_back(nums[i]);
            generate(n, k, one);
            tmp.pop_back();
        }
    }
};
```