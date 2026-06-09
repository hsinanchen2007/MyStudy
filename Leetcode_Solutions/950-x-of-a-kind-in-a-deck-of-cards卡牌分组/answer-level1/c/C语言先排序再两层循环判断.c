### 解题思路

X为分组组数，外层循环遍历不同的分组数量，进行判断。
num为每组元素个数，内层循环判断每组元素是否都相同，如果都相同，则可以这么分组。（排序后判断每组元素是否相同只需要比较每组首尾元素即可）

### 代码

```c
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

bool hasGroupsSizeX(int* deck, int deckSize){
    bool res=false;
    int i, X, num;

    qsort(deck, deckSize, sizeof(int), cmpfunc);  // 数组从小到大排序
    for(X=1; X<deckSize; X++){  //X:分组的组数
        if(deckSize%X==0){
            num = deckSize/X;  // 每组元素个数
            for(i=0; i<deckSize; i+=num){
                if(deck[i]==deck[i+num-1]){  // 因为已经排好序了，只需要判断每组的首尾元素是否相同
                    res = true;
                }else{
                    res = false;
                    break;
                }
            }
            if(res){
                return res;
            }
        }
    }
    return false;
}

```