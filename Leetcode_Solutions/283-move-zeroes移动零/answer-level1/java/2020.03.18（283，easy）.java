### 解题思路
本题使用一次for循环，定义一个**k索引**从**-1**开始

将非0元素挨个移动到**++k**索引位置，也就是数组前面的位置

遍历完非0元素后，再将空的位置用0补齐即可。

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int k = -1;
        for(int i = 0; i < n; i++){           
            if(nums[i] != 0){//把不为0的移动到前面              
                nums[++k] = nums[i];
            }      
            if(i != k){//剩下的位置都用0来补
                nums[i] = 0;
            }
        }
    }
}
```