### 解题思路
此处撰写解题思路

### 代码

```c
int clumsy(int N){
    if(N>4)
    {
        switch(N%4){
            case 0: return N+1; break;
            case 1: return N+2; break;
            case 2: return N+2; break;
            case 3: return N-1; break;
            default: break;
        }
    }
    if(N==1) return 1;
    if(N==2) return 2;
    if(N==3) return 6;
    if(N==4) return 7;
    return -1;
}
```