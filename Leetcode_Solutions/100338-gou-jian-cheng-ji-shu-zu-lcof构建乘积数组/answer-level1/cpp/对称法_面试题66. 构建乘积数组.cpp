### 解题思路
    /*
     * 对称法
     *
     * 结果B[i] = A[0]*A[1]...A[i-1]*A[i+1]...A[n-1]可以看做
     * C[i] = A[0]*A[1]...A[i-1]和 D[i] = A[i+1]*A[i+2]...A[n-2]*A[n-1]两部分乘积。
     * 所以C[i]可以自上而下顺序计算：
     *      C[i] = C[i-1]*A[i-1]
     * D[i]可以自下而上顺序计算：
     *      D[i] = D[i+1]*A[i+1]
     *
     * 大致的意思是：先计算该数左边所有数的乘积，存到该数；
     *               再计算该数右边所有数的乘积，存到临时数，
     *               最后将临时数乘该数，存到该数。
     * */
### 代码

```cpp
std::vector<int> constructArr(std::vector<int> &a) {
    if (a.empty()) {
        return {};
    }

    std::vector<int> ans(a.size(), 1);

    // 计算该数左边所有数的乘积，存储到该数
    for (int i = 1; i < a.size(); i++) {
        ans[i] = ans[i - 1] * a[i - 1];
    }

    // 再计算该数右边所有数的乘积，存到temp
    int temp = 1;
    for (int i = a.size() - 2; i >= 0; i--) {
        temp *= a[i + 1];
        // 最后将temp乘该数
        ans[i] *= temp;
    }

    return ans;
}
```