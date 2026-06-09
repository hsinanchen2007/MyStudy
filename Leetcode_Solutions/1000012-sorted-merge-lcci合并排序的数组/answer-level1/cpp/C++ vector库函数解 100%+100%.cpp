![image.png](https://pic.leetcode-cn.com/c359b5bbded36c7eb82edb3694a9c9e79b956b07cd5c787c2756f008a735ca0b-image.png)
使用C++vector库函数, 执行用时0ms、内存10.8M。
### 解题思路
不使用额外空间。
使用vector的内置函数, resize()、lower_bound()、insert()
使用resize()截断后缀的0, lower_bound()找到数字num应该插入的位置, 使用insert()进行插入。
    # lower_bound()返回不大于num的第一个迭代器。

### 代码
```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        A.resize(m);
        for(int num : B){
            auto iter = lower_bound(A.begin(), A.end(), num);
            A.insert(iter, num);
        }
    }
};
```