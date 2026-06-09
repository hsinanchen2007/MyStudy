### 解题思路
思路见代码

### 代码

```java
import java.util.Random;

/**
 * 求数组中第k大元素
 * 方法1：先排序
 * 方法2：最小堆法
 * 方法3：快排法
 */
class Solution {
    Random random = new Random();

    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        int l = 0;
        int r = n-1;
        while(true){
            int j = partition(nums, l, r);
            if(j == n-k){
                return nums[j];
            }
            else if(j < n-k){
                // 右侧
                l = j+1;
            }
            else {
                // 左侧  j > k-1
                r = j-1;
            }
        }
    }

    // 给arr[l:r]进行partition操作，即返回值为p 保证arr[l:p)<arr[p]<=arr(p:r]
    private int partition(int[] arr, int l, int r){
        // 随机化
        if(r>0 && r-l+1 > 0)
            swap(arr, l, random.nextInt(r) % (r-l+1) + l);

        int i = l+1, j = l+1;
        int val = arr[l];
        // 保证arr[l+1:i)<val<=arr[i,j)
        while(j<=r){
            if(arr[j] < val){
                swap(arr, i++, j++);
            }else {
                j ++;
            }
        }

        swap(arr, l, --i);
        return i;
    }

    // 交换
    private void swap(int[] arr, int i, int j){
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
```