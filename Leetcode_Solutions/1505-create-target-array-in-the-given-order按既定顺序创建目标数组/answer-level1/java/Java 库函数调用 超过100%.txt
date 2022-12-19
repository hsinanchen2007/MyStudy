### 解题思路
一开始找不到类似C中的Insert方法就自己写了一个插入方法
刚刚找到了vector中的add跟insert类似，但是因为Vector需要用Integer定义所以在add完之后需要加到一个新的int数组中

### 代码

```java
import java.util.Vector;
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        Vector<Integer> ans = new Vector<>();
        int n = nums.length,i;
        ans.clear();
        for (int j = 0; j <n ; j++) {
            ans.add(index[j],nums[j]);
        }
        int[] arr = new int[nums.length];
        for (int j = 0; j < ans.size(); j++) {
            Integer A = ans.get(j);
            arr[j] = A.intValue();
        }
        return arr;
    }
}
```