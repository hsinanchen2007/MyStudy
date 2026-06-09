```
/**
*
*整体思路：
*1.将consts数组数据存入结构体数组中，
*   此时双重指针相当于一维数组的，因为结构体本身就是指针，
*2.对数组进行快速排序，排序依据是a,b对应出差代价的差值
*3.双重指针前半部分前往A市，后半部分前往B市
*
*/

typedef struct{

    //the total price of people go to A city 
    int a_price;
    //the total price of people go to B city 
    int b_price;

} Price;

int cmp( const void ** a , const void ** b ){

    return ( ( *( Price ** )a ) -> a_price ) - ( ( *( Price ** )a ) -> b_price ) 
            - ( ( *( Price ** )b ) -> a_price ) + ( ( *( Price ** )b ) -> b_price );

}

int twoCitySchedCost( int ** costs , int costsSize , int * costsColSize ){

    //the price of each people to go to A and B city
    Price ** price = ( Price ** )malloc( sizeof( Price * ) * costsSize );
    //the optimized price of people to go to A and B city
    int sum = 0;

    //copy the array to the struct's array
    for( int i = 0 ; i < costsSize ; i++ ){

        *( price + i ) = ( struct Price * )malloc( sizeof( Price ) * 1 );

        ( *( price + i ) ) -> a_price = *( *( costs + i ) + 0 );
        ( *( price + i ) ) -> b_price = *( *( costs + i ) + 1 );

    }

    //quick sort
    qsort( price , costsSize , sizeof( Price * ) , cmp );

    //calculating the element's value
    for( int i = 0 ; i < costsSize ; i++ ){

        if( i < ( costsSize / 2 ) ){

            sum += ( *( price + i ) ) -> a_price ;
            continue;
            
        }

        sum += ( *( price + i ) ) -> b_price ;

    }

    return sum;

}
```

快速排序第二种写法

```
/**
*
*整体思路：
*1.将consts数组数据存入结构体数组中，
*   此时双重指针相当于一维数组的，因为结构体本身就是指针，
*2.对数组进行快速排序，排序依据是a,b对应出差代价的差值
*3.双重指针前半部分前往A市，后半部分前往B市
*
*/

int cmp( const void ** a , const void ** b ){

    return ( *( *( int ** )a + 0 ) - *( *( int ** )a + 1 ) ) 
            - ( *( *( int ** )b + 0 ) - *( *( int ** )b + 1 ) );

}

int twoCitySchedCost( int ** costs , int costsSize , int * costsColSize ){

    int sum = 0 , i = 0;

    qsort( costs , costsSize , sizeof( *( costs + 0 ) ) , cmp );

    for( ; i < costsSize / 2 ; i++ ){

        sum += *( *( costs + i ) + 0 );

    }

    for( ; i < costsSize ; i++ ){

        sum += *( *( costs + i ) + 1 );

    }

    return sum;

}
```

