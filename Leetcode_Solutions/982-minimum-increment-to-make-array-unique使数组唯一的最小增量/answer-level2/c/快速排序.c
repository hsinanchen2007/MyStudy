### 解题思路
快速排序然后对每一个数进行统计就可以了，
可以用这个数和上一个数的关系直接算出需要增加的次数，这样可以节省很多时间。

![QQ截图20200322104920.png](https://pic.leetcode-cn.com/8c09e7eeb682a915ee58a8ac5809151ffd3c4edec76448d92da98510a357eb14-QQ%E6%88%AA%E5%9B%BE20200322104920.png)


### 代码

```c

int cmp( const void *a, const void *b ) {
    return *( int *)a - *( int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    int ans = 0;
    qsort( A, ASize, sizeof(A[0]), cmp );
    for( int i = 1; i < ASize; i++ ) {
        if( A[i] <= A[i-1] ) {
            //计算增加的次数
            ans += A[i-1]-A[i]+1;
            //重新赋值让这个数比前一个数大于1
            A[i] = A[i-1]+1;
        }
    }
    return ans;
}

```