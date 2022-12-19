### 解题思路


### 代码

```cpp
class ProductOfNumbers {
public:
    vector<int> arr;
    ProductOfNumbers() {
        ;
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int result = 1;
        int i = arr.size()-k;
        for (; i<arr.size(); i++)
        {
            result *= arr[i];
        }
        return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```