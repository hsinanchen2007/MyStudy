### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> output;
    vector<int> result;
    result.reserve(k);
    combine(1, k, n,output, result);
    return output;

    }

    void combine(int currentIndex,int objSize,int range,vector<vector<int>> &output,vector<int> &currentResult)
{
    if (currentResult.size() >= objSize) {
        output.push_back(currentResult);
        return;
    }
    for (int index = currentIndex; index <= range; index++) {
        currentResult.push_back(index);
        int remainToBeAdded = objSize - currentResult.size();
        if (remainToBeAdded && remainToBeAdded <= range - index) {
            //进行下一步尝试
            combine(index+1, objSize,range, output, currentResult);
        }
        else if(remainToBeAdded == 0)
        {
            //直接将结果输出
            output.push_back(currentResult);
        }
        currentResult.pop_back();
    }
    
}

};
```