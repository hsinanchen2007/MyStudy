### 解题思路
本来想利用高斯求解，但是题目要求还是用递归比较合适。纪念第一个双100，继续加油。
![捕获.JPG](https://pic.leetcode-cn.com/6aa382b677700a6023862fafb018b6b6b3f25c66eb52258daed13c1283e90341-%E6%8D%95%E8%8E%B7.JPG)

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        if(n==1)return 1;
        else return n+sumNums(n-1);
    }
};
```