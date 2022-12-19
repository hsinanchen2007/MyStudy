```
int mySqrt(int x){
    int start = 0;
    long temp =x/2;
    int flag = 0;
    while(1){
        if(temp*temp>x){
            temp = (start+temp)/2;
            if (temp<=flag) return flag;
        }
        else if(temp*temp<x){
            flag = temp;
            temp++;
        }
        else return temp;
    }
}
```
