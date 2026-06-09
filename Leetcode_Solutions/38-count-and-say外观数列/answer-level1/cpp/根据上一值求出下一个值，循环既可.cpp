### 解题思路
循环步骤都是根据上一步结果来计算的，操作都是一样的，循环n-1次就可以计算出结果，优化可以通过备忘录

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; i++){
            string t = "";
            int times = 1;
            for(int j = 1; j < result.length(); j++){
                if(result[j - 1] != result[j]){
                    t += (char)(times + 48);
                    t += result[j - 1];
                    times = 1;
                }else{
                    times++;
                }
            }
            t += (char)(times + 48);
            t += result[result.size() - 1];
            result = t;
        }
        return result;
    }
};
```