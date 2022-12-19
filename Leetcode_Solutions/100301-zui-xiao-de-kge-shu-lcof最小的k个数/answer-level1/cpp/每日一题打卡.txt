### 解题思路
Partition函数+二分的写法，很久不做有些生疏，第一次写的程序出现了3处低级错误。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        const int n = arr.size();
        vector<int> ans;
        if(n < k || k < 1) return ans;

        int left = 0, right = n-1;
        int index = -1;
        while(left < right && index != k-1) { //Bug3:k换成k-1,否则有的case中会在partition中出现right-left+1==0的情况
            if(index > k-1) {
                right = index - 1;
                index = Partition(arr, left, right);
            }
            else if(index < k-1) {
                left = index + 1;
                index = Partition(arr, left, right);
            }
        }
        
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    int Partition(vector<int>& arr, int left, int right) {
        int index = left + rand() % (right-left+1); //Bug1:忘记+left
        swap(arr, index, right);

        int less = left - 1;
        for(int i = left; i < right; i++) {
            if(arr[i] < arr[right]) {
                swap(arr, ++less, i);
            }
        }
        swap(arr, ++less, right);
        return less; //Bug2:index;
    }

    void swap(vector<int>& arr, int left, int right) {
        if(left == right) 
            return;
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
};
```