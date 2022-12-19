提示：
    可以类比一下字符串比较函数strcmp的原理，具体问题具体分析，我们在strcmp基础上，修改了结束条件，即循环比较，最大比较次数为最长的字符串长度的两倍

1.先分析题目特点，如果看不出特点，建议多随便修改一下运行区的输入，还有就是大胆假设。
![~$7TWI25IOVA3)\[OTAOJI\]X.png](https://pic.leetcode-cn.com/272b08f2296bc0afef49c8e3e672aa0cca389d55f97692bd7a37280dde4aa0f2-~$7TWI25IOVA3\)%5BOTAOJI%5DX.png)



2.为了提高效率，所以我们提前将整形数据分离，并记录位数，比较每次比较都要作分离操作。
3.利用字符串存储空间消耗较小
4.在解决比较两个字符串长度问题时，利用一个函数提高后续比较的代码的复用率，避免冗余，但这时带来一个问题，就是原位置被打乱了，不能单纯返回1和-1，因为调用比较函数str_cmp的原因，打乱cmp中tmp_a -> str和tmp_b -> str的位置，所以利用换位标志位position表示是否打乱位置了
5.在str_cmp函数中，默认s1的长度是最长的，注意s1也是需要循环的，因此s1和s2都需要各自对len1和len2进行取余，已达到自动回0目的

```
/**
*
*整体思路：
*1.首先申请长度为numsSize的动态缓冲区buffer，用于存放结构体Node，定义len，用于存放nums所有位数
*2.遍历数组nums同时，调用按位分离整形数据的函数splitInteger,将结构体存入动态缓冲区buffer中
*3.调用快速排序函数，传入动态缓冲区buffer，长度为numsSize,元素数据类型为Node *,比较函数为cmp
*4.申请动态长度为len+2的缓冲区str，，遍历buffer的同时，每个字符串存入str中
*5.添加字符串结束标志'\0'到str后
*6.返回str
*/

/**
*Function: saving each bit of elements in nums and the length of str 
*/
typedef struct Node{

    char * str;
    int len;

} Node;

/**
*Function: splitting integer to string bit by bit, saving the length of string
*@param: int val : the value ready to be splitted 
*@param: int * length : the total length of every string 
*return : struct Node * : the result includes the length of current string
*/
struct Node * splitInteger( int val , int * length ){

    //the parameter of pro used to save the prority of val
    //the parameter of len used to calculating the length of current string
    int pro = 1 , len = 0;

    //alloclating memory to save current result of val
    struct Node * node = ( struct Node * )malloc( sizeof( Node ) * 1 );

    //calculating the number of bit in val
    while( val / pro != 0 ){

        len++;
        pro *= 10;

    }

    //intializing pro
    pro /= 10;

    //intializing the memory in struct Node according the value of len
    node -> str = ( char * )malloc( sizeof( char ) * ( len + 2 ) );
    node -> len = len;
    *length += len;

    //if the value of val is zero
    if( val == 0 ){

        node -> str[ 0 ] = '0';
        node -> str[ 1 ] = '\0';
        node -> len = 1;
        * length += 1; 
        return node;

    }

    //saving each bit to memory
    for( int i = 0 ; i < len ; i++ ){

        node -> str[ i ] = val / pro % 10 + 48;
        pro /= 10; 

    }

    //appending the ending flag of string to currnt string
    node -> str[ len ] = '\0';  

    return node;

}

/**
*Funciton: comparing s1 to s2 double times
*@param: char * s1 : the longest string between s1 and s2
*@param: char * s2 : the shortest string between s1 and s2
*@param: int len1 : the length of string 1
*@param: int len2 : the length of string 2
*@param: int position : remember the original position of s1 and s2
*        1 : they do not change position, -1 : they have changed posotion
*return: int : the result of the process
*/
int str_cmp( char * s1 , char * s2 , int len1 , int len2 , int position ){

    //you should compare twice, making sure this situation 830 , 8308 and so on
    for( int i = 0 , j = 0 ; i < 2 * len1 ; i++ , j++ ){

        //making sure all the pointer is legal
        if( *( s1 + i % len1 ) > *( s2 + j % len2 ) ){

            //returning the result according to the flag of position
            return position * 1;

        } else if ( *( s1 + i % len1 ) < *( s2 + j % len2 ) ){

            return -1 * position;

        }

    }

    return 0;

}

/**
*Function: comparing the a and b according to the rules of programmer
*/
int cmp( const void * a , const void * b ){

    struct Node * tmp_a = *( struct Node ** )a;
    struct Node * tmp_b = *( struct Node ** )b;

    //if the length of tmp_a bigger than tmp_b
    if( tmp_a -> len > tmp_b -> len ){

        return str_cmp( tmp_a -> str , tmp_b -> str , tmp_a -> len , tmp_b -> len , 1 );

    } else {

        return str_cmp( tmp_b -> str , tmp_a -> str , tmp_b -> len , tmp_a -> len , -1 );

    }

    //if tmp_a -> str equals to tmp_b -> str 
    return 0;

}

char * minNumber( int * nums , int numsSize ){

    //alloclating memory to save the result of spliting process and the length of each integer
    struct Node ** buffer = ( struct Node ** )malloc( sizeof( Node * ) * numsSize );
    //the parameter of len used to save the total length of each integer
    int len = 0;

    //splitting the integer bit by bit
    for( int i = 0 ; i < numsSize ; i++ ){

        *( buffer + i ) = splitInteger( *( nums + i ) , &len );

    }

    //quick sort
    qsort( buffer , numsSize , sizeof( Node * ) , cmp );

    //alloclating memory to save the final result
    char * str = ( char * )malloc( sizeof( char ) * ( len + 2 ) );

    //clearing len
    len = 0;
    
    //copying all the string in buffer to str 
    for( int i = 0 ; i < numsSize ; i++ ){

        struct Node * tmp = *( buffer + i );
        char * s = tmp -> str;

        for( int j = 0 ; j < tmp -> len ; j++ , len++ ){
            *( str + len ) = *( s + j );

        }

    }

    //freeing buffer
    free( buffer );
    //appending the ending flag of string to str
    *( str +len ) = '\0';

    return str;

}
```
