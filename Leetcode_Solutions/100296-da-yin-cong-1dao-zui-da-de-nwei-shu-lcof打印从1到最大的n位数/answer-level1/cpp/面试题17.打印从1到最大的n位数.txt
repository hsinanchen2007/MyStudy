### 解题思路
核心思路：确定输入n后所需要建立vector的大小，然后依次赋值即可
执行用时 :8 ms, 在所有 C++ 提交中击败了82.26%的用户
内存消耗 :10.6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        int count=1;
        int size=pow(10,n)-1;
        vector<int>nums(size,0);
        for(int i=0;i<size;i++){
            nums[i]=count++;
        }
        return nums;
    }
};
```