### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for(int i = 0; i<A.size();i++)
            sum+=A[i];
        if(sum%3!=0)
            return false;
        int i = 0;
        int sum1=0;
        while(i<A.size()){
            sum1+=A[i];
            if(sum1==sum/3)
                break;
            ++i;
        }
        if(sum1!=sum/3)
            return false;
        int j = i+1;
        while(j<A.size()-1){
            sum1+=A[j];
            if(sum1==sum/3*2)
                return true;
            ++j;
        }
        return false;
    }
};
```