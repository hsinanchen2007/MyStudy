由题意最短的等差子数组长度为3，找出从当前位置出发的最长子数组长度为n，
那么这个子数组贡献的答案是(n-1)*(n-2)/2.比如找到长度为5的等差子数组，那么
长度为3的等差子数组有3个，长度为4的2个，长度为5的1个，总共(5-1)*(5-2)/2个。
如果找到的等差子数组的长度小于3那么贡献的答案是0则从j-1的位置重新开始找。
- 时间复杂度: O(n)
- 空间复杂度: O(1)

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(),i=0,res=0;
        while(i<n-2){
            int j = i+1,diff = A[j]-A[i];
            while(j<n && A[j] - A[j-1] == diff)j++;
            if(j-i<3)i=j-1;
            else{
                res+=(j-i-1)*(j-i-2)/2;
                i=j;
            }
        }
        return res;
    }
};
```