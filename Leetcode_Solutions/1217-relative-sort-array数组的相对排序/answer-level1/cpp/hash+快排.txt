### 解题思路
首先利用hash统计arr1中每个数的个数，这里要注意，hash数组的大小要超过1000，不然会栈溢出
然后利用arr2数组来查找hash里面不为0的个数，构造一个循环，push到vector数组中
最后，将arr1数组排序一下，然后循环查找没有被push到vector数组的数，即hash里面剩下的不为0的数，排序是为了题目要求的升序

### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len = arr1.size();
        int len2 = arr2.size();
        vector<int> t;
        int p[1005]={0};
        for(int i = 0;i<len;i++){
            p[arr1[i]]++;
        }
        for (int i =0;i<len2;i++){
            while(p[arr2[i]]>0){
                t.push_back(arr2[i]);
                p[arr2[i]]--;
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i = 0;i<len;i++){
            while(p[arr1[i]]>0){
                t.push_back(arr1[i]);
                p[arr1[i]]--;
            }
        }
        return t;


    }
};
```