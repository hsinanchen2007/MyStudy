### 解题思路
我们考虑一种平凡状态，我们可以用两个量来去描述它，分别是：
1.一共有多少'('已经存在
2.已存在的'('有多少没被满足

当然这样两个量并不能唯一的确定一个状态，但是每个状态都能用唯一的这两个量进行描述
处于任意一种状态下，我们根据上述两个量来进行判定：
1.如果所有已存在的'('都被满足，那么这种状态接下来只能添加'('操作
2.如果存在未被满足的'('，可能分别添加'('或')'，这时只需要判断'('的数量没超过要求即可。
因此我们只要记录了上述两种状态便能够循环遍历result数组中的变量。

### 代码

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
         if(n == 0) return result;
        vector<int> unchecked;//多少'('未被满足
        vector<int> put;//存在多少'('
        //对结果进行初始化
        result.push_back("(");
        unchecked.push_back(1);
        put.push_back(1);
        for(int i = 1; i < 2*n; i++){
            int size = result.size();
            for(int j = 0; j < size; j++){
                string temp = result[j];
                //存在未满足的'('，能进行如下两种操作
                if(unchecked[j] > 0){
                    //添加的'('不能超过n
                    if(put[j] != n){
                        result.push_back(temp + "(");
                        put.push_back(put[j] + 1);
                        unchecked.push_back(unchecked[j] + 1);
                    }
                    result[j] += ")";
                    unchecked[j]--;
                }
                //不存在为满足的'('，只能添加'('
                else{
                    result[j] += "(";
                    unchecked[j]++;
                    put[j]++;
                }
            }
        }
        return result;
    }
};
```