1. 当任意区间**包含**大于R的数时不满足要求。
2. 当任意区间**只包含**小于L的数时不满足要求。
3. 满足要求的区间：**不包含大于R的数据并且至少包含一个位于区间[L,R]的数**。
4.  算法设计：
    1. 维护两个数据：目前为止最后一个大于R的数对应的索引(lastLargeThanRNumIndex)和最后一个位于区间[L,R]的数据的索引(lastInTheRangeNumIndex)；
    2. 当A[i] > R时，更新lastLargeThanRNumIndex
    3. 当A[i] < L时，如果lastInTheRangeNumIndex != -1 并且 lastInTheRangeNumIndex > lastLargeThanRNumIndex ，则有可能构成满足要求的区间,形式为：A[(lastLargeThanRNumIndex + 1)...lastInTheRangeNumIndex...i]。
    4. A[i]位于[L,R]中间时，更新lastInTheRangeNumIndex，则可能构成满足要求的区间，形式为A[(lastLargeThanRNumIndex + 1)...i]。

cpp代码：

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R) {
        int ans = 0;
        int lastLargeThanRNumIndex = -1;
        int lastInTheRangeNumIndex = -1;
        for (int i = 0; i < A.size(); ++i) {
            if(A[i] > R) {
                lastLargeThanRNumIndex =  i;
            } else if (A[i] < L ) {
                if(lastInTheRangeNumIndex  != -1 && lastInTheRangeNumIndex > lastLargeThanRNumIndex) {
                    ans += lastInTheRangeNumIndex - lastLargeThanRNumIndex;
                }
            } else {
                lastInTheRangeNumIndex = i;
                ans += i - lastLargeThanRNumIndex;
            }
        }
        return ans;
    }
};
```

swift代码：

```swift
class Solution {
    func numSubarrayBoundedMax(_ A: [Int], _ L: Int, _ R: Int) -> Int {
        var lastLargeThanRNumIndex = -1
        var lastInTheRangeNumIndex = -1
        var ans = 0
        for i in 0..<A.count {
            if A[i] > R {
                lastLargeThanRNumIndex = i
            } else if A[i] < L {
                if lastInTheRangeNumIndex != -1 && lastInTheRangeNumIndex > lastLargeThanRNumIndex {
                    ans +=  lastInTheRangeNumIndex - lastLargeThanRNumIndex
                }
            } else {
                lastInTheRangeNumIndex = i
                ans += i - lastLargeThanRNumIndex
            }
        }
        return ans
    }
}
```

