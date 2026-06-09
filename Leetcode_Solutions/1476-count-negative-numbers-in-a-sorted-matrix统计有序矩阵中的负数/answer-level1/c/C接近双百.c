### 解题思路
此处撰写解题思路
从最后一行最后一列扫描
若此行最后一个元素 >0 则直接返回
若此列某个元素 >0 则跳出内循环，检查上一行
![image.png](https://pic.leetcode-cn.com/f1bc197df202caede4bc20aad8088bd6064ceebe29d579f3f940c90e22f457c5-image.png)

### 代码

```c
int countNegatives( int ** grid , int gridSize , int * gridColSize)
{
    int count = 0;
    for( int i = gridSize - 1 ; i >= 0  ; i-- )
	{
        int j = *( gridColSize + i ) - 1;
        if( *( *( grid + i ) + j ) >= 0 )
		{
            return count;
        }
        for(  ; j >= 0 ;j-- )
		{
            if( *( *( grid + i ) + j ) >= 0 )
			{
                break;
            }
            count++;
        }
    }
    return count;
}


```