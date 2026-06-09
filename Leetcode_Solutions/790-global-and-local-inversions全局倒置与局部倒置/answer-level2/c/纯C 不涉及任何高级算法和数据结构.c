### 解题思路

先看结果:
执行用时 :52 ms, 在所有 C 提交中击败了97.44%的用户
内存消耗 :6.9 MB, 在所有 C 提交中击败了100.00%的用户

**局部倒置必然是全局倒置 全局倒置不一定是局部倒置**
只要出现了 全局倒置 且 不是局部倒置 就说明 肯定不相等
**目标就是找到 是全局倒置 但 不是 局部倒置的就行**

只有两种情况满足:
1. 出现V型低谷,谷底低于 左边缘 之前的任何一个点
2. 出现V型低谷,右边缘低于 除谷底的 之前任何一个点

### 代码

```c
bool isIdealPermutation(int* A, int ASize){
    int lastMax;

    if(ASize <= 2){
        return true;
    }

    lastMax = 0- INT_MAX;

    for(int i = 1; i< ASize; i++){        
        if((A[i] <A[i-1]) && lastMax > A[i]){          
            return false;
        } else {        
            if(lastMax > A[i])
             return false;
        } 

        if(A[i-1] > lastMax)
            lastMax = A[i-1];
    }
    return true;

}
```