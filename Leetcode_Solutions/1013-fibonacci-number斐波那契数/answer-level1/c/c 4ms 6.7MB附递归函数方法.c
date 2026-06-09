```
/**
*迭代算法：时间复杂度O(n) 空间复杂度O(1)
*整体思路：
*1.计算前两次的和
*2.将b更新到a, 和更新到a
*3.重复1-2，知道N>0不成立
*
*/

int fib( int N ){

    int a = 0 , b = 1 , sum = 0;

    while( N > 0 ){

        sum = a + b;
        b = a;
        a = sum;
        N--;

    }

    return sum;

}

/*************************利用递归函数*****************************
*时间复杂度为：O(2^n)
*空间复杂度为：O(1)
*
int Fibonacci( int num ){

    if( num > 1 ){

        return Fibonacci( num - 1 ) + Fibonacci( num - 2 );

    } else if( num == 1 ){

        return 1;

    }

    return 0;

}

*************************利用递归函数*****************************/
```
