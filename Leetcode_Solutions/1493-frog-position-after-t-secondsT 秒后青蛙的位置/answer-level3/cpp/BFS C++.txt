- 当t>0时候，碰到了target点，要判断target是否是叶子节点。
    - 如果是：则返回当前点的概率
    - 如果不是，则返回0.00「因为它肯定会接着跳走」
- 当t==0时，碰到了target点，则返回当前点的概率
- 当t<0时，青蛙会接着跳
```c++
class Solution {
public:
    map<int,double> proba; // 概率
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(edges.size()==0 && target == 1) return 1.00;
        bool leaf = true; // 判断target是否为叶子节点
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] > edges[i][1]) swap(edges[i][0],edges[i][1]);
            if(edges[i][0]==target) leaf = false;
        }
        queue<int> q; // BFS
        q.push(1);
        proba[1] = 1.00;
        while(q.empty()==false && t){
            int width = q.size();
            t--;
            while(width--){
                int k = q.front();
                q.pop();
                int base = 0; // 计算当前BFS的概率
                for(int i=0;i<edges.size();i++){
                    if(edges[i][0]==k){
                        base++;
                        q.push(edges[i][1]);
                    }
                }
                for(int i=0;i<edges.size();i++){
                    if(edges[i][0]==k){
                        proba[edges[i][1]] = proba[k] * (double)1/base;
                        if(t==0 && edges[i][1]==target) return proba[target];
                        else if(t>0 && edges[i][1]==target) return (leaf==true)?(proba[target]):0.00;
                    }
                }
            }
        }
        return 0.00;
    }
};
```
