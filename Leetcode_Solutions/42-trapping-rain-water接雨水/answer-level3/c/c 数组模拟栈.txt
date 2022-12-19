```
/**
*
*整体思路：利用模拟栈
*1.申请长度为heightSize长度的动态内存stack,模拟栈空间，stack存储height下标，便于计算距离
*2.维护指针top指向stack栈顶，维护i指向height当前元素，否则进入步骤7
*3.遍历height，满足i < heightSize
*4.如果栈不为空且当前元素*( height + i )大于栈顶指向的元素*( height + *( stack + top ) )
*5.读取栈顶top-1指向的元素，同时进行弹栈操作top--,如果此时栈为空，top==0，停止计算，否则计算当前元素到
*  栈顶所指向的元素的距离，更新sum
*6.将当前元素的下标进行压栈操作，top++，下一趟遍历，进入步骤3
*7.释放栈stack,返回sum
*/

//returning the minimun between a and b
#define min( a , b ) ( a > b ? b : a )

int trap( int * height , int heightSize ){

    //the parameter of sum used to save the total value of rainfall
    //the parameter of top is the pointer of stack points to the top
    //the parameter of i is the pointer of height points to current element
    int sum = 0 , top = 0 , i = 0;
    //alloclating memory to save the index of elements in height 
    int * stack = ( int * )malloc( sizeof( int ) * heightSize );

    //visiting array
    while( i < heightSize ){

        //if stack is not NULL and the value of current element in height bigger than the
        //value of element in the top of stack
        while( top > 0 && *( height + i ) > *( height + *( stack + top - 1 ) ) ){

            //Pop the stack
            int curr = *( stack + top - 1 );
            top--;
            if( top == 0 ){

                break;

            }

            int dis = i - *( stack + top - 1 ) - 1;
            int bound = min( *( height + i ) , *( height + *( stack + top - 1 ) ) )
                                                                     - *( height + curr );
            sum += dis * bound;

        }

        //Push to stack
        *( stack + top++ ) = i++;

    }

    //freeing stack
    free( stack );
    return sum;

}
```
