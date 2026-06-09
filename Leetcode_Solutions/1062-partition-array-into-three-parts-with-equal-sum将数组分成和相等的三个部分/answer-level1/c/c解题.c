### 解题思路
此处撰写解题思路

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    int ans = 0 , target = 0;
    for(int i = 0; i<ASize ; i++){
        ans += A[i];
    }

    if(ans % 3 != 0) return false;
    else target = ans/3;

    int head = 0  , leans = 0 , k= 0;
    while(head < ASize){
        leans += A[head];
        if(leans==target){
            leans = 0; k++;
        }
        head++;
    }
    //若k<3,则无法分成三份，若k>3是为了考虑当target==0的情况
    if(k>=3) return true;
    else return false;
}
```