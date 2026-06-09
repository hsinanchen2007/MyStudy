```

/**
*
*整体思路：
*1.遍历二维字符数组时将对应的ip地址与访问次数存放在结构体中，更新链表
*   更新结构体：ip已存在，更新访问次数；新ip地址，添加到链表中，维护最后一个节点
*2.遍历完毕后申请动态内存，将链表数据存放进内存中，
*
*细节说明：1.一定要注意进行任何有关字符串函数操作时，一定要加上'\0'，
*2.一定要注意字符‘.’应该在更新完链表后再进行存放操作
*
*/

//the function of this struct is used to save the ip and the number of visiting
typedef struct NetWork {

    int val;
    char address[ 101 ] ;
    //used to link the next node
    struct NetWork * next;

} NetWork ;

/**
*Function: visiting the link, if the ip is existing, updating the value of the number and
* return the haeder node
*@param: struct NetWork * head : the header of the link ready to be visited
*@param: char * s : the string used to be compared
*@param: int num : the value of the current ip's visiting number
*return: head : the header of the link atfer updating,
*        NULL : there is not such a ip data
*/
struct NetWork * check( struct NetWork * head , char * s , int num ){

    struct NetWork * tmp = head;
    while( tmp != NULL ){

        //if there is such a ip, updating the value of the number, then return the header
        if( strcmp( tmp -> address , s ) == 0 ){

            tmp -> val = tmp -> val + num;
            return head;

        }

        tmp = tmp -> next;

    }
    

    return NULL;

}

/**
*Function: appending the value of the number to the string, and reversing the string
*@param: struct NetWork * Node : the node ready to be updating
*@param: char * s : the alloclating memorise ready to be save
*return: char * : the result of the operation
*/
char * svaeStruct( struct NetWork * Node , char * s ){
    
    //copying the node's ip to the buffer
	strcpy( s , Node -> address );
	int index = 0 , len = strlen( s );
	
	*( s + len++ ) = ' ';

    //appending the value of the visiting number to the string
	while( Node -> val != 0 ){

		*( s + len++ ) = ( Node -> val % 10 ) + 48;
		Node -> val /= 10;

	}

    //appending the ending flag of the string
    *( s + len ) = '\0';
	len--;

    //reserving the string
	while( index < len ){

		char ch = *( s + index );
		*( s + index++ ) = *( s + len );
		*( s + len-- ) = ch;

	}
	return s;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** subdomainVisits( char ** cpdomains , int cpdomainsSize , int * returnSize ){

    //the header of the link
    struct NetWork * head = NULL;
    //marking the end of the link to appending new nodes
    struct NetWork * end = head;
    struct NetWork * tmp;
    char ** buffer = ( char ** )malloc( sizeof( char * ) * cpdomainsSize * 3 );
    int len = 0;
    char * s ;

    //visiting the array
    for( int i = 0 ; i < cpdomainsSize ; i++ ){

        int num = 0 , j = 0 ;
        s = ( char * )malloc( sizeof( char ) * 110 );
        
        //calculating the value of the number
        while( *( *( cpdomains + i ) + j ) != ' ' ){

            num = num * 10 + ( *( *( cpdomains + i ) + j ) - 48 );
            j++;

        }
        
        j = strlen( *( cpdomains + i ) ) - 1;

        //analysising the ip string
        for( ; *( *( cpdomains + i ) + j ) != ' ' ; j-- ){

        	if( *( *( cpdomains + i ) + j ) == '.' ) {

                //appending the ending flag of the string
                *( s + len ) = '\0';
        		if( ( tmp = check( head , s , num ) ) == NULL ){
                    //if current node is header, you should allcolate new node
        			if( end == NULL ){
                        
        				end = ( struct NetWork * )malloc( sizeof( NetWork ) * 1 );

        				end -> next = NULL;
        				end -> val = num;
        				strcpy( end -> address , s );
        				head = end;
                        
                        
        			} else {

                        //if current node is not header, you should create new node
        				tmp = ( struct NetWork * )malloc( sizeof( NetWork ) * 1 );

        				tmp -> next = NULL;
        				tmp -> val = num;
        				strcpy( tmp -> address , s );
        				end -> next = tmp;
        				end = tmp;
                        

        			}

        		}

                //in order to avoid appending the character of '.' to the end of ip,
                //you should to append after the operation
                *( s + len++ ) = *( *( cpdomains + i ) + j );

        	} else{

                *( s + len++ ) = *( *( cpdomains + i ) + j );

            }

        }

        //appending the ending flag of the string
        *( s + len ) = '\0';
        //making sure the last segment of the ip is analysised
        if( ( tmp = check( head , s , num ) ) == NULL ){

        	tmp = ( struct NetWork * )malloc( sizeof( NetWork ) * 1 );

        	tmp -> next = NULL;
        	tmp -> val = num;
        	strcpy( tmp -> address , s );
        	end -> next = tmp;
        	end = tmp;

        }
        len = 0;

    }

    //copying the link's value to the buffer
    while( head != NULL ){

    	*( buffer + len ) = ( char * )malloc( sizeof( char ) * 110 );
        s = ( char * )malloc( sizeof( char ) * 110 );
        strcpy( *( buffer + len ) , svaeStruct( head , s ) );
        len++;
        

        head = head -> next;

    }

    *returnSize = len;

    return buffer;

}
```
