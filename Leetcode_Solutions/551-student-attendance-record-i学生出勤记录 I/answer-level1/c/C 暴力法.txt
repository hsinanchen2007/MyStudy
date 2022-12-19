```
/**
*
*整体思路：遍历字符串
*
*/

bool checkRecord( char * s ){

    int A = 0 , L = 0 ;

    for( int i = 0 ; *( s + i ) != '\0' ; i++ ){

        switch( *( s + i ) ){

            case 'A':{

                L = 0;
                A++;

                if( A == 2 ){

                    return false;

                }

                break;

            }

            case 'L':{

                L++;

                if( L == 3 ){

                    return false;

                }

                break;

            }

            default:{

                L = 0;
                break;

            }

        }

    }

    return true;

}
```
