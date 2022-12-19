### 解题思路
首先我们将给出的数组进行排序，排序是从小到大排列的，也就是`A[i] >= A[i-1]`，然后我们从第一个位置通过与前面进行比较，看是否需要操作。如果这次比较的数字与前一次一样大，那么这个位置的数字需要操作一次，一次也是最小的操作数。 因为我们改变了原来数组的内容，可能出现`A[i] < A[i-1]`，例如这个例子`[2,2,2]`,出现这个情况我们按照题意最少的操作数是使`A[i]` 变成`A[i-1]+1`。当然当`A[i] >A[i-1]`的时候是不需要操作的。

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin() ,A.end());
        if (A.size() == 0 || A.size() == 1)
            return 0;
        int count = 0;
        for(int i = 1; i < A.size(); i++){
            if (A[i] == A[i-1]){
                A[i]++;
                count++;
            }else if (A[i] < A[i-1]){
                int temp = A[i];
                A[i] = A[i-1]+1;
                count = count +(A[i] - temp);
            }
        }
        return count;

    }
};
```