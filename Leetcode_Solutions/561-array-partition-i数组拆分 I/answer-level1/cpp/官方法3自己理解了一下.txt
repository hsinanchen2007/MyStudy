### 解题思路
对官方第三种方法的粗浅理解

### 代码

```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int arr[20001]={0};
        int lim = 10000;
        for (int num: nums)
            arr[num + lim]++;
        int d = 0, sum = 0;
        for (int i = -10000; i <= 10000; i++) {
            sum += (arr[i + lim] + 1 - d) / 2 * i;
    //当前值i减去上一个值i-1多出来的不成对子的d个数，再综合考虑出当前值能多少次作为最小值被加入结果。
            d = (2 + arr[i + lim] - d) % 2;     //d值为0或1
    //d为当前值i凑成对子后多出来的数量(实际到下一次i+1迭代才用上)，加2是防止arr[i + lim] - d=0-1=-1特例（此时需要的实际为1）,除此之外加2不影响其他正确结果
        }
        return sum;
    }
};
```