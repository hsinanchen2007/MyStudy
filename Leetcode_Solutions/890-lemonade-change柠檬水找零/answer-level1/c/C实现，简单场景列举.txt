```
bool lemonadeChange(int* bills, int billsSize){
    int i = 0;
    int cnt5  = 0;  // 记录5元钞的数量
    int cnt10 = 0;  // 记录10元钞的数量
    
    if (bills == NULL || billsSize < 0 || billsSize > 10000) {
        return false;
    }
    
    for (i = 0; i < billsSize; i++) {
        if (bills[i] == 5)
        {
            cnt5++;
        } 
        
        if (bills[i] == 10) {
            cnt5--;
            cnt10++;
            if (cnt5 < 0) {
                return false;    
            }
        }
        
        if (bills[i] == 20) {
            if (!((cnt5 > 0 && cnt10 > 0) || (cnt5 > 2 && cnt10 == 0))) {
                return false;
            }
            
            if (cnt10 > 0) {
                cnt10--;
                cnt5--;
            }else {
                cnt5 -= 3;
            }
            
            if (cnt5 < 0) {
                return false;    
            }
        }
    }
    
    return true;    
}
```
