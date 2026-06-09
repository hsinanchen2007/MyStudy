### 解题思路
用Map(一个二维数组也行)存储商品和价格的映射，一个计数器来判断是否达到打折的人数，累加，乘以折扣即可。

### 代码

```java
class Cashier {

    private Map<Integer,Integer> productsPrices = new HashMap<>();
    private int n;// 多少个顾客打折
    private double discount;// 折扣
    private int currentCustomer = 0;// 当前客户数

    public Cashier(int n, int discount, int[] products, int[] prices) {
        this.n = n;
        this.discount = discount;
        for (int i = 0; i < products.length; i++) {
            productsPrices.put(products[i],prices[i]);
        }
    }

    public double getBill(int[] product, int[] amount) {
        currentCustomer++;
        double currDiscount = 1.0D;
        if (currentCustomer == n){
            currDiscount -= this.discount/100;
            currentCustomer = 0;
        }
        int sum = 0;
        for (int i = 0; i < product.length; i++) {
            sum += productsPrices.get(product[i]) * amount[i];
        }
        return sum * currDiscount;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
```