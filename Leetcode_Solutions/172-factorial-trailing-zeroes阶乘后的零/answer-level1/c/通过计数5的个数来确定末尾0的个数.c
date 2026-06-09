``` c
/*
* example
*  n    n
* 2  < 5  so we can count 5
* nums = 0
* 5 * 25 <= 125
* 5 * (1..25) <=125; so num += 25
* for i in (1..25) trailingZeroes(i)  equal trailingZeroes(25!)
*/
int trailingZeroes(int n){
    int tmp;
    if(n < 5) return 0;
    tmp = n / 5;
    return tmp  + trailingZeroes(tmp);
}
```