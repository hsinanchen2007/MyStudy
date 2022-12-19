看到这道题，首先想到的就是暴力。。。。
所以就试了一下。。。时间空间双百！
```
class ProductOfNumbers {
public:
    vector<int>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int res=1;
        int n=ans.size();
        for(int i=n-k;i<n;i++){
            res*=ans[i];
        }
        return res;
    }
};
```
