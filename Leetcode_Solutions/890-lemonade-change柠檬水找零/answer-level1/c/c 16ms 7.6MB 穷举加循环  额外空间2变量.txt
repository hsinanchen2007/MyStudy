```
/**
*
*整体思路：时间复杂度O(n), 
*1.维护两个变量，5元钱数量five和10元钱数量ten
*2.如果首元素大于5，直接return false
*3.从第二个元素开始遍历，
*   a.如果当前元素为5，5变量加一
*   b.如果当前元素为10，如果5的个数变量少于1，直接return false，否则five--,ten++
*   c.如果当前元素为20，优先考虑ten>=1 && five>=1是否满足，满足的话five--,ten--
*     如果不满足，判断five>=3是否成立，不成立直接return false
*4.以上均满足时，直接return true
*/

bool lemonadeChange(int* bills, int billsSize){

    //the parameter of five is used to save the number of 5 yuan
    //the parameter of ten is used to save the number of tem yuan
    int five = 0 , ten = 0;

    //if the first element in bills is bigger than 5, return false
    if( *( bills + 0 ) > 5 ){

        return false;

    }

    //else the number of five add 1
    five++;

    //visiting array
    for( int i = 1 ; i < billsSize ; i++ ){

        switch( *( bills + i ) / 5 ){

            //if current element is 5, add 1 to five
            case 1:{

                five++;
                break;

            }

            //if current element is 10, the number of five must bigger than 0, 
            case 2:{

                if( five == 0 ){

                    return false;

                }

                five--;
                ten++;
                break;

            }

            //if current element is 20, the number of five and ten must bigger than 0, or
            //the number of five must bigger than 2
            case 4:{
                
                //you must think this situation firstly, otherwise, there may be some mistake
                if( five >= 1 && ten >= 1 ){

                    ten--;
                    five--;
                    break;


                } else if( five >= 3 ){

                    five -= 3;
                    break;


                }

                return false;

            }

        }

    }

    return true;

}
```
