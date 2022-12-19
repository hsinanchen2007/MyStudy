### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand(time(nullptr));
        __quickSort(arr,0,arr.size()-1,k);
        vector<int> res;
        for(int i=0;i<k;i++) res.push_back(arr[i]);
        return res;
    }

private:
    void __quickSort(vector<int>& arr, int l,int r,int k){

        if (l>=r)
            return;
        //partition操作，快速排序的核心
        //将小于标定点的数放在左半边，大于标定点的数放在右半边
        //partition完成以后，arr[l,j-1]<arr[j],arr[j+1,r]>arr[j]
        int j=l;
        swap(arr[l],arr[rand()%(r-l+1)+l]);
        int temp=arr[l];

        for(int i=l+1;i<=r;i++){
            if(arr[i]>temp) continue;
            else {
                swap(arr[++j],arr[i]);
            }
        }
        swap(arr[l],arr[j]);

        //partition完成后右半边的所有数都大于左半边，此时判断左半边[l,j]的元素个数即可得当前数组中的num=j-l+1个最小的数字
        //此时如果这个数字刚好等于要求的k，则立即终止递归，这些数字就是要求的k个最小数。
        //若num>k，则表示左半边中最小数字的范围小于要求范围，在[l,j-1]中在找出k个最小数字
        //若num<k，表示左半边的最小数字不足，剩下的k-num个数，要在右边找
        int cur_num=j-l+1;
        if(cur_num==k) return;
        else if(cur_num>k) __quickSort(arr,l,j-1,k);
        else __quickSort(arr,j+1,r,k-cur_num);
    }
};
```