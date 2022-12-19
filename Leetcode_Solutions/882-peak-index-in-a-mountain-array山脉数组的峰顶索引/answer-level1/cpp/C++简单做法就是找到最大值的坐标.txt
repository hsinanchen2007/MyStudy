实际就是求数组A中的最大值的坐标
```
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int max = A[0]; //最大值
        int j = 0; //保存最大值的坐标
        for(int i=0; i<A.size(); i++){
            if(A[i]>max){
                max = A[i];
                j = i;
            }
        }
        return j;
    }
};
```
