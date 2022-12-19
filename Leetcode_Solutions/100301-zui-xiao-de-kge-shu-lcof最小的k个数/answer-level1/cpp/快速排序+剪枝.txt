### 解题思路
在快速排序的结束条件处加多两个判断，当子排序的最右端小于k返回即可，不需要排序了，因为此时小于k的都在k的左边了，无需再对它们排序。同理，当子排序的最左端大于等于k时，亦无须再对它们排序了，因为只需要k个最小的。此处的index以0开头。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int len = arr.size();
        kk = k;
        quit_sort(arr, 0, len-1);
        vector<int> res(k);
        for (int i=0; i<k; i++) res[i] = arr[i];
        return res;
    }
private:
    int kk;
    void quit_sort(vector<int>& arr, int i, int j) {
        if (i >= j || j < kk || i >= kk) return ;
        int temp = arr[i];
        int l = i;
        int r = j;
        while (l < r) {
            while (l < r && arr[r] >= temp) r--;
            if (l < r) {
                arr[l] = arr[r];
                l++;
            }
            while (l < r && arr[l] <= temp) l++;
            if (l < r) {
                arr[r] = arr[l];
                r--;
            }
        }
        arr[l] = temp;
        quit_sort(arr, i, l-1);
        quit_sort(arr, r+1, j);
    }
};
```