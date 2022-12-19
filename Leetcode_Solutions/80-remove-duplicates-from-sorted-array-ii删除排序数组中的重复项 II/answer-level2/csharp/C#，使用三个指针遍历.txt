### 解题思路
此处撰写解题思路
三个指针，i为数组遍历迭代器，j为计数器，k为重复数字计数器
### 代码

```csharp
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int j = 0;
        int k = 1;
        int length = nums.Length;
        if (length < 1) { //空数组的情况
            return 0;
        }
        if (length == 1) { //只有一个元素的情况
            return j + 1;
        }
        for (int i = 0; i < length; i++) {
            if (k >= 2) {  //重复个数大于等于2的情况
                if (nums[j] != nums[i]) { //出现变化
                    j++;
                    nums[j] = nums[i];
                    k = 1;  //重置重复数字计数器
                }

                }
            else {
                if (nums[j] != nums[i]) { //重复个数小于2且出现变化
                    j++;
                    nums[j] = nums[i];
                    k = 1;
                }
                else {
                    if (i != 0) { //第一项时的特殊情况
                    k++;
                    j++;
                    nums[j] = nums[i];
                    }
                }
            }
        }
        return j + 1;
    }
}
```