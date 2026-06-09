### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(),A.end(),0);
        if(sum%3!=0) return false;
        int div=sum/3;
        int count=1;
        sum=0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum==div){
                count++;
                sum=0;
            } 
        }
        if(count>3) return true;
        return false;
    }
};
```