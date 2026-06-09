```
/**
*
*整体思路：
*1.遍历数组，如果遇到1，指针i移动两个单位，遇到0时，判断是否为最后一个元素，如果是，直接返回true
*  如果不是，则移动一个单位
*2.返回false
*
*/

bool isOneBitCharacter( int * bits , int bitsSize ){

    
    //visiting array
    for( int i = 0; i < bitsSize ; i++ ){

        //if the value of current element is 1, moving two steps
        if( *( bits + i ) == 1 ){

            i++;

        ////if the value of current element is zero, judging whether it is the last element
        } else if( *( bits + i ) == 0 && i + 1 == bitsSize ){

            return true;

        }

    }

    return false;

}
```
