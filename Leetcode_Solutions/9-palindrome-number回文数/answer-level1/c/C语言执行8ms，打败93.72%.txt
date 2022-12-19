```
bool isPalindrome(int x){
    int temp;
    long y=0;
    int start=x;
    if(x<0){
        return false;
    }else{
        while(x!=0){
            temp=x%10;
            x=x/10;
            y=temp+y*10;
        }
        if(start == y){
            return true;
        }
        return false;
    }
}
```
