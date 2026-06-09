### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
  string largestTimeFromDigits(vector<int>& A){
    sort(A.begin(), A.end(), greater<int>());
    do{
      if (A[0] * 10 + A[1] < 24 && A[2] * 10 + A[3] < 60)
      return string("") + (char)('0'+A[0]) + (char)('0'+A[1]) 
        + ":" + (char)('0'+A[2]) + (char)('0'+A[3]);
    } while (next_permutation(A.begin(), A.end(), greater<int>()));
    return"";
  }
};
```