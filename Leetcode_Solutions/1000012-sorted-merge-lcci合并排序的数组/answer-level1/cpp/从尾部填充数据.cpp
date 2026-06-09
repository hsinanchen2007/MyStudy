### 解题思路
我们知道向量A的大小正好是A和B的总和，故可以从后面排布数据，这样就不会影响到前面的数据了。

以样题为例：
```
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3
```
我们尾部开始判定，首先设定下标a_index = 2 和 b_index =2 以及总长度 all_index = 5。
然后进行判定：
```
all_index = 5： 判定A[2] 和 B[2]的大小，输入6进去, 此时a_index = 2， b_index = 1；
all_index = 4： 判定A[2] 和 B[1]的大小，输入5进去，此时a_index = 2， b_index = 0；
all_index = 3： 判定A[2] 和 B[0]的大小，输入3进去，此时a_index = 1， b_index = 0；
all_index = 2： 判定A[1] 和 B[0]的大小，输入2进去，此时a_index = 1， b_index = -1；
all_index = 1： 此时B向量已经为空，输入A剩余的数值进去就可以了。
```
因此，就可以得到合并后的A = [1,2,2,3,5,6]；

这里**有个坑**需要注意下：
输入数组A可能为0，这个时候，需要把B数组的数据输入进去就可以了。


### 代码

```cpp
class Solution {
public:
    //从尾部排列
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int a_index = m - 1;
        int b_index = n - 1;
        int all_index = m + n - 1;
        while(b_index >= 0 && all_index >= 0){
            if(a_index < 0 || A[a_index] <= B[b_index]){
                A[all_index] = B[b_index];
                all_index--;
                b_index--;

            }
            else{
                A[all_index] = A[a_index];
                a_index--;
                all_index--;
            }
        }
    }
};
```