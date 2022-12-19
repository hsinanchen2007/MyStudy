```
/**
*
*总体思路：
*1.遍历数组，判断水平和垂直方向是否均为0
*
*/

bool judgeCircle(char * moves){

    int horizon = 0 , verical = 0;

    for( int i = 0 ; *( moves + i ) != '\0' ; i++ ){

        switch( *( moves + i ) ){

            case 'U':{

                verical += 1;
                break;

            }

            case 'D':{

                verical -= 1;
                break;

            }

            case 'L':{

                horizon -= 1;
                break;

            }

            case 'R':{

                horizon += 1;
                break;

            }

            default:
                break;

        }

    }

    if( horizon == 0 && verical == 0 ){

        return true;

    }

    return false;

}
```
