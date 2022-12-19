### 解题思路
![image.png](https://pic.leetcode-cn.com/cc6d9784830f4f8755f5a34b8dc9348b09d30f013e7666004629555a93840b2d-image.png)

动态规划：实际是求排列数
dp[i] 表示第i个字符时的路径数
dp[i] = dp[i-1] +dp[i-2]
条件：
1)对i取1个字符时，则一定在0~25以内，因此dp[i] = dp[i-1],表示从i-1到i的路径;
2)当i取2个字符时，只有在0~25以内时，才有dp[i] = dp[i-2]，表示从i-2到i的路径;
dp[i-1]和dp[i-2]是不同的路径，即表示不同的翻译方法，因此需要加和

以12258为例
1：1
12:{1,2} {12}
122：{1,2,2} {12,3},{1,23}
......



### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {

        string strnum = to_string(num);
        unordered_set<string> strset;
        for (int i = 0; i < 26;i++){
            strset.insert(to_string(i));
        }

        vector<int> dp = vector<int>(strnum.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < dp.size();i++){
            string str = "";
            str += strnum[i - 2];
            str += strnum[i - 1];
            dp[i] += dp[i - 1];

            if(strset.count(str)){
               dp[i] += dp[i - 2];
            }

        }

        return dp.back();
    }
};
```