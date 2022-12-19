```cpp []
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        return max(0, *max_element(A.begin(), A.end()) - K - (*min_element(A.begin(), A.end()) + K));
    }
};
```
```scala []
object Solution {
  def smallestRangeI(A: Array[Int], K: Int): Int = {
    0.max(A.max - A.min - 2 * K)
  }
}
```
