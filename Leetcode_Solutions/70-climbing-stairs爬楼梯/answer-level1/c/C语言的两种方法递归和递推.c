### 解题思路

其实这个问题可以直接简化成斐波那契数列，也就是F(n) = F(n-1) + F(n-2)

我们可以用递归实现，但是用于过程中存在许多重复计算，因此最朴实的递归可能是超时了。所以需要定义一个备忘录，将一些计算过的值记录下来。

另外一种方法就是利用递推公式，每次保留两个状态，不断的往后计算

### 代码

递推的代码如下

```c
int climbStairs(int n){
    // f(n) = f(n-1) + f(n-2)
    if ( n < 0 ) return 0;
    if (n <=2) return n;

    int fn1 = 1, fn2 = 2;
    int fn3;
    for (int i = 2 ;i < n; i++){
        fn3 = fn2 + fn1;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;

}
```

递归代码如下

```c
int _climb(int n, int *arr)
{
    if (arr[n] != 0 ) return arr[n];
    arr[n] = _climb(n-1, arr) + _climb(n-2, arr);
    return arr[n];

}

int climbStairs(int n){

    //终止情况
    if ( n <  0 ) return 0;
    if ( n <= 2) return n;
    int *arr = (int*)calloc(n+1, sizeof(int));
    arr[1] = 1;
    arr[2] = 2;
    return _climb(n , arr);

}
```

没想到的是第二种居然速度那么快

![image.png](https://pic.leetcode-cn.com/c59747914993bd7b4d03c4309d285d1fe61385de978cb3622ce6231fdb1c9d36-image.png)

由于环境提供了hash结构，于是我试着写了下代码， 没想到超出内存了

```c
struct dict {
    int id;
    int value;
    UT_hash_handle hh;
};

int helper( int n, struct dict *d ){
    if ( n == 0 || n == 1) return 1;

    struct dict *tmp;
    HASH_FIND_INT(d, &n, tmp);
    if ( tmp != NULL ) {
        return tmp->value;
    } else {
        tmp = (struct dict*)malloc(sizeof(struct dict));
        tmp->id = n;
        tmp->value = helper(n-1,d) + helper(n - 2, d);
        HASH_ADD_INT(d, id, tmp);
        return tmp->value;
    }

}

int climbStairs(int n){

    struct dict *d = NULL;
    int res;
    res = helper(n, d);

    return res;
}

```

![image.png](https://pic.leetcode-cn.com/804af84535d79c9077b2df3842133bb0b1dbe0bbb99c94235b8f525305b04af4-image.png)
