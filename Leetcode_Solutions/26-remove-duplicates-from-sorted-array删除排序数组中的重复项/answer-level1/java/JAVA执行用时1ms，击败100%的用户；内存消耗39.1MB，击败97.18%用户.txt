### 解题思路
**快慢指针
1：设定两个指针，一个指针从初始位置0开始，步长为1，另一个指针从1开始，步长也为1；
2: 当快指针等于慢指针时，交换快指针和慢指针+1位置的数值，同时两个指针同时前进1步，计数器（新数组长度）加一；
3： 如果不相等，快指针继续q前进，慢指针不动；**
![删除排序数组中的重复项.png](https://pic.leetcode-cn.com/aa1804443f28bacc4df64bd5ace3ebb4576f5c058877d0a2cb45a59363c1895c-%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E9%A1%B9.png)

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length < 1){
            return 0;
        }
        if(nums.length == 1){
            return 1;
        }
        int i = 0;
        int j = 1;
        int count = 1;
        while(j < nums.length){
            if (nums[j] == nums[i]){
                j++;
            }else{
                int b = nums[i+1];
                nums[i+1] = nums[j];
                nums[j] = b;
                i++;
                j++;
                count++;
            }
        }  
        return count;  
    }
}
```