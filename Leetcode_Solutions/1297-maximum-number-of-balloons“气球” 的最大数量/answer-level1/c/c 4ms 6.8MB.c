```
/**
*
*整体思路：
*1.申请动态内存，并初始化为0
*2.遍历字符串，对应balon分别对缓冲区加1
*3.对l和o的缓冲区值除以2，
*4.遍历缓冲区，取最小元素返回
*
*/

int maxNumberOfBalloons( char * text ){
    
    //alloclating memorise to svae the number of characters
    int * buffer = ( int * )malloc( sizeof( int ) * 5 );
    //used to save the number of the min in the buffer
    int min = 0;

    //itializing the memorise
    for( int i = 0 ; i < 5 ; i++ ){

        *( buffer + i ) = 0;

    }

    //counting the number of the character by visiting the string
    for( int i = 0 ; *( text + i ) != '\0' ; i++ ){

        switch( *( text + i ) ){

            case 'b':{

                *( buffer + 0 ) += 1;
                break;

            }

            case 'a':{

                *( buffer + 1 ) += 1;
                break;

            }

            case 'l':{

                *( buffer + 2 ) += 1;
                break;

            }

            case 'o':{

                *( buffer + 3 ) += 1;
                break;

            }

            case 'n':{

                *( buffer + 4 ) += 1;
                break;

            }

            default:
                break;

        }

    }

    //o and c character both be used twice
    *( buffer + 2 ) /= 2;
    *( buffer + 3 ) /= 2;
    min = *( buffer + 0 );

    //min is the number of word balloon
    for( int i = 1 ; i < 5 ; i++ ){

        if( *( buffer + i ) < min ){

            min = *( buffer + i );

        }

    }

    free( buffer );

    return min;

}
```
