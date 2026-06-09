```
/**
*
*整体思路：
*1.如果小于1，直接返回false，负数的因数一定会有负数存在的
*2.如果num大于1，进入3，否则进入7
*3.能被2整除，num /= 2，不满足的话，直接返回false
*4.能被3整除，num /= 3，不满足的话，直接返回false
*5.能被6整除，num /= 5，不满足的话，直接返回false
*6.进入2进行循环
*7.返回false
*/

bool isUgly( int num ){

    //if the value of num is less than 1
    if( num < 1 ){

        return false;

    }

    //if the value of num is bigger than 1
    while( num > 1 ){

        //if 2 is one of the factors of num
        if( num % 2 == 0 ){

            num /= 2;
            continue;

        //if 3 is one of the factors of num
        } else if( num % 3 == 0 ){

            num /= 3;
            continue;

        //if 5 is one of the factors of num
        } else if( num % 5 == 0 ){

            num /= 5;
            continue;

        } else {

            //one of the factors is not 2 , 3 and 5, return false
            return false;

        }

    }

    return true;

}
```
