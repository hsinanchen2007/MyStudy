```
int sumNums( int n ){

    int result = 0;
    ( n > 0 ) && ( result = sumNums( n - 1 ) );

    return result + n;

}
```
