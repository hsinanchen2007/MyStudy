class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> commonarry;
        int hash[2000] = {0};//用hash数组遍历三个数组求出现三次的数字，然后添加到新数组里，无需排序，直接返回就好。
        for(int i = 0; i < arr1.size(); i++)
        {
            hash[arr1[i]]++;
        }
        
        for(int i = 0; i < arr2.size(); i++)
        {
            hash[arr2[i]]++;
        }
        
        for(int i = 0; i < arr3.size(); i++)
        {
            hash[arr3[i]]++;
        }
        
        for(int i = 0; i < arr1.size(); i++)
        {
            if(hash[arr1[i]] == 3)
                commonarry.push_back(arr1[i]);
        }
        
        return commonarry;
    }
};