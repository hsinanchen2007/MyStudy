### 解题思路
快速选择

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k < 1)
            return vector<int> ();
        partition(arr, 0, arr.size() - 1, k - 1);//注意这里是下标k-1
        vector<int> res(k);
        for(int i = 0; i < k; ++i)
            res[i] = arr[i];
        
        return res;
    }
private:
    void partition(vector<int>& arr, int left, int right, int k){
        int p = fast_sort(arr, left, right);
        if(p == k)//此时前k个元素是前k小的元素
            return;
        else if(p > k){//说明第k小的元素在[left, p）
            partition(arr, left, p - 1, k);            
        }
        else{//说明第k小的元素在（p,right]
            partition(arr, p + 1, right, k);
        }
    }
    int fast_sort(vector<int>& arr, int left, int right){       
        
        int flag = arr[left];
        int l = left, r = right;
        while(l < r){
            while(l < r && arr[r] >= flag)
                --r;
            arr[l] = arr[r];
            while(l < r && arr[l] < flag)
                ++l;
            arr[r] = arr[l];
        }
        arr[l] = flag;
        return l;
    }
};
```