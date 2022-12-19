### 解题思路
参考了下解题几位兄弟的思路，大概思路就是：确定一个capacity，检查该capacity是否满足条件（在D天内送达），然后更新capacity，更新方法采用二分。
![image.png](https://pic.leetcode-cn.com/4a88d44721abb75331c33c03d5da7d0f328fc37724101dbfb0c6049a1dd2750e-image.png)

### 代码

```cpp
class Solution {
public:
    bool checkOK(vector<int> weights, int D, int cap) {
        int sum = 0;
        int day = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > cap) {
                day++;
                sum = weights[i];
            } else if (sum == cap) {
                day++;
                sum = 0;
            } else {
                sum += weights[i];
            }
/*剪枝*/
            if (day > D) {
                return false;
            }
        }
/*这个判断不能漏掉，因为最后一堆包裹还没上船*/
        if (sum != 0) { 
            day++;
        }
        if (day > D) {
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int low = 0;
        int high = 0;
/*下界：最大包裹的重量；上界：所有包裹的重量和*/
        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
            if (low < weights[i]) {
                low = weights[i];
            }
        }
/*注意没有“=”号，最终退出条件是low==high*/
        while (low < high) {
            int mid = (low + high) >> 1; /*注意这里是向下取整*/
            if (checkOK(weights, D, mid)) {
                high = mid;
            } else {
/*由于上面mid是向下取整，这里下界必须要+1，否则死循环。比如low = 14; high = 15时，mid=(14+15)/2=14 -> low = 14 -> 死循环了*/
                low = mid + 1; 
            }
        }
        
        return low;
    }
};

```