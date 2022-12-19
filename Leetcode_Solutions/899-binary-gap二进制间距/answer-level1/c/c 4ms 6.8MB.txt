```
/**
*
*整体思路：
*1.每次对2取余判断，根据当前1的下标减去前一个1的下标判断距离，
*2.如果1的个数不为1，则判断当前距离值是否大于记录的最大值，是则替换
*
*/

int binaryGap( int N ){
    
    //the parameter of max is used to save the maxinum of distance
    //the parameter of index is the index of current value
    //the parameter of form is used to save former index of 1
    //the parameter of count is used to 
    int max = 0 , index = 0 , form = 0 , count = 0;

    while( N > 0 ){

        //the index of value move to next
        index++;

        if( N % 2 == 1 ){

            count++;

            //if the count of 1 not equal 1, judging the distance bigger than max or not
            if( count != 1 && index - form > max ){

                max = index - form;

            }

            form = index;

        }
        
        N /= 2;

    }

    return max;

}
```
