执行用时 :28 ms, 在所有 cpp 提交中击败了100.00%的用户
当数组中的数大于自身的索引+1或者小于自身的所以-1时就会出现2个以上的全局倒置，就不可能和局部倒置相等了
```
class GlobalLocalInversions {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i)
            if (A[i] < i - 1 || A[i] > i + 1) return false;
        return true;
    }
};
```
