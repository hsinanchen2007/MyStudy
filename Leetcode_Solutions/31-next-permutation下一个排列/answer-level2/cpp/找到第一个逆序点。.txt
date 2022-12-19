### 解题思路

这道题题目读起来太绕了。   主要就是要找到第一个逆序的点。 然后把逆序点开始的后面的数排序了。  再找到第一个大于逆序点前一个数的数。
如[2,3,1]   找到第一个逆序点。位置为1.把位置1开始到最后的数排序。这里使用了reverse函数，参数是两个迭代器。 变成了[2,1,3]。然后把位置0的数和第一个大于它的数交换。 最后变成[3,1,2] 。

reverse函数功能是逆序（或反转），多用于字符串、数组、容器。头文件是#include <algorithm>
reverse函数用于反转在[first,last)范围内的顺序（包括first指向的元素，不包括last指向的元素），reverse函数无返回值

swap 包含在命名空间std 里面
swap(a,b);（交换两个数）



执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了69.26%的用户

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int reverserindex = nums.size()-1;
        while(reverserindex>0&&nums[reverserindex]<=nums[reverserindex-1])
            --reverserindex;
        reverse(nums.begin()+reverserindex,nums.end());
        if(reverserindex>0)
        {
            for(int i = reverserindex;i<nums.size();++i){
                if(nums[reverserindex-1]<nums[i])
                {
                    swap(nums[reverserindex-1], nums[i]);
                    break;
                }
            }
        }

    }
};
```