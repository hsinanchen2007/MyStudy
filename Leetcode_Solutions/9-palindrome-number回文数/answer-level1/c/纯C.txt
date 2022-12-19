纯C
```
#define isNotPalindrome 0

bool isPalindrome(int x){
    if(0 > x)
    {
        return isNotPalindrome;
    }
    
    int uTemp = x;
    long uReverse = 0;

    while(0 != uTemp)
    {
        uReverse = uReverse * 10 + uTemp % 10;
        uTemp = uTemp / 10;
    }

    return !(uReverse ^ x);
}
```
