### 解题思路
- 核心思路：实质为利用快排思想找到第k小的数，然后将它和它之前的元素存入vector返回
- 执行用时：52 ms, 在所有 C++ 提交中击败了42.13%的用户
- 内存消耗：18.7 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0)return {};
        if(k>=arr.size())return arr;
        vector<int>result(k);
        quickSelect(arr,0,arr.size()-1,k);
        for(int i=0;i<k;i++)result[i]=arr[i];
        return result;
    }
    void quickSelect(vector<int>&arr,int begin,int end,int k){
        int m=partition(arr,begin,end);
        if(m==k)return;
        else if(m<k){
            quickSelect(arr,m+1,end,k);
        }
        else{
            quickSelect(arr,begin,m-1,k);
        }
    }
    int partition(vector<int>&arr,int begin,int end){
        int tmp=arr[begin];
        while(begin<end){
            while(begin<end&&arr[end]>=tmp)end--;
            arr[begin]=arr[end];
            while(begin<end&&arr[begin]<=tmp)begin++;
            arr[end]=arr[begin];   
        }
        arr[begin]=tmp;
        return begin;
    }
};
```