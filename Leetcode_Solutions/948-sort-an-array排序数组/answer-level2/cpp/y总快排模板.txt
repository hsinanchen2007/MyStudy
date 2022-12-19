```
class Solution {
public:
    void quickSort(vector<int>& q, int l , int r){
        if(l >= r)return;
        int x = q[l + r >> 1] , i = l - 1, j = r + 1;
        while(i < j){
            do i++; while(q[i] < x);
            do j--; while(q[j] > x);
            if(i < j)swap(q[i],q[j]);
        }
        quickSort(q, l , j);
        quickSort(q,j + 1, r);

    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() -1);
        return nums;
    }
};
```

