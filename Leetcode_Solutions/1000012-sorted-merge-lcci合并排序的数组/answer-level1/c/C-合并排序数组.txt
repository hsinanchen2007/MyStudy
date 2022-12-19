### 解题思路
此处撰写解题思路
从末尾进行合并，比较两个数组末尾数值的大小。
### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for( int i = m + n; i > 0; i-- ){
        if( m >= 1 && n >= 1 ){
            if( A[ m - 1 ] > B[ n - 1 ]){
                A[ m + n - 1 ] = A[ m - 1 ];
                m--; 
            }
            else{
                A[ m + n - 1 ] = B[ n - 1 ];
                n--;
            }
        }
        if( m == 0 && n != 0 ){
            A[ m + n - 1 ] = B[ n - 1 ];
            n--;
        }
        if( m != 0 && n == 0 ){
            A[ m + n - 1 ] = A[ m - 1 ];
            m--;
        }
        if( m == 0 && n == 0 ){
            break;
        }
    }
    

}
```