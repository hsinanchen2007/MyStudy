## 解法：双指针

对于这种数组问题，且涉及到分块的要求，双指针是一种常见的解题方法。

首先，如果在数组中存在和相等的三个部分，那么数组整体的和肯定是3的倍数。依据这一特点，可以排除一部分的输入。

接着：

* 初始化两个指针分别指向数组中下标为`1`的元素和下表为`n-2`的元素，这两个指针分别表示第二部分的起始下标和结束下标。第一个指针之前为第一部分，第二个指针之后为第三部分。

* 在移动指针的过程中，维护两个变量分别表示第一部分的和和第二部分的和；
* 如果上述两个变量的值相等，且为数组整体和的三分之一，则返回`true`；否则：
  * 如果第一部分的和不等于整体和的三分之一，则将起始指针向后移动一个位置；
  * 如果第二部分的和不等于整体和的三分之一，则将结束指针向前移动一个位置；
* 循环上述操作，直到起始指针大于结束指针，则返回`false`。

代码如下：

```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if (A.size() < 3)
            return false;
        int sum = 0;
        for (auto item: A){
            sum += item;
        }
        if (sum % 3 != 0)  // 和不为3的倍数，直接返回0
            return false;
        
        int part_2_start = 1;  // 第二部分的起始位置
        int part_2_end = A.size() - 2;  // 第二部分的终止位置
        int sum_part1 = A[0];
        int sum_part3 = A[A.size() - 1];
        
        while (part_2_start <= part_2_end){
            if (sum_part1 == sum / 3 && sum_part3 == sum / 3)
                return true;
            if (sum_part1 != sum / 3){
                sum_part1 += A[part_2_start];
                part_2_start++;
            }
            if (sum_part3 != sum / 3){
                sum_part3 += A[part_2_end];
                part_2_end--;
            }
        }
        return false;
    }
};
```

时间复杂度：$O(n)$，整个遍历过程最多将所有元素都访问一遍。