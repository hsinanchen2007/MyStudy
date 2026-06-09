![image.png](https://pic.leetcode-cn.com/4446c49fda8be409241f37b907de8aa0406925889bc22f50364e5541caafc3c3-image.png)
```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxnum=0;
        // 步骤1：找出arr1中的最大值
        for( int i=0; i<arr1.size(); i++ )
        {
            if( maxnum < arr1[i] )
                maxnum = arr1[i];
        }
        // 步骤2：建立arr1中数字和出现次数的vector变量
        vector<int> varr(maxnum+1,0);
        for( int i=0; i<arr1.size(); i++ )
        {
            varr[arr1[i]]++;
        }
        arr1.clear();
        // 步骤3：添加arr2中元素
        for( int i=0; i<arr2.size(); i++ )
        {
            for( int j=0; j<varr[arr2[i]]; j++ )
                arr1.push_back(arr2[i]);
            varr[arr2[i]] = 0;
        }
        // 步骤4：添加arr2中未出现过的元素
        for( int i=0; i<maxnum+1; i++ )
        {
            for( int j=0; j<varr[i]; j++ )
                arr1.push_back(i);
        }
        return arr1;
    }
};
```
