![image.png](https://pic.leetcode-cn.com/152fd12ea7137dd7adf98f21d6e4871594be489eced51481445b23e3414bff40-image.png)
解题思路：数组一和数组二对比，相等则交换数组一中的数到前面去，最后sort(begin+tmp,end)即可。
```
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int tmp = 0;
        for(int i = 0;i<arr2.size();++i)
           for(int j = 0;j<arr1.size();++j){
               if(arr1[j] == arr2[i]){
                   swap(arr1[j],arr1[tmp]); ++tmp;
               }
           }
           sort(arr1.begin()+tmp,arr1.end());
           return arr1;
    }
```


