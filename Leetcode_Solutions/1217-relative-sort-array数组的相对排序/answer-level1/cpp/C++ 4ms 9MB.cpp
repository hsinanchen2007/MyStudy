1.先遍历题目的两个数组，将两个数组中共有的元素加入到另一个数组ans，并将第一个数组中的该元素的值改为-1。
2.对第一个数组进行排序，重新遍历第一个数组，将不等于-1的添加到ans数组后面。
```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans; 
        for(auto a2:arr2){
            for(int i=0;i<arr1.size();i++){
                if(arr1[i]==a2){
                    ans.push_back(arr1[i]);
                    arr1[i]=-1;
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]==-1) continue;
            ans.push_back(arr1[i]);
        }
        return ans;
    }
};
```
