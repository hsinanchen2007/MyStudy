```
/**
*时间复杂度O(N)，空间复杂度O(3)
*整体思路：... 8 7 6 5 4 3 2 1 
*1.如果当前数组长度小于2，返回0
*2.遍历数组，寻找最小值和最大值，profit用来补存放历史最大值
*3.如果为最小值，则将当前最小值放在min 5到最高位，1-4放置当前最小值的下标，清空当前最大值max
*4.如果当前为最大值，且下标大于min记录的下标，则更新profit的值
*
*/

int maxProfit( int * prices , int pricesSize){

    //if the length of prices less than 2, return 0
    if( pricesSize < 2 ){

        return 0;

    }

    //the parameter of min is used to save the minimun and it's index in prices
    //the parameter of max is used to save the maximun
    //the parameter of profit is used to save the maximun of profit
    int min = *( prices + 0 ) * 10000 + 0 , max = - 1 , profit = 0;

    //visiting prices
    for( int i = 1 ; i < pricesSize ; i++ ){

        //if current element is the minimun in prices
        if( ( min / 10000 ) > *( prices + i ) ){

            min = *( prices + i ) * 10000 + i;
            max = -1;

        }

        //if current element is the maximun in prices 
        if( ( max < *( prices + i ) ) && i > ( min % 10000 ) ){

            max = *( prices + i );
            //if current profit is bigger than the value of historical profit
            profit = profit > max - min / 10000 ? profit : max - min / 10000;

        }

    }

    return profit;

}
```
