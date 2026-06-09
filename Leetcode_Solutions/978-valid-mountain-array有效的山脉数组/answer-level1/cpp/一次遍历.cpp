1. 遍历数组找到最高点，若最高点为第一个或者最后一个，则return false
2. 从最高点往后判断是否满足A[i]>A[i+1}]，不满足返回false


``` C++
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.empty()) return false;
        int index=0;
        while(index<A.size()-1)
        {
            if(A[index]<A[index+1])
            {
                index++;                
            }
            else
                break;
        }
        if(index==0||index==A.size()-1)
            return false;
        while(index<A.size()-1)
        {
            if(A[index]<=A[index+1])
                return false;
            index++;
        }
        return true;
    }
};
```