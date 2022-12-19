### 解题思路
采用类似快排算法的思想，可以快速求解

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //采用类似快排算法的思想
       int low = 0, high = A.size() - 1;
       int pivot = A[low]; //选择枢纽元素
        while(low < high)
        {
            while(low < high && A[high] % 2 == 1)
                high--;
            A[low] = A[high];       //把后面的偶数移动到前面
            while(low < high && A[low] % 2 == 0)
                low++;
            A[high] = A[low];   //把前面的奇数移动到后面
        }
        A[low] = pivot;
        return A;    
    }

    // int Partition(vector<int>& A, int low, int high)
    // {
       
    //     }
};
```