### 解题思路
二分法去尝试可能的最大甜度值。详情见代码注释

### 代码

```cpp
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int size = sweetness.size();//输入的巧克力的块数。
        if(size <= 0){//输入参数有误，直接返回0
            return 0;
        }

        int maxsweet = 0;
        int minsweet = 0;

        minsweet = *min_element(sweetness.cbegin(),sweetness.cend());//获取最小甜度不需要for循环
        if(size == (K + 1)){//可能切的块数与分享人数相等，则直接返回最小值
            return minsweet;
        }

        for(int i = 0;i < size;++i){//获取可能的最大甜度
            maxsweet += sweetness[i];
        }

        int result = 0;
        int mid = 0;//可能的甜度值
        while(minsweet <= maxsweet){//开始二分查找。，带着“＝”号可以保证查找区间的闭合，如果不带，则有可能会漏掉一些值。
            mid = (minsweet + maxsweet) / 2;
            if(checkMaxSweetofMin(sweetness,K,mid) == true){
                result = mid;//保存该甜度值（mid），也是可能的最终结果
                minsweet = mid + 1;//如果满足要求，则说明可能还有更大的甜度值可以满足要求，所以要向大的方向更新最小值。重新计算mid
            }else{
                maxsweet = mid - 1;//如果不满足要求，则说明当前的甜度值不满足要求，需要向小的方向更新最大值。重新计算mid
            }
        }

        return result;
    }

    bool checkMaxSweetofMin(vector<int> &sweetness, int K, int maxsweet) {
        int total = 0;//巧克力被切成的总块数
        int sweetsum = 0;//每块巧克力的甜度，用于计算可被切的总块数

        for (auto s : sweetness) {
            sweetsum += s;
            if(sweetsum >= maxsweet){
                total++;
                sweetsum = 0;
            }
        }

        if(total >= K + 1){//等于也是满足要求的，也需要保存当前的甜度值,所以需要返回true
            return true;
        }else{
            return false;
        }
    }
};
```