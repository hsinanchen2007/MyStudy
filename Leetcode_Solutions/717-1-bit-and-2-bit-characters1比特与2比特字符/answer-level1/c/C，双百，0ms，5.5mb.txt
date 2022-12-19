### 解题思路
思路很简单，末尾必须是0，0前的连续1必须是偶数

### 代码

```c
bool isOneBitCharacter(int* bits, int bitsSize){
    int cnt=0;
    if(bits[bitsSize-1]==0&&bitsSize==1)
        return 1;
    for(int i=bitsSize-2;i>=0;i--){
        if(bits[i]==1)
            cnt++;
        else
            break;
    }
    return cnt%2?0:1;
}
```