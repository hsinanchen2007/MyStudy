```
/**
*
*整体思路：
*1.首先初始化相关内存
*2.首先存储当前像素点的原始值到old_image，再更为当前像素点为newColor
*   2-1.如果ole_image和newColor相等，则返回函数
*   2-2.对同sc列的sr-1行进行判断，如果等于old_image，则递归调用当前像素点
*   2-3.对同sc列的sr+1行进行判断，如果等于old_image，则递归调用当前像素点
*   2-4.对同sr行的sc+1列进行判断，如果等于old_image，则递归调用当前像素点
*   2-5.对同sr行的sc-1列进行判断，如果等于old_image，则递归调用当前像素点
*
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
*Fcuntion: visiting the points in the former, next, left and right of current image, updating wo new color
*@param: int ** image : the picture ready to be updated
*@param: int imageSize : the length of the row in the picture
*@param: int * imageColSize : the length of column in the picture
*@param: int sr : the row of current point
*@param: int sc : the column of current point
*@param: int newColor : the color is used to replace old image
*return: void
*/
void search( int ** image , int imageSize , int * imageColSize , int sr , int sc , int newColor ){

    /*saving the ponit of old image*/
    int old_image = *( *( image + sr ) + sc );
    /*updating the old image to new color */
    *( *( image + sr ) + sc ) = newColor;

    /*if current point of image is equaling to old image*/
    if( old_image == newColor ){

        return ;
        
    }

    /*if the former row point in the same column is equaling to the old image of current one*/
    if( sr - 1 >= 0 && ( *( *( image + sr - 1 ) + sc ) == old_image ) ){

        search( image , imageSize , imageColSize , sr - 1 , sc , newColor );

    }

    /*if the next row point in the same column is equaling to the old image of current one*/
    if( sr + 1 < imageSize && ( *( *( image + sr + 1 ) + sc ) == old_image ) ){

        search( image , imageSize , imageColSize , sr + 1 , sc , newColor );

    }

    /*if the left point in the same row is equaling to the old image of current one*/
    if( sc - 1 >= 0 && ( *( *( image + sr ) + sc - 1 ) == old_image ) ){

        search( image , imageSize , imageColSize , sr , sc - 1 , newColor );

    }

    /*if the right point in the same row is equaling to the old image of current one*/
    if( sc + 1 < *( imageColSize + sr ) && ( *( *( image + sr ) + sc + 1 ) == old_image ) ){

        search( image , imageSize , imageColSize , sr , sc + 1 , newColor );

    }

}

int ** floodFill( int ** image , int imageSize , int * imageColSize , int sr , int sc , int newColor 
                                                , int * returnSize , int ** returnColumnSizes ){

    /*intializing the length of row in the image*/                                                
    *returnSize = imageSize;
    /*alloclating memory to save the length of each column*/
    *( returnColumnSizes + 0 ) = ( int * )malloc( sizeof( int ) * imageSize );

    /*titializing the length of each column*/
    for( int i = 0 ; i < imageSize ; i++ ){

        *( *( returnColumnSizes + 0 ) + i ) = *( imageColSize + i );

    }

    /*updaintg the old image*/
    search( image , imageSize , imageColSize , sr , sc , newColor );

    return image;

}
```
