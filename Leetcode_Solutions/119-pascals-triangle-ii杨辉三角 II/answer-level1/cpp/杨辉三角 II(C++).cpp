### 解题思路
此处撰写解题思路
这个题目主要是有两个考点，注释也基本都写到了。这里简写亮点：
- 直接使用二维数组会浪费空间
- 从左到右计算会覆盖原值
- 
### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 如果用二维的话，很容易解决。但是造成空间浪费。可以如下优化：
        // - 自上往下进行计算 for
        // - 将计算的结果存入数据。注意：不能马上存入，否则就会覆盖计算数。
        vector<int> result(rowIndex+1, 0);
        result[0] = 1;
        if (rowIndex == 0)
            return result;
        result[1] = 1;
        for (int i = 2; i < rowIndex+1; i++) {
            result[i] = 1;
            for (int j = i - 1; j > 0; j--) {
                // 这个地方必须反过来，存放的位置会覆盖的；而后面的位置不会覆盖，是空的
                result[j] = result[j] + result[j-1];
            }
            
        }
        return result;
    }
};
```