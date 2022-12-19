### 解题思路：
**分析**：
- **快指针**：遍历整个数组；
- **慢指针**：记录可以覆写数据的位置；
- 题目中规定**每个元素最多出现两次**，因此，应检查**快指针**指向的元素和**慢指针**指针所指向单元的前一个元素是否相等。相等则不更新慢指针，只更新快指针；不相等时，先将**慢指针**后移一位，再将**快指针**指向的元素覆写入**慢指针**指向的单元，最后更新**快指针**（详见图解）。

**边界**：
- 当数组的长度小于等于 2 时，不需要操作，直接返回原数组即可。

**初始化**：
- **快指针**用于遍历数组，但算法不可能操作序号小于 2 的元素，因此**快指针**初始值为 2；
- 初始状态下，**慢指针**应紧随**快指针**之后，因此初始值为 1；

**结束条件**：
- **快指针**达到数组结尾。

### 图解：
<![pics.001.jpeg](https://pic.leetcode-cn.com/b8ea4146679d75284c2cd2fba5a208e7ef6d9a310d603aac1717cc310b60cc41-pics.001.jpeg),![pics.002.jpeg](https://pic.leetcode-cn.com/d042376f7379afbaebba42297e9ecdcd27d1c849a68b8a1b0dd94b472cdca3e9-pics.002.jpeg),![pics.003.jpeg](https://pic.leetcode-cn.com/597eb923940ce182a7f57f6073d1560847511df44e4ae48630376167fe46f01d-pics.003.jpeg),![pics.004.jpeg](https://pic.leetcode-cn.com/b6e6f10a73e1702f9d2db4d2d507f867dd4156a331470bf57337ddb4a958fbb5-pics.004.jpeg),![pics.005.jpeg](https://pic.leetcode-cn.com/c823c2e29f0468e9d27a3e7eb89a324cbdd72a5ab9518ae82deca92654cf19f4-pics.005.jpeg),![pics.006.jpeg](https://pic.leetcode-cn.com/eb1128b6f46c7613cd9badcfccd329405dc81f492bdb4dbfd77a4cfa3242b464-pics.006.jpeg),![pics.007.jpeg](https://pic.leetcode-cn.com/34998ca628608b109902fe6d6366f57abf4deb2447694aa6b0c735c4b675b8d9-pics.007.jpeg),![pics.008.jpeg](https://pic.leetcode-cn.com/45cb9ac5cbb5949abd7940b3df07fe876fdfbcf2ddd3fc34892291ddbf6df16b-pics.008.jpeg),![pics.009.jpeg](https://pic.leetcode-cn.com/9ee49e7b2384d6af026813ad710b169a3133f537e1986d8a978514d433fb18e0-pics.009.jpeg),![pics.010.jpeg](https://pic.leetcode-cn.com/a066413e28f89bbe43488907004e8df14d580d6e1978e1aa3fc056fe3358ac4c-pics.010.jpeg),![pics.011.jpeg](https://pic.leetcode-cn.com/808e52779b57a1f790787e6f0879117358e90c4e5233c15ed3ffc32abb5fdcf9-pics.011.jpeg),![pics.012.jpeg](https://pic.leetcode-cn.com/5d28e56b59b11246c622b7e64320edb87197728db31d07e5ea1f91f978fe3d71-pics.012.jpeg)>


### 代码：
```cpp []
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
        {
            return n;
        }
        int sp = 1;
        for(int fp = 2; fp < n; fp++)
        {
            if(nums[fp] != nums[sp - 1])
            {
                nums[++sp] = nums[fp];
            }
        }
        return sp + 1;
    }
};
```
