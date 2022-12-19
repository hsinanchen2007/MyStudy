每次随机选取一个基准值arr[pivot]，将数组分成三部分：小于arr[pivot]的一部分，等于arr[pivot]的一部分，大于arr[pivot]的一部分。然后检查这个基准值最后所在的下标是不是arr.length - K，算法时间复杂度为O(n)。
具体步骤：
1. 在数组区间随机选取pivot = left + random[right-left]
2. 根据pivot做partition：
   - 小于arr[pivot]的部分放在左边
   - 等于arr[pivot]的部分放在中间
   - 大于arr[pivot]的部分放在右边
3. 得到partition的返回值
   - 返回值是一个人为规定的数组p，数组只有两个值
   - p[0]代表等于arr[pivot]的部分的左边界
   - p[1]代表等于arr[pivot]的部分的右边界
4. 分别比较p[0],p[1]与n-k的大小：
   - 如果p[0] > n - k ，向左寻找，继续寻找数组区间[left,p[0]-1]
   - 如果p[1] < n - k ，向右寻找，继续寻找数组区间[p[1] + 1,r]
   - 其他情况直接返回

```
public class Solution {

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        return quickSort(nums,0,nums.length - 1,len - k);
    }

    private int quickSort(int[] arr,int l,int r,int k){
        if (l == r) {return arr[l]; }

        int pivot = l + (int) (Math.random() * (r - l + 1));
        swap(arr,pivot,r);
        int[] p = partition(arr,l,r);
        if (p[1] < k){
            return quickSort(arr,p[1] + 1,r,k);
        } else if (p[0] > k){
            return quickSort(arr,l,p[0]-1,k);
        } else {
            return arr[p[0]];
        }

    }

    private int[] partition(int[] arr,int l,int r){
        int less = l - 1;
        int more = r;

        while(l < more){
            if (arr[l] < arr[r]){
                swap(arr,++less,l++);
            } else if (arr[l] > arr[r]) {
                swap(arr,--more,l);
            } else {
                l++;
            }

        }
        swap(arr,more,r);
        return new int[] {less+1,more};
    }

    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
```
