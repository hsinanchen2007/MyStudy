题目给定的是正整数序列，按照题解2给的思路，如果修改题目为序列中同时也存在负数，便无法对元素进行取相反数标记了。
这时可以运用交换操作 swap， 来原地解决标记的问题。

因为题设最小值为1，采取的思路是利用交换操作将扫描当前位的数字 num 放置在下标为 num - 1 的位置。
如果假设数组中有负数且最小值为 min， 则改为把数组 num 放置在下标为 num - min 的位置即可。
这样一来，修正后每个存在的数对应的位置都会被规则对应的数填满，而缺省的数对应的位置由重复出现的数字填充，最后按照放置规则对数组进行检查即可。

```
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){

    void swap( int *p1, int *p2 );

    //  按规则修正数组：
    //  通过交换，把元素置换到对应下标位置
    //  交换过后不移动检查位置，继续检查交换到当前位置的元素是否需要操作
    //  如果当前元素重复出现（对应位置已有相同数字）或者该元素已经在正确位置，则扫描下一位
    int i = 0;
    while( i < numsSize ){
        if( nums[ i ] == i + 1 || nums[ i ] == nums[ nums[ i ] - 1 ] ){
            i++;
            continue;
        }
        swap( &nums[ i ], &nums[ nums[ i ] - 1 ] );
    }

    //  为了节省空间，这里C语言多了一步获取答案数组的长度（多少个数字没有出现），其实可以直接申请一个numsSize长度的数组
    *returnSize = 0;
    for( i = 0; i < numsSize; i++ )
        if( nums[ i ] != i + 1 )
            ( *returnSize )++;
    
    //  搭建答案数组：
    //  扫描修正后的数组，当发现当前位置的元素不符合对应规则时，说明该位置对应的正确元素不存在，将其加入答案数组
    int *ret = ( int* ) malloc( sizeof( int ) * *returnSize );
    int j = 0;
    for( i = 0; i < numsSize; i++ )
        if( nums[ i ] != i + 1 )
            ret[ j++ ] = i + 1;

    return ret;
}

void swap( int *p1, int *p2 ){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
```

恳请各位优化、指正！
