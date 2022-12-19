### 代码

```cpp
class Solution {
public:
    // 你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素,只能删一次,
    // 删除后子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。
    // 注意，删除一个元素后，子数组 不能为空。
    int maximumSum(vector<int>& arr) {
        int len = arr.size();
        vector<int> f(len), g(len);
        f[0] = arr[0];
        g[0] = -10005;
        for(int i=1; i<len; i++){
            f[i] = max(f[i-1]+arr[i], arr[i]);  //其实就是f(i-1)是否<0
            g[i] = max(g[i-1]+arr[i], f[i-1]);
        }
        int res = INT_MIN; 
        for(int i=0; i<len; i++){
            res = max(res, max(f[i], g[i]));
        }
        return res;
    }
};





```