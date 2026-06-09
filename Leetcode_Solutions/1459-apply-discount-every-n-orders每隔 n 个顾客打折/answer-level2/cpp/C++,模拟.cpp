```
class Cashier {
public:
    map<int,int>pric;
    int n,discount;
    int index=0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n=n;
        this->discount=discount;
        for(int i=0;i<products.size();i++){
            pric[products[i]]=prices[i];
        }

    }
    
    double getBill(vector<int> product, vector<int> amount) {
        index++;
        double sum=0;
        for(int i=0;i<product.size();i++){
            sum+=(1.0*pric[product[i]]*amount[i]);
        }
        if(index==n){
            sum=sum-1.0*(discount*sum)/100;
            index=0;
        }
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
```
