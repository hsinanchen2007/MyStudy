### 解题思路
**平均时间复杂度 O(n)**
利用快排的思路
* 先按照中点值x为基准值划分，求得基准值pivot，是的基准值的左边都是小于等于x， 右边都是大于等于x的数。
* 若左边的个数大于等于k个，说明答案在左边，并在左边找第k个数。
* 若左边的个数小于k个，说明答案在右边，并在右边找`k-left的个数`（因为前面已经有left个数了，所以要从从右边相对位置找起。）
    例子：
    ```cpp
          p
    3 2 3 4 8 4 9

    /*
    p的左边都是小于等于4， p的右边都是大于等于4
    若要找第6小的数，就要找p之后的第2小的数。 因为p以及左边有4个数，所以6-4就是找右边第2小的数。  即总体第6小的数
    */
    ```

### 代码

```cpp
class Solution {
public:
    int partition(vector<int>& arr, int l, int r) {
        int x = arr[l + r >> 1];
        int i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (arr[i] < x);
            do j--; while (arr[j] > x);
            if (i < j) swap(arr[i], arr[j]);
        }
        return j;
    }
    
    int quickSort(vector<int>& arr, int l, int r, int k) {
        if (l == r) return l;
        int pivot = partition(arr, l, r);
        int left = pivot - l + 1;
        if (left >= k) {
            return quickSort(arr, l, pivot, k);
        } else {
            return quickSort(arr, pivot + 1, r, k - left);
        }
    }
    
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        if (k == 0) return {};   // k等于0的时候需要特判
        int index = quickSort(arr, 0, n - 1, k);
        return vector<int>(arr.begin(), arr.begin() + index + 1);
    }
};
```