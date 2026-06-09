### 解题思路


### 代码

```java

class Cashier {

    Map<Integer,Integer> map;
	int n,discount,count;

   public Cashier(int n, int discount, int[] products, int[] prices) {
		this.n=n;
		this.discount=discount;
        this.count=0;
		this.map =new HashMap<>();
		for(int i=0;i<products.length;i++) {
			map.put(products[i], prices[i]);
		}
    }
    	
	 public double getBill(int[] product, int[] amount) {
    	int account=0;
    	for(int i=0;i<product.length;i++) {
    		//int price = map.get(product[i]);
    		account+=map.get(product[i])*amount[i];
    	}
    	count++;
    	
		return (count%n==0)?(account-account*(discount/100.0)):account;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
```