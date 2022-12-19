### [5341. 最后 K 个数的乘积](https://leetcode-cn.com/problems/product-of-the-last-k-numbers/)

### 题解
   + 存储数并从后向前遍历累乘即可
   + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)
   
### 代码
```cpp
class ProductOfNumbers {
public:
    vector<int> vs;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vs.push_back(num);
    }
    
    int getProduct(int k) {
        int res = 1;
        for(int i = 1; i <= k; i++)
            res = res * vs[vs.size()-i];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
```