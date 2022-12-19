
```
public int reverse(int x) {    
    int result=0;    
    while(x!=0){       
        result=result*10+x%10;//%/带符号        
        x=x/10;        
        if(result>Integer.MAX_VALUE/10&x>0) return 0;//判断是否溢出        
        if(result<Integer.MIN_VALUE/10&x<0) return 0;//判断是否溢出    
    }    
    return result;
}
```
