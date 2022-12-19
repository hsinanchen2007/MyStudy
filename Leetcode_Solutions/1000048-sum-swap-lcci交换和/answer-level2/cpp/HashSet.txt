##代码
'''
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        // 分别计算两个array的和，并将array2的值存入hashset
        int sumArray1 = 0;
        int sumArray2 = 0;
        unordered_set<int> hash;
        for(int i:array1){
            sumArray1 += i;
        }
        for(int i:array2){
            sumArray2 += i;
            hash.insert(i);
        }

        // 如果两个array的总和为奇数，说明不存在使两array的和相等的情况
        if((sumArray1+sumArray2)%2==1) return {};

        // 遍历array1, 查找在array2中是否存在满足条件的数
        int targets = (sumArray1+sumArray2)/2 -sumArray1;    
        for(int i=0; i<array1.size(); i++){
            int ca1 = array1[i];
            int ca2 = ca1+targets;
            if(hash.count(ca2)) return {ca1, ca2};
        }
        return {};
    }
};
'''