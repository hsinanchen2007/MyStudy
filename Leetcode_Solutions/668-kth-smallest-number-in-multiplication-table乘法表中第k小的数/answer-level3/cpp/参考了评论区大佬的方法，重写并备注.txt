```
class Solution {
public:
    //Binary Search for value
    //跟普通二分不一样 普通二分把下标来当作边界，而这里的二分则是把值来当作边界
    int fun(int m, int n, int num) {//函数功能：获得在m*n的乘法表中，找出有多少个值 <= num。返回满足条件的值的数量
        int count = 0;
        for(int i = 1; i<=m; ++i) {//行从第一行开始
            count += min(num/i, n);//此表达式的含义：num这个值在当前第i行，有多少个值不比它大（<=num的个数）
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        if(k == 1) return 1;
        if(k == m*n) return m*n;
        int left = 1, right = m*n, mid;//值来当作边界，乘法表（m*n）最小是1，最大是m*n
        while(left < right) {
            mid = (left+right) >> 1;
            int temp = fun(m, n, mid);//得到在乘法表中 值 <= mid 的数量
            if(temp < k) {
                left = mid+1;//如果temp < k, 说明当前mid这个值在目标值的左边（比目标值小），所以可以缩小边界
            }
            else right = mid;//temp >= k， 在temp>k时，为什么不取 right = mid-1，而是right = mid。因为我们的目标值可能存在重复，比如 123334，如果我选择要找第3小的数，而mid当前恰好=3，那么temp得到的结果会是5（<=mid）。如果我们选择right = mid-1=2。那么将会运行错误导致结果错误。在temp = k时，为什么不能立马返回结果呢，而是继续运行缩小边界？因为我们当前的mid可能是一个不在乘法表中的值，毕竟mid=(left+right) >> 1; 所以立即返回可能返回错误答案。所以一定收缩范围 直到left=right。最终返回的一定是正确值（若答案t的temp = k， 而某一非表值x的temp也=k， 那么t一定比x小，最终x也会被right缩小导致出局）。
        }
        return left;
    }
};

```

