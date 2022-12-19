```
class Solution {
public:
    int helper(int n){//计算阶乘
        int ret = 1;
        for(int i=1;i<=n;i++){
            ret *= i;
        }
        return ret;
    }
    
    string getPermutation(int n, int k) {//借鉴康托展开
        string ret = "";
        vector<int> v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        int k2 = k-1;
        int n2 = n-1;
        while(k2!=0){
            int n2_mul = helper(n2);
            int index = k2/n2_mul;
            ret += to_string(v[index]);
            v.erase(v.begin()+index);
            k2 = k2%n2_mul;
            n2--;
        }
        for(int i=0;i<v.size();i++){
            ret += to_string(v[i]);
        }
        
        return ret;
    }
};
```
