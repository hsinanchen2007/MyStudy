### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};
        vector<int> res = {1,1};        
        vector<int> line;
        for(int i=2; i <= rowIndex; ++i){
            line.assign(i+1, 1);            //创建当前行 填充1
            int left = 1,right = i-1;       //因为每行都是回文 所以使用双指针双向填充
            for(; left <= right; ++left,--right){   
                res[left] = res[right] = res[left-1] + res[left]; //根据上一行生成当前行
            }
            res = std::move(line);          //使用move替代拷贝赋值 可以快很多
        }
        return res;
    }
};
```