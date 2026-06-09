![image.png](https://pic.leetcode-cn.com/ca7ae5511ce8758ad074fb930ddcff6d5f11d474743887b6ed99110228f966b6-image.png)

### 解题思路
快排的partion过程是会改变原数组的。并且会返回一个下标。
这个下标指向改变之后的数组的一个位置。
这个位置及其左边的数，都要比这个位置的右边的数要小。

所以，如果我partition之后返回的是k-1，那么就说明当前这个划分之后的数组的[0,k-1]这k个数，就是我想要的。如果不是k-1，那么就看情况在左右两边继续递归调用就好了。

时间复杂度和快排一样，最坏是O(n2),平均是O(nlogn)
空间复杂度也和快排一样，O(1)

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int t = fun(arr,0,arr.size()-1,k);
        vector<int> res(arr.begin(),arr.begin() + t+1);
        return res;
    }
    int fun(vector<int>& arr, int start, int end, int k){
        if(k == end-start+1) return end;
        int objk = start + k -1;// [start, objk],一共k个数
        int i = partition(arr,start, end);
        if(i == objk){
            return i;
        }else if(i > objk){
            return fun(arr,start,i-1,k);
        }else{//i要比objk小，本次划分的不够多，需要在右边继续划分出一些来
            return fun(arr,i+1,end,k-(i+1-start));
        }
    }
    int partition(vector<int>& arr, int start, int end){
        int i = start-1;
        int x = arr[end];
        for(int j=start; j<end; j++){
            if(arr[j]<=x){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        i++;
        swap(arr[i],arr[end]);
        return i;
    }
};
```
周五，比较放松，简单题复杂化消磨时间。成功了，小得意~