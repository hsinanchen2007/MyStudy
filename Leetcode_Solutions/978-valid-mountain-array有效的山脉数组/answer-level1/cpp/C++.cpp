### 解题思路
找A中的最大值的位置maxpos，若最大值有重复，则一定不满足山脉数数组。
即山脉数组的最大值一定唯一，且其位置不在开头或者末尾
如果maxpos != 0 && maxpos != A.size()-1 && A[0] != max &&countmax == 1，返回true
否则返回false

### 代码

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
            return false;
        //找A中的最大值的位置maxpos，若最大值有重复，则找到最后一个出现的最大值位置
        //如果maxpos != 0 && maxpos != A.size()-1 && A[0] != max &&countmax == 1，返回true
        //否则返回false
        int max = A[0];     
        int maxpos = 0;  //最后一个出现的最大值位置
        int countmax = 1; //最大值的个数
        for(int i = 1; i < A.size(); i++){
            if(A[i] > max){
                max = A[i];
                maxpos = i;
                countmax = 1;
            } else if(A[i] == max){
                countmax++;
            }
            //判断是否满足A[0] < A[1] < ... A[i-1] < A[i]
            if(A[i] < max && i < maxpos && A[i] <= A[i-1])
                return false;
                //判断是否满足A[i] > A[i+1] > ... > A[B.length - 1]
            else if(i != A.size() - 1 && A[i] < max && i > maxpos && A[i] <= A[i+1])
                return false;
        }
        if(maxpos != 0 && maxpos != A.size()-1 && A[0] != max && countmax == 1)
            return true;
        else 
            return false;
    }
};
```