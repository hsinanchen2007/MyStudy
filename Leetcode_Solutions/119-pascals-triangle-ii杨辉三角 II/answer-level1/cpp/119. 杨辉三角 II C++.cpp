### 解题思路
1.杨辉三角形上下行的关系可以更改为在上一行的末尾增加1个元素，元素为1。
2.这一行的元素的倒数第二个元素值应该为该元素值加上这一行倒数第三个元素值，以此类推。

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i = 0;i <= rowIndex;i++){
            result.push_back(1);
            for(int j = i - 1;j > 0;j--){
                result[j] += result[j - 1];
            }
        }
    return result;
    }
};
```