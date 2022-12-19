### 解题思路

思路和快速排序一样，O(1)的空间复杂度，

partition函数根据 算法导论 第7章的 伪代码修改

parition函数用于将数组分为三个部分，一个部分都小于x，一个部分都大于x，以及一个中间数

根据中间值的坐标来判断后续的搜索范围


```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if ( k == 0 ){
            return vector<int>();
        }
        qucikSearch(arr, 0, arr.size()-1, k-1);
        vector<int> res(arr.begin(), arr.begin()+k);
        return res;
    }

    void qucikSearch(vector<int>& arr, int p, int r, int k){
        int m = partition(arr, p, r);
        if ( k == m ) return;
        if ( k < m ) {
            qucikSearch(arr, p, m-1, k);
        } else{
            qucikSearch(arr, m+1, r, k);
        }
        return ;
        
    }

    int partition(vector<int>& arr, int p, int r){

        int x = arr[r]; 
        int i = p ;
        for ( int j = p; j < r ; j++){
            if (arr[j] < x){
                if (i != j) std::swap(arr[i], arr[j]);
                i++;
            }
        }
        std::swap(arr[i], arr[r]);
        return i;
    }

};

```