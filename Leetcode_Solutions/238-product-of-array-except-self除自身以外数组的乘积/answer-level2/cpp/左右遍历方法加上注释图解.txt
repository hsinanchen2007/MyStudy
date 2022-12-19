### 解题思路
我就是发一下我写的注释. 方法是看评论里面各位的思路, 从左到右和从右到左的遍历相乘.
看我写的注释图解是不是也很好懂?

### 代码

```cpp
class Solution {
public:

    // | A  B  C  D  E |
    // |---------------|
    // | *  B  C  D  E |
    // | A  *  C  D  E |
    // | A  B  *  D  E |
    // | A  B  C  *  E |
    // | A  B  C  D  * |
    // -----------------
    // L->   1   A   AB  ABC  ABCD
    //    BCDE  CDE  DE   E   1   <-R

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // n > 1
        int L = 1;
        int R = 1;
        vector<int> ans(n, 1);
        for (int i=0, j=n-1; i<n; ++i, --j) {
            ans[i] *= L;
            L      *= nums[i];

            ans[j] *= R;
            R      *= nums[j];
        }
        return ans;
    }
};
```