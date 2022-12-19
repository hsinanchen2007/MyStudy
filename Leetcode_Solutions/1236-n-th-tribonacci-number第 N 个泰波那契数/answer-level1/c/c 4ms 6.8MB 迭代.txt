```
/**
*
*整体思路:迭代
*1.如果n为0，返回0
*2.如果n为1，返回1
*3.如果n为2，返回1
*4.初始化first=1,second=1,third=0
*5.遍历 3-n之间的数，暂存当前first,second,third到tmp
6.更新second的值到third，更新first的值到second，更新first为tmp
*/

int tribonacci( int n ){

    //if n is zero
    if( n == 0 ){

        return 0;

    //if n is 1
    } else if( n == 1 ){

        return 1;

    //if n is 2
    } else if( n == 2 ){

        return 1;

    }

    //the parameter of first is n
    //the parameter of second is n-1
    //the parameter of first is n-2
    int first = 1 , second = 1 , third = 0;

    //visiting 3 to n, updating first,second,third
    for( int i = 3 ; i <= n ; i++ ){

        int tmp = first + second + third;

        third = second;
        second = first;
        first = tmp;

    }

    return first;

}
```
