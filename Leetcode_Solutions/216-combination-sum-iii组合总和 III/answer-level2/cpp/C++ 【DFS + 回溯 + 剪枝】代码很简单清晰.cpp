# 代码很简单很清晰，希望对大家有帮助！^_^

```
int k;
vector<vector<int>> ans;
void DFS(int pos, int curr, vector<int>res) {//位置、当前目标值、当前所用数字
    if (res.size() == k) {                   //若次数用完
        if (curr == 0) ans.push_back(res);   //已达到目标
        return;
    }
    for (int i = pos; i <= 9 && i<=curr; i++) {//i=pos实现剪枝
        res.push_back(i);                      //存储
        DFS(i + 1, curr - i, res);             //DFS
        res.pop_back();                        //回溯
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    this->k = k;
    DFS(1, n, vector<int>{});
    return ans;
}
```
