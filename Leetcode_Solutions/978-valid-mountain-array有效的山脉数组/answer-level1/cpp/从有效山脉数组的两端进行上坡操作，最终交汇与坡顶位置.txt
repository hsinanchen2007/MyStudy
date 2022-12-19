### 解题思路


### 代码

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
        {
            //数组长度小于3
            return false;
        }
        int head = 0;//头端索引
        int tail = A.size()-1;//尾端索引
        //尾端上坡
        while(head<A.size()-1 && A[head]<A[head+1])
        {  
            head++; 
        }
        //头端上坡
        while(tail>head && A[tail]<A[tail-1])
        { 
            tail--;
        }
        //判断两端索引是否相交于同一点，判断坡顶是否在数组头部或是尾部
        if(head != tail || head == 0 || tail == A.size()-1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
```