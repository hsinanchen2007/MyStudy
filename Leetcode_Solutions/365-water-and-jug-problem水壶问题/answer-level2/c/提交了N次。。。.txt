```
bool canMeasureWater(int x, int y, int z){
    if(x+y<z){
        return false;
    }
    if(x==z || y==z){
        return true;
    }
    if(x==0&&y>z){
        return false;
    }
    if(y==0&&x>z){
        return false;
    }

    int min = x<y?x:y;
    int temp;
    for(int i=1;i<=min+1;i++){
        if(x%i == 0 && y%i ==0){
            temp = i;
        }
    }
    if(z%temp==0){
        return true;
    }
    return false;
}
```
