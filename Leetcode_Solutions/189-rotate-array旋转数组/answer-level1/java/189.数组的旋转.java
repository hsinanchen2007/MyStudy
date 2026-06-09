### 解题思路
1.把后面的k个元素存储备份
2.所有的元素向后平移k个单位  
3.把备份的存回来

### 代码

```java
class Solution {
    public void rotate(int[] nums, int k) {
        int[] current = new int[k];
        int leng = nums.length;
        k %= leng;
        for (int i = 0; i < k; i++) {
            current[i] = nums[leng - k + i];
        }
        for (int i = (leng - 1); i > k - 1; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = current[i];
        }
    }
}
```