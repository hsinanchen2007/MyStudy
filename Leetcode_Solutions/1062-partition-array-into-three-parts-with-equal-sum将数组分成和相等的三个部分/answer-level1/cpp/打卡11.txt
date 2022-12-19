### 解题思路
  首先把A数组的总和计算出来，如果总和sum都不能整除3一定false的。
  之后，只需要一个一个累加过去，遇到和为sum的三分之一的，就个数加一，再把值给清零。
  如此反复，最后只需要看统计的个数是否为3就行。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(auto x : A){
            sum += x;
        }
        if(sum % 3)return false;
        int t = 0;
        int c = 0;
        int l = A.size();
        for(auto x : A){
            t += x;
            if(t == sum / 3){
                t = 0;
                c++;
            }
        }
        return c == 3;
    }
};
```