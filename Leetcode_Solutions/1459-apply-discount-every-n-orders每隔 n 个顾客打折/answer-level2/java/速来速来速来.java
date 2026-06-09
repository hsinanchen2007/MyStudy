### 解题思路
offend

### 代码

```java
class Cashier {

 	private int n;
	private int discount;
	int[] products;
	int[] prices;
	int num=1;

    public Cashier(int n, int discount, int[] products, int[] prices) {
    	this.n=n;
    	this.discount=discount;
    	this.prices=prices;
    	this.products=products;
    	this.num=1;

    }
    
    public double getBill(int[] product, int[] amount) {
    	double money=0;
    	int len=product.length;
        int len2=products.length;
    	for(int i=0;i<len;i++){
    		int temp=product[i];
    		int p=0;
    		for(int j=0;j<len2;j++){
    			if(products[j]==temp){
    				p=prices[j];
    				break;
    			}
    		}
    		money=money+p*amount[i];
    	}
    	if(num==n){
    		money=(double)(money-(discount*money)/100);
    		num=1;
    	}else{
    		num++;
    	}
		return money;

    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */
```