### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;

        if(n<0||k<0||k>n){
            return res;
        }
        process(1,temp,n,k);


        return res;
    }

private:
    void process(int start,vector<int> temp,int n,int k){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<=n;i++){
            temp.push_back(i);
            process(i+1,temp,n,k);
            temp.pop_back();
        }

    }
};
```