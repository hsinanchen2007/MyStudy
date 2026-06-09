### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
    二分法，如何想到：看到数组，求边界问题，那就想能不能用二分法去做，目前看是可以的
    具体：
    1. 首先运载能力，假设为K，则不会超过 weights的总和，因为D是大于1的,
       但肯定是大于等于weights的最大值的，因为不可能把一个货物分两半。
    2. 那我们就可以二分法的 left = max(weights)， right = sum(weights) ，K就是这其中的任何一个值。
    3. 然后求得是左边界，所以最后需要返回left。

    我们需要单独定义一个函数，来判断需要的天数是否能满足 D天。
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = findMax(weights);
        int right = calSum(weights); 

        while (left <= right) {
            int mid = left + (right - left)/2;
            if(canArrInD(weights, D, mid) != true) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }

    bool canArrInD(vector<int>& weights, int D, int k) { // k代表运载重量
        // 要看 weights中，利用K需要多少天，是否大于D
        int count = 0; // 用以索引遍历 weights
        int kk = k; // 保留k的值，用kk代替k做减法
        int days = 0; // k时，需要days天
        while(count < weights.size()) {
            if(kk-weights[count] >=0) { //这里要加上等号。这样让kk减小到0
                kk = kk -weights[count];
                count++;
            } else { // 说明剩余的空间不够装今天的货物了，然后 count不加加，还得从这个位置重新算
                days++;
                kk = k;
            } 
        }
        if ((days+1) > D) { // 这里要注意是 days+1 ，
        //因为上边while中肯定是if中count++了才不满足，不会是走了else结束的while循环。所以if跳出后要加上这一天。
            return false;
        }
        return true;
    }

    int  findMax(vector<int>& weights) {
        int max = 0;
        for(auto i : weights) {
            if(i > max) {
                max = i;
            }
        }
        cout << "max = " << max << endl;
        return max;
    }
    int  calSum(vector<int>& weights) {
        int sum = 0;
        for(auto i : weights) {
            sum = sum + i;
        }
        cout << "sum = " << sum << endl;
        return sum;
    }
};
```