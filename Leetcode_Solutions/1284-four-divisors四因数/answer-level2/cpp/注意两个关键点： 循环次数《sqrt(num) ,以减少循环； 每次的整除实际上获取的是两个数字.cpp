### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    int val = 0;
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        int temp = 0;
        vector<int> tempV ;
        for (auto &ele:nums) {
            temp = getFactor(ele);
            if (temp == 4) {
                sum += val;
            }
        }
        return sum;
    }
    int getFactor(int num) 
    {
        vector<int> res; // no need to calc vector
        int cnt = 0;
        val = 0;
        int a = sqrt(num);
        for (int i =1; i <= a; i++) {
            if (num%i  == 0) {
                //res.push_back(i);
                cnt ++;
                val += i;
                val += num/i;
                if (cnt > 2) {
                    break;
                }
            }
        }
        if (a * a == num) {
            cnt = 2 * cnt -1;
        } else {
            cnt = 2 * cnt;
        }
        return cnt;
    }
};
```