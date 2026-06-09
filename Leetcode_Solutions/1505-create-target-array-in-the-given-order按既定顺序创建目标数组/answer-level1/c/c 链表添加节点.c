```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
*
*整体思路：
*1.申请动态内存buffer，用于存放最终最终结果，同时建立单向链表的头结点，val值为*( nums + 0 )，
*    next指向NULL
*2.遍历index和nums，设置一个计数器count，用于记录当前节点偏移量，如果count==*( index + i )，
*   则添加到链表中，如果*( index + i ) == 0，则按添加到链表头进行操作，
*3.将链表的数据复制到缓冲区buffer中
*4.释放链表，返回buffer
*/
/**
*
*Function: saving the value of current array
*/
typedef struct Node{

    int val;
    struct Node * next;

} Node;

int * createTargetArray( int * nums, int numsSize , int * index , int indexSize , 
                                                                        int * returnSize){
    
    //intializing returnSize
    *returnSize = numsSize > indexSize ? indexSize : numsSize;

    //alloclating memory to save the final result
    int * buffer = ( int * )malloc( sizeof( int ) * ( *returnSize ) );
    //creating the header of the link
    struct Node * header = ( struct Node * )malloc( sizeof( Node ) * 1 );

    //intializing the value of the header and the pointer of next
    header -> val = *( nums + 0 );
    header -> next = NULL;

    //visiting array
    for( int i = 1 ; i < *returnSize ; i++ ){

        //creating current node in link
        struct Node * node = ( struct Node * )malloc( sizeof( Node ) * 1 );
        //intializing the value of current node 
        node -> val = *( nums + i );
        node -> next = NULL;

        //if current adding to the head of link
        if( *( index + i ) == 0 ){

            node -> next = header;
            header = node;

        } else {

            //if current node inserts to the link
            //the parameter of count used to calculating the offset of currenr link
            //the parameter of flag used to marks current appending the end of link
            int count = 1 , flag = 0;
            //the parameter of curr points current node in link
            struct Node * curr = header -> next;
            //the parameter of form point former node in link
            struct Node * form = header;

            while( curr != NULL ){
                
                //if current node is not the node ready to be inserted, continuing
                if( count != *( index + i ) ){

                    count++;
                    form = curr;
                    curr = curr -> next;
                    continue;

                }

                node -> next = curr;
                form -> next = node;
                flag = 1;
                break;

            }

            //appending new node to the end of link
            if( flag == 0 ){

                form -> next = node;

            }

        }

    }

    //copying the value of each node in link to buffer
    struct Node * tmp = header;
    *returnSize = 0;

    while( tmp != NULL ){

        *( buffer + *returnSize ) = tmp -> val;
        *returnSize += 1;
        tmp = tmp -> next;

    }

    //freeing( header )
    free( header );
    return buffer;

}
```
