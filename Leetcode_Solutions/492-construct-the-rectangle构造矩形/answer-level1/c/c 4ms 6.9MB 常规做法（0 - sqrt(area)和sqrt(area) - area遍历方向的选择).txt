![Figure_1-1.png](https://pic.leetcode-cn.com/f32ce40f4c8fdc0885257066090d3d34dcb2ee3687850ef2fd41a3a4912bed2b-Figure_1-1.png)


x的取值范围为1-100,000,000
x：横轴为面积area，y：面积的开根号
在图中，我们看到如果把蓝色虚线去填补红色虚线，还差6才能到9，根据函数图像，我们可以看到切点一次导数随着x增大不断
减小，就是说函数曲线偏离x轴的程度会越来越小，y值用来填补0到x轴上某一点的值会越来越小，所以取sqrt( area )到0之
间遍历

```
/**
*
*整体思路：
*1.从area的平方根开始，倒序遍历1-sqrt( area )之间的数
*2.一旦找到一个长宽，该长宽一定是差值最小的一组长宽
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * constructRectangle( int area , int * returnSize){
    
    unsigned int * buffer = ( unsigned int * )malloc( sizeof( unsigned int ) * 2 );
    
    *( buffer + 0 ) = sqrt( area );
    *returnSize = 2;

    while( *( buffer + 0 ) > 0  ){

        if( area % *( buffer + 0 ) == 0 ){

            *( buffer + 1 ) = *( buffer + 0 );
            *( buffer + 0 ) = area / *( buffer + 1 );

            break;

        }

        *( buffer + 0 ) -= 1;

    }
    
    return buffer;

}
```
