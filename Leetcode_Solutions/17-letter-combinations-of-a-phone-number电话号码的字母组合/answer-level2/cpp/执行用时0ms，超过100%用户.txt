### 解题思路
总共三层循环，下面解释每一层循环的含义：
- 第一层循环是遍历每个数字，内部进行插入操作
- 第二层循环是遍历已经保存在result结果中的数组
- 第三层循环是遍历i位置数字对应的各个字母，并进行拼接
这里有几个小技巧：
- 如何初始化循环，在result中添加一个""即可
- 拼接操作需不需要把之前的抹除，不需要，erase操作花费的时间相当长，直接利用在后拼接即可。
存在的疑惑：
如何降低内存消耗。。。

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) return result;
        vector<string> v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        result.push_back("");
        for(int i = 0; i < digits.size(); i++){
            int size = result.size();
            for(int j = 0; j < size; j++){
                string word = result[j];            
                result[j] += v[digits[i] - '2'][0];
                for(int k = 1; k < v[digits[i] - '2'].size(); k++){
                    result.push_back(word + v[digits[i] - '2'][k]);
                }
            }
        }
        return result;
    }
};
```