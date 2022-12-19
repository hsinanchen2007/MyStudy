### 解题思路
通过双指针，将前面的偶数与后面的基数进行交换。

因为奇数二进制末位为1,偶数二进制末位为0,所以用位运算来判断奇偶性。`n&1 == 1`表示n为奇数，`n&1 == 0`表示n为偶数。

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int p = 0;  // 指向第一个元素
        int q = nums.size() - 1;   // 指向第二个元素

        while(p < q){
            // 当第一个指针小于第二个指针时
            // while(p < q && nums[p] % 2 != 0){
            while(p < q && (nums[p] & 1) != 0){
                // 移动第一个指针直到找到一个偶数
                ++p;
            }
            // while(p < q && nums[q] % 2 != 1){
            while(p < q && (nums[q] & 1) != 1){
                // 移动第二个指针直到遇到一个奇数
                --q;
            }
            if(p < q){
                int temp = nums[p];
                nums[p] = nums[q];
                nums[q] = temp;
            }
        }
        return nums;
    }
};
```