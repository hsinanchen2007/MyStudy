```
/**
*
*整体思路：
*1.构造得分缓冲区，遍历得分字符数组时，除C情况，其余全部将得分情况存进数组中
*2.依据CD+等，维护得分数组当前元素的指针，类似栈操作
*
*/
int calPoints(char ** ops, int opsSize){
    
    int score = 0 , index = -1;
    int * form = ( int * )malloc( sizeof( int ) * opsSize );

    for( int i = 0 ; i < opsSize ; i++ ){

        switch( *( *( ops + i ) + 0 ) ){

            case 'C':{

                //deleting the element from the array
                score -= ( *( form + index ) );
                *( form + index ) = 0;
                index--;
                break;

            }

            case '+':{

                //adding two former element
                *( form + ++index ) = 0;

                if( index - 1 >= 0 ){

                    *( form + index ) += *( form + index - 1 );

                }

                if( index - 2 >= 0 ){

                    *( form + index ) += *( form + index - 2 );

                }
                score += ( *( form + index ) );
                break;

            }

            //multiplting former element
            case 'D':{

                *( form + ++index ) = 0;

                if( index - 1 >= 0 ){

                    *( form + index ) += ( 2 * ( *( form + index - 1 ) ) );

                }

                score += ( *( form + index ) );
                break;

            }

            default:{

                //calculating current score
                int len = strlen( *( ops + i ) );
                int value = 0 , prio = 1;;

                for( int j = 0 ; j < len ; j++ ){

                    if( *( *( ops + i ) + j ) == '-' ){

                        prio = -1;

                    } else {

                        value = value * 10 + ( *( *( ops + i ) + j ) - 48 );

                    }

                }

                *( form + ++index ) = prio * value;
                score += prio * value;

            }

        }

    }

    return score;

}
```
