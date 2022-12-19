/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/28
 *
 * 解题思路1： 暴力 配合sqrt
 *
 * 解题思路2：厄拉多塞筛法 详见代码 所有的非质数最终都可以分解为质数因子
 */

```
    public boolean isPrime(int n){

        for(int i = 2 ; i*i <= n ; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    /**
     * 通过不了 1500000 超时
     * @param n
     * @return
     */
    public int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }

    public int countPrimes2(int n){

        //定义一个信号数组默认为false 将所有以当前质数为因子的数都标记为非质数true
        boolean[] sign = new boolean[n+1];
        int count = 0;

        for(int i = 2; i< n;i++){

            if(sign[i] == false){ //如果当前为false 即为质数,因为  以比它小的数为因子的数都是true
                count ++;
                for(int j = i + i ; j < n; j+=i){ //标记为非质数
                    sign[j] = true;
                }
            }

        }
        return count;

    }
```