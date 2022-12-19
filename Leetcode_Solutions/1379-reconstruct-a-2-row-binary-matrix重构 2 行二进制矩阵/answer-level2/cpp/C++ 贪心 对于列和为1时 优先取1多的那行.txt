```
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& c) {   
        int n = c.size(),sum=0;
        for(int i = 0; i < c.size(); i++) sum += c[i];
        if(upper+lower!=sum) return {};//必无解
        vector<vector<int>> ans(2,vector<int>(n));
        for(int i = 0; i < n; i++){
            if(c[i]==2){//此时上下只能都取1 取不到时则无解
                if(upper>=1&&lower>=1) ans[0][i] = ans[1][i] = 1, upper--,lower--;
                else return {};
            }
            else if(c[i]==1){//贪心 此时谁1多就取谁的 如果先取了少的 可能导致后面某处c[j]=2时少的无法提供1
                if(upper>=lower&&upper>=1) ans[0][i] = 1,upper--;//让多的先上
                else if(lower>=1) ans[1][i] = 1, lower--;
                else return {};
            }
        }
        return ans;
    }
```
