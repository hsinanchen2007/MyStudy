### 解题思路

就是先先干掉2的倍数，然后干掉3的倍数，（4是2的倍数，过滤），干掉5的倍数，（6是2和3的倍数），干掉7的倍数，就这样子一路干到sqrt(n)就行了


![图片来自于维基百科](https://pic.leetcode-cn.com/77583e8c9a820e3880f754a00863d616642d8cf915230382c2aaa11168c25849-file_1581643684036)

参考: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes


### 代码

```c
int countPrimes(int n){

    int *nums = malloc(sizeof(int) * n);
    for ( int i = 0; i < n; i++){
        nums[i] = 1;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (nums[i]){
            int k = 2;
            while (k * i < n){
                nums[k * i] = 0;
                k++;
            }
        }
    }

    int res = 0;
    for (int i =  2; i < n; i++){
        res+= nums[i];
    }
    return res;
    
    



}
```