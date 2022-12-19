### 解题思路
本题要求至少**三种方法**，并且**空间复杂度是O（1）**

这里只列了一种思路，就是**三次反转**达到目的。

剩下的解法去看**官方解析**，很全面。

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        exchange(nums, 0, n - 1);//整体翻转
        exchange(nums, 0, k - 1);//前k个翻转
        exchange(nums, k, n - 1);//剩下的再翻转
    }
    
    private void exchange(int[] nums , int i, int j){
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
}
```