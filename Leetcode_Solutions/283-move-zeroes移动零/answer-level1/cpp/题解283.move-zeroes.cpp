### 解题思路
题解：使用index索引：
1、指针j用来指向非零数应该存储的位置，指针i用来遍历数组；
2、在i遍历时，把所有非零数转移到j的位置同时将j加1向后移动一位；
3、只有j<=i，当j!=i，已经完成nums[i]赋值给nums[j]，若是[1,0,0,0,2]变为[1,2,0,0,2]，则此时nums[i]
仍为原来非零数，所以需要将此时的nums更换为0。
ps：可以使用从前向后不断交换零和非零项的办法。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i =0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (i != j) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};
// 1.loop; count zeros;
```