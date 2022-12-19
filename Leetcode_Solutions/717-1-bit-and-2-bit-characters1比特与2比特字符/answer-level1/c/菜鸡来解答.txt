### 解题思路
此处撰写解题思路



### 代码

```c
bool isOneBitCharacter(int* bits, int bitsSize){
    int i=0;
    while(i<bitsSize){
        if(i==bitsSize-1)
            return 1;
        if(bits[i]==1)
            i=i+2;
        else
            i++;
    }
    return 0;

}
```