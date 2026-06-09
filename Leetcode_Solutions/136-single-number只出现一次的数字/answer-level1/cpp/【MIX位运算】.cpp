### 解题思路
$$
\begin{aligned}
&X \oplus X = 0 \\
&X \oplus 0 = X \\
&X \oplus Y \oplus Z = X \oplus Z \oplus Y
\end{aligned}
$$

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for(int x: nums)
            res ^= x;

        return res;
    }
}
```
```python []
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for x in nums:
            res ^= x

        return res
```
```c++ []
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto &x: nums)
            res ^= x;

        return res;
    }
};
```