### 解题思路
DFS可以看作是n层的数，每一层有10个节点[0,9]，dfs的每一层相当于为每一位选择恰当的位置，因为使用stoi进行转换，所以不用考虑leading zero的问题。最后的结果因为第一位保存的是0，所以要将第一位erase掉

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        helper(0,n,"");
        result.erase(result.begin());
        return result;
    }

    void helper(int depth, int n, string current){
        if(depth == n){
            result.push_back(stoi(current));
            return;
        }
        for(int i = 0; i < 10; i++){
            helper(depth+1,n,current+to_string(i));
        }
    }

    vector<int> result;
};
```