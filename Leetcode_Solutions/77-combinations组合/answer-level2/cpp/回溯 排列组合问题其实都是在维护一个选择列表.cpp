### 解题思路
排列组合问题其实都是在维护一个选择列表
排列问题的选择列表只需要排除i 本身；
组合问题的选择列表要把1到n 也就是n+1之前的元素都排除掉，不参加下一次组合

### 代码

```cpp
class Solution {
private:
    void dfs(int n, int k, int depth, vector<int>& record, vector<int>& path, vector<vector<int>>& result ) {
         if (depth == k) { //深度为组合的个数
             result.push_back(path);
             return;
         }

         for (int i = 1; i <= n; i++) {
            if (record[i] == 0) {
                for (int j = 1; j <= i; j++) {
                    record[j] = 1; //将1到n从选择列表中移除
                }
                path.push_back(i);
                dfs(n, k, depth +1, record, path, result);
                path.pop_back();
                for (int j = 1; j <= i; j++) {
                    record[j] = 0;  //将1到n恢复到选择列表里
                }
            }
        }
   }
   
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> record(n+1);//record是从0开始的
        vector<int> path;

        if (n < 1 || k < 1 || k > n ) {
            return result;
        }
        dfs(n, k, 0, record, path, result);
        return result;
    }
};

```