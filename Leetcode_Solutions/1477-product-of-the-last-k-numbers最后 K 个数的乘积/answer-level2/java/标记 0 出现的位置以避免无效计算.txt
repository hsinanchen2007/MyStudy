### 解题思路
当 k >= mark 时，k 个数中必然包含0，因此直接 return 0.

### 代码

```java
class ProductOfNumbers {
    int res = 1;
    int mark = 1;
    ArrayList a = new ArrayList();
    public ProductOfNumbers() {
    }
    
    public void add(int num) {
        if(num != 0){
            a.add(num);
            mark ++;
        }
        else{
            mark = 1;
            a.clear();
        }
        
    }
    
    public int getProduct(int k) {
        if(k >= mark)
            return 0;
        int count = 0;
        res = 1;
        for (int i = a.size() - 1; count < k; i--){
            int cur = (int)a.get(i);
            if (cur == 0)
                return 0;
            res *= cur;
            count ++;
        }
        return res;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
```