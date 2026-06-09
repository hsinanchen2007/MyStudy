#思路：
1）反复颠倒其中分子和分母项，并且进行不断加cont中的数
2）约分是不用的。

# 代码：
```
int* fraction(int* cont, int contSize, int* returnSize){
    int *ans  = malloc(sizeof(int) * 2);
    int index = contSize - 1, 
        temp;

    for(;index >= 0;index--){ 
        if(index == contSize - 1){
            ans[0] = 1, 
            ans[1] = cont[index];
        }else{
            ans[1] = ans[1] + ans[0]  * cont[index];
        }
        temp = ans[0];
        ans[0] = ans[1];
        ans[1] = temp;  
    }
    *returnSize  = 2;
    return ans;
}
```
注意：关注好替换其中分子和分母的关系，从而可以减少代码运行时不必要的重复的部分。


