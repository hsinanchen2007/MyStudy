```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 这个问题可以拆分成两步来实现
        // step1 : 
        // 找到arr2中的元素分别在arr1中出现了多少次；map<int,int> mapArr 
        // 同时找出没有在arr2中出现过的元素并对其进行排序。vector<int> norArr
        map<int,int> mapArr;
        vector<int> norArr;
        int norIndex = 0;
        for(int i = 0;i != arr2.size();i++){
            mapArr[arr2[i]] = 1;
        }
        for(int i : arr1){
            if(mapArr[i] != 0){
                mapArr[i]++;
            }else{
                norArr.push_back(i);
                norIndex++;
            }
        }
        sort(norArr.begin(),norArr.end());

        //step2 :
        //根据mapArr的计数来处理arr1中有在arr2中出现的元素
        //根据norArr来处理arr1中没有在arr2中出现的元素
        vector<int> resultVec(arr1.size(),0);
        int resultIndex = 0;
        for(int i = 0;i != arr2.size();i++){
            for(int j = 0;j != mapArr[arr2[i]] - 1;j++){
                resultVec[resultIndex++] = arr2[i];
            }
        }
        for(int i = 0;i != norArr.size();i++){
            resultVec[resultIndex++] = norArr[i];
        }

        return resultVec;
    }
};
```
