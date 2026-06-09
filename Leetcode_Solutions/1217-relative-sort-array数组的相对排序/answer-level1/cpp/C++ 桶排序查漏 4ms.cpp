### 解题思路
我这个略为麻烦但是速度还挺快
1.  先遍历题目的两个数组，将两个数组中共有的元素加入到另一个数组arr3
2.  桶排序长数组arr1和新数组arr3，看看哪个元素漏了，再加入到arr3去。

4ms,    96.79%
9.1MB,  17.60%

### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr3(0);
        
        for(int i = 0; i < arr2.size(); i++)
            for(int j = 0; j < arr1.size(); j++)
                if(arr2[i] == arr1[j])
                    arr3.push_back(arr1[j]);

        int aa[1001] = {0};
        for(int i = 0; i < arr1.size(); i++)
             aa[arr1[i]]++;

        int bb[1001] = {0};
        for(int i = 0; i < arr3.size(); i++)
            bb[arr3[i]]++;

        for(int i = 0; i < sizeof(aa)/sizeof(aa[0]); i++)
            if(aa[i]>0 && bb[i]==0)
                while(aa[i]--)
                    arr3.push_back(i);
        
        return arr3;
    }
};
```