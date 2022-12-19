### 解题思路
1.判断是否大于等于三个元素或者数组是否为空
2.遍历数组，设置一个转向标志位，
3.依据转向标志位确定是在山坡左侧还是右侧，
4.如果山坡无转向，则不满足山脉条件：
    1）连续下降不满足山脉
    2）连续上升不满足山脉

### 代码

```c
bool validMountainArray(int* A, int ASize){
    
    //make sure the array larger than 3 elements or 
    //not NULL 
    if( ASize < 3 || A == NULL ){

        return 0;

    }

    int direction = 0;

    for( int i = 0 ; i < ASize - 1 ; i++ ){

        switch( direction ){

            //rising direction
            case 0:{

                //i != 0 makes sure not always the downing directon
                if(  i != 0 && A[ i ] > A[ i + 1 ] ){

                    //changing direction
                    direction = 1;
                //i == 0 && A[ i ] > A[ i + 1 ] makes sure not always 
                //the downing directon
                } else if ( A[ i ] == A[ i + 1 ] 
                    || ( i == 0 && A[ i ] > A[ i + 1 ] ) ){

                    return 0;

                }

                break;

            }
            //downing direction
            case 1:{
                //not meeting the codition
                if( A[ i ] <= A[ i + 1 ] ){

                    return 0;

                }

                break;

            }

            default:
                break;

        }

    }
    //making sure not always the rising direction
    if( direction == 0 ){
            
        return 0;
        
    }

    return 1;

}
```