```
public class Solution {
    public IList<int> SelfDividingNumbers(int left, int right) {
        IList<int> result = new List<int>();
        
        while(left<=right){
            
            if(Judge(left++)){
                result.Add(left-1);
            }
        }
        return result;
    }
    
    
    public bool Judge(int num){
        
        
        int p = 0;
        int real = num;
        while(num!=0){
            p = num%10;
            if(p==0) return false;
            num/=10;
            if(real%p!=0){
                return false;
            }
        }
        
        return true;
    }
}
```
