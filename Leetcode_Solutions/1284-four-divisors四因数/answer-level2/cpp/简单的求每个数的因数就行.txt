### 解题思路
![image.png](https://pic.leetcode-cn.com/2870d62f0067abfba91a85acabf5d343d969de02cfd4125031675840c57c89e0-image.png)


### 代码

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            vector<int> pr;
            if (primer(num, pr)) {
                sum += (1 + num + pr[0] + pr[1]);
            }
        }

        return sum;
    }

    bool primer(int num, vector<int>& pr) {
        if (num <= 1) return false;
        for (int k = 2; k * k <= num; ++k) {
            if (num % k == 0) {
                pr.push_back(k);
                num/k != k ? pr.push_back(num/k) : void();
            }
        }

        return pr.size() == 2;
    }
};
```