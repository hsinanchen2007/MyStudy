### 解题思路
arrayaylist

### 代码

```java
class ProductOfNumbers {
 
   List List;
    public ProductOfNumbers() {
         
         List = new ArrayList();
    }
    
    public void add(int num) {
        List.add(num);
    }
    
    public int getProduct(int k) {
        int result=0;
        int result2=1;
      
        int i =0;
        for(int j=List.size()-1;j>List.size()-1-k;j--)
        {
            result = (int)List.get(j);
           
            result2=result2*result;
        }
      
        return result2;
        
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */
```