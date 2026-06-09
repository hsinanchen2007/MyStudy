### 解题思路
C++

### 代码

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        function<int(int)> convertToBSTIndex = [&] (int label) { // 转换为正常二叉搜索树的元素
            int tmp = 0;
            int level = 0;
            while(tmp < label) { // 获取层数
                tmp += pow(2, level);
                level += 1;
            }
            level -= 1;
            if(level % 2 == 1) return label;
            else {
                int res = (pow(2, level) * 2 - 1) - (label - pow(2, level)); // 转换
                return res;
            }
        };
        label = convertToBSTIndex(label);
        while(label > 0) {
            res.push_back(label);
            label /= 2;
        }
        for(int i = 0; i < res.size(); i ++) {
            res[i] = convertToBSTIndex(res[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```