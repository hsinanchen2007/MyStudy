#### 不排序方式


![](https://pic.leetcode-cn.com/c6d6564683c212dcc143d95f57581dd4457cbf7766826a723a2416013e974c76.png)


##### 您不妨先思考一个这样的问题：

有一串连续的数字（无重复），这串数字中最大值为 $m$， 最小值为 $n$ ，问你这串数字中一共有多少个数字？

##### 答案：

$m - n + 1$




同样，如果我们能够知道 5 张扑克牌中的最大值 $maxValue$ 和最小值 $minValue$ ，那我们就知道，要使它为顺子需要 $maxValue - minValue + 1$ 张牌。

- 在查找 $maxValue$ 和 $minValue$ 过程中，跳过大小王 $0$ 。
- 如果 $maxValue - minValue + 1 > 5$，说明题目给的 5 张牌不足以构成顺子，返回 $false$ .
  - 即使里面有大小王，也不够用来填补使它构成顺子。
- 如果 $maxValue - minValue + 1 <= 5$，说明 5 张牌足以构成顺子，返回 $true$。
  - 里面的大小王填补在合适位置即可。

同时，我们再定义一个标志数组判断是否有重复数字，发现重复数字直接返回 $false$ 即可。



#### 代码



```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool m[15];
        memset(m, 0, sizeof(m));
        int minValue = 14, maxValue = 0;
        for (int item : nums) {
            if (item == 0) {
                continue;
            }
            if (m[item]) {
                return false;
            }
            m[item] = true;
            minValue = min(minValue, item);
            maxValue = max(maxValue, item);            
        }
        return maxValue - minValue + 1 <= 5;
    }
};
```



#### 排序方式



排序之后扑克牌就有序了，我们就可以直接判断相邻两张牌之间需要多少个大王或小王来填补。

- 如果需要填补大小王的数量，大于已有大小王的数量，则返回 $false$ .
- 相反，如果需要填补大小王的数量，小于或等于已有大小王的数量，则返回 $true$ .

例如：

```
扑克牌： 0 1 4 5 6
我们发现 1 和 4 之间需要 4 - 1 - 1 张大王或小王来填补
但大王或小王只有 1 张，所以它不可以构成顺子
```



#### 代码



```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = 0;
        for (int i = 0; i < 4; i ++) {
            if (nums[i] == 0) {
                zero++;
                continue;
            } 
            if (nums[i] == nums[i+1]) {
                return false;
            }
            zero -= nums[i+1]-nums[i] - 1;
        }
        return zero >= 0;
    }
};
```





#### 最后

感谢您的观看！

