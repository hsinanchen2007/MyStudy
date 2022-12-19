求出所有元素个数的最大公约数
```
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> tmp;
        for(auto i: deck){
            tmp[i]++;
        }
        int cap = tmp.size();
        if(cap==1) return tmp.begin()->second>=2;
        
        vector<int> c;
        for(auto z: tmp){
            c.push_back(z.second);
        }
        int r = c[0];
        for(int i=1;i<cap;i++){
           
          r= gcd(r,c[i]);
          if(r==1) return false;
        }
        
        
        return true;
    }
    int gcd(int a, int b){
        int m= a>=b?a:b;
        int n= a>=b?b:a;
       return n==0?m:gcd(n,m%n);
    }
};
```
