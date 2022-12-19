```
/**
*
*整体思路：
*1.遍历数组，计算全部元素和，
*2.计算start和destination之间的距离，
*   a.如果start<destination，则按start递增遍历该距离长度
*   b.如果strat>destination，则按start递减遍历该距离长度
*3.元素集体和减去该段距离
*
*/

int distanceBetweenBusStops( int * distance , int distanceSize , int start , int destination ){

    //the parameter of in_dis is the total distance of all element
    //the parameter of out_dis is the distance between start and destination
    int in_dis = 0 , out_dis = 0;

    //calculating the total distance
    for( int i = 0 ; i < distanceSize ; i++ ){

        in_dis += *( distance + i );

    }

    //if start smaller than destination
    if( start < destination ){

        for( int i = start ; i < destination ; i++ ){

            out_dis += *( distance + i );

        }

    } else {

        //if start bigger than destination
        for( int i = start - 1 ; i >= destination ; i-- ){

            out_dis += *( distance + i );

        }

    }

    in_dis -= out_dis;

    return out_dis > in_dis ? in_dis : out_dis;

}
```
