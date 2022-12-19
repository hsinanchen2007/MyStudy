### 解题思路
理解题目要求的时间复杂度，肯定是类似二分法的方式 n = n/k

### 代码

```c
/*请查阅下时间复杂度 - logn，达到这个复杂度就类似二分式查找，但题目要求没说明是对数的底，当然是5了。那么你就知道肯定有n = n/5 这步了。就会做了嘛   参考  https://github.com/wayou/wayou.github.io/issues/10
*/
int trailingZeroes(int n){

    int cnt = 0;
    while(n>=5) {
        cnt +=n/5;
        n = n/5;
    }
    return cnt;

}
```