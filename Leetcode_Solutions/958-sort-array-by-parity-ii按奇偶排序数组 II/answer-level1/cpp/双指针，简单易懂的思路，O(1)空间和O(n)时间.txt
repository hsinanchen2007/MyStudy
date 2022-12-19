### 解题思路
设置偶数指针i和奇数指针j，双指针步长为2遍历数组，若偶数指针元素为奇数并且奇数指针为偶数时，交换，否则继续遍历。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len_A = A.size();
        int t = 0;
        int i=0,j=1;
        while(i<len_A&&j<len_A){
            if(A[i]%2==1&&A[j]%2==0){
                t = A[i];
                A[i]=A[j];
                A[j]=t;
                i = i+2;
                j = j+2;
            }else if(A[i]%2==0) i=i+2;
            else if(A[j]%2==1) j = j+2;
            if(i>=len_A||j>=len_A) break;
        }
        return A;
    }
};
```