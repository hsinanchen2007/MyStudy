
注意观察例1
![1583326485(1).jpg](https://pic.leetcode-cn.com/ec71a42985d5a16f53d6e8fc93ec6149c14b8702e7cc2d2acacc2739ff640d98-1583326485\(1\).jpg)


```
/**
*
*整体思路：（每一行满足递减，每一列也满足递减）
*1.由于矩阵有序，即从后向前，采用逆序遍历即可
*2.如果某一行，最后一个元素大于0，立即返回结果，因为前一行的最后一个元素必大于0
*3.如果遍历该行存在某个元素大于0，就不需要继续遍历，因为在该行该元素前面所有元素必大于0
*4.如果小于0，则计数器count加一
*5.返回结果
*/

int countNegatives( int ** grid , int gridSize , int * gridColSize){

    //the parameter of count used to save the number of elements that less than zero
    //用于存储小于0的元素个数
    int count = 0;

    //visiting the array 遍历数组
    for( int i = gridSize - 1 ; i >= 0  ; i-- ){

        //the parameter of j used to point the last element in current row
        //j指向改行的最后一个元素
        int j = *( gridColSize + i ) - 1;

        //if the last element in current row bigger than 0, return cout
        //如果最后一个元素大于，则前一行最后一个元素必大于0，矩阵前面所有元素必大于0
        if( *( *( grid + i ) + j ) >= 0 ){

            return count;

        }

        //visiting elements in current row
        for(  ; j >= 0 ;j-- ){
            
            //if current element in current row bigger than 0, continuing former row
            //如果当前行的当前元素大于0，继续遍历前一行元素，该行前面元素必大于0
            if( *( *( grid + i ) + j ) >= 0 ){

                return count;

            }

            count++;

        }

    }

    return count;

}
```
