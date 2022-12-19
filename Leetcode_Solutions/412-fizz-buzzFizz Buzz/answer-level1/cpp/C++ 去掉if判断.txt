简单的四个循环：
```
for(int i=1;i<=n;i++){
    res[i-1]=to_string(i);
}
for(int i=3;i<=n;i+=3){
    res[i-1]="Fizz"
}
for(int i=5;i<=n;i+=5){
    res[i-1]="Buzz"
}
for(int i=15;i<=n;i+=15){
    res[i-1]="FizzBuzz"
}
```
