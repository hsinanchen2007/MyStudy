### 解题

保存后缀和数组。

执行用时 :208 ms

### 代码

```cpp
class ProductOfNumbers {
private:
    int zero;
    deque<long> product;
public:
    ProductOfNumbers() {
        zero = 0;
        product.push_front(1L);
    }
    
    void add(int num) {
        if(num != 0) {
            if(product.size() > 40000) {
                if(product.back() == 0)
                    zero--;
                product.pop_back();
            }
            long x = product.front();
            product.push_front((long)num * x);
        } else {
            product.clear();
            product.push_front(1L);
            zero++;
        }
    }
    
    int getProduct(int k) {
        if(product.size() <= k) {
            if(zero > 0)
                return 0;
            else{
                return product[0];
            }
        }
        return product[0] / product[k];
    }
};