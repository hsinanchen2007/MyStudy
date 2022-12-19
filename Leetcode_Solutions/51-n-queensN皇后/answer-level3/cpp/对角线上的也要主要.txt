### 解题思路
思路饶了一下，我觉得下一道题的结果可能好一些。
其实最终答案可以用一个数组表示，我也是基于这样的结果来算，最后经过一个ex转化了下。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> finalres;
        if(n==1){
            finalres.push_back({"Q"});
            return finalres;
        }
        vector<int> tempres;
        vector<vector<int>> res;
        solve(res, tempres, n);
        finalres = ex(res,n);
        return finalres;
    }
    void solve(vector<vector<int>> &res,vector<int> &tempres,int n){
        long m = tempres.size();
        if(m==n){
            res.push_back(tempres);
            return;
        }
        for(int i=0;i<n;i++){
            if(m==0){
                tempres.push_back(i);
                solve(res, tempres, n);
                tempres.pop_back();
                continue;
            }
            if(abs(i-tempres[m-1])>1&&find(tempres.begin(),tempres.end(),i)==tempres.end()&&isValid(tempres,m,i)){
                tempres.push_back(i);
                solve(res, tempres, n);
                tempres.pop_back();
            }
        }
        return;
    }
    bool isValid(vector<int> tempres,long m,int i){
        for(int j=0;j<m;j++){
            if(abs(tempres[j]-i)==(m-j)){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> ex(vector<vector<int>> res,int n){
        vector<vector<string>> finalres;
        for(vector<int> i:res){
            vector<string> temp;
            for(int j:i){
                
                string tempstr = ".";
                for(int x=0;x<n-1;x++){
                    tempstr.append(".");
                }
                tempstr[j] = 'Q';
                temp.push_back(tempstr);
            }
            finalres.push_back(temp);
        }
        return finalres;
    }
    // void printres(vector<vector<string>> res){
    //     for(vector<string> i:res){
    //         for(int j=0;j<i.size();j++){
    //             cout<<i[j]<<endl;
    //         }
    //         cout<<endl<<endl;
    //     }
    //     cout<<endl;
    // }
};
```