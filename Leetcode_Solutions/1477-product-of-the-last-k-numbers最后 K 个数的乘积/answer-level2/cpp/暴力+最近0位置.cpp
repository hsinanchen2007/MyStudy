

### 代码

```cpp
#include <vector> 
class ProductOfNumbers {
    vector<int> arr={};
    int zero=-1;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)
            zero=arr.size();
        arr.emplace_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        if(arr.size()-zero<=k)
            return 0;
        for(int i=0;i<k;i++)
        {
            prod*=arr[arr.size()-1-i];   
        }
        
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```