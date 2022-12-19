遍历数组，先填满保存k个数的结果数组res，当res满的时候，循环遍历res找出最大的值及其索引，然后和数组元素进行交换，最后返回结果res
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k,0);
        int index = 0;
        for(int i=0;i<arr.size();i++){
            if(index < k){
                res[index] = arr[i];
                index++;
            }
            else{
                pair<int,int> tmp(i, arr[i]);
                bool found = false;
                for(int j=0;j<k;j++){
                    if(tmp.second < res[j]){
                        tmp.second = res[j];
                        tmp.first = j;
                        found = true;
                    }
                }
                if(found){
                    res[tmp.first] = arr[i];
                }
            }
        }
        return res;
    }
};
```
