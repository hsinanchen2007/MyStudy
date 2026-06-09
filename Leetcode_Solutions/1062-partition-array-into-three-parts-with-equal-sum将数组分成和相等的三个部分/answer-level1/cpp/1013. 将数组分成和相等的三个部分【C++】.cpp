### 解题思路

这个题不难，首先需要明白的是，如果一个数组能如题述那样分成三等分，那么这三个和相等，并且三个等分的和相加即为整个数组所有元素的和。

求整个数组的和 `sum` 是很简单的，如果这个数组能三等分则每个等分的和即为 `sum/3` ，所以我们只需要遍历数组，逐个元素相加求和 `sumOfPart`，一旦 `sumOfPart == sum / 3` 则说明找到了一个等分，此时将 `sumOfPart` 重置为0（以开始计算新的一部分的部分和），并将 `part++` 表示新找到了一个等分。

特别需要注意的是，当 `sum == 0` 的时候，`sumOfPart == 0` 是可能存在多个部分的，即 `part >= 3`，但不能小于3，因为至少需要三等分。

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto a : A) {
            sum += a;
        }
        int part = 0;
        int sumOfPart = 0;
        for (auto a : A) {
            sumOfPart += a;
            if (sumOfPart == sum / 3) {
                sumOfPart = 0;//将部分和重置为0
                part++;//组数+1
            }
        }
        return part >= 3 ? true : false;
    }
};
```