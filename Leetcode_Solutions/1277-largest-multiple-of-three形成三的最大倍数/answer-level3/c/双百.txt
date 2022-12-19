### 解题思路
思路比较直观，但繁琐，考虑各种情况（代码没优化），如果有大佬更好的思路恳请指点；
1. 首先排序，如果最大值为0直接返回0即可（从大到小）
2. 我们用一个mods数组来存放digits除三的余数，mods[i]=digits[i]%3，然后用sum代表mods数组的和
3. 这样的话结果只有四种情况(sum<=2   ->直接返回空字符串即可，因为没有和为3的数；
                sum%3==1 ->那么我们从后向前遍历mods只要去掉一个值为1的就行，如果没有值为1的那就把值为0的全部搞上去
                sum%2==2 ->思路一样去掉值为2的，没有的话去两个值为1的（第一遍的时候没加这个情况但还是对了），还没直接把值为0的搞上去)

### 代码

```c
int comp(int *a,int *b){
    return *b - *a;
}

char * largestMultipleOfThree(int* digits, int digitsSize){
    qsort(digits,digitsSize,sizeof(int),comp);
    if (digits[0]==0){
        char *ans=malloc(sizeof(char)*2);
        ans[0] = 48;
        ans[1] = 0;
        return ans;
    }
    int *mods=malloc(sizeof(int)*digitsSize);
    long sum=0;
    for (int i=0;i<digitsSize;i++){
        mods[i] = digits[i]%3;
        sum += mods[i];
    }
    if (sum<=2)
        return "";
    char *ans=malloc(sizeof(char)*(digitsSize+1));
    if (sum%3==0){
        for (int i=0;i<digitsSize;i++)
            ans[i] = digits[i] + 48;
        ans[digitsSize] = 0;
    }
    else if (sum%3==1){
        int index=-1,top=-1;
        for (int i=digitsSize-1;i>=0;i--){
            if (mods[i]==1){
                index = i;
                break;
            }
        }
        if (index!=-1){
            for (int i=0;i<digitsSize;i++){
                if (i!=index)
                    ans[++top] = digits[i]+48;
            }
            ans[++top] = 0;
            return ans;
        }
        else{
            for (int i=0;i<digitsSize;i++){
                if (mods[i]==0)
                    ans[++top] = digits[i]+48;
            }
            ans[++top] = 0;
            return ans;
        }
    }
    else{
        int index=-1,top=-1;
        for (int i=digitsSize-1;i>=0;i--){
            if (mods[i]==2){
                index = i;
                break;
            }
        }
        if (index!=-1){
            for (int i=0;i<digitsSize;i++){
                if (i!=index)
                    ans[++top] = digits[i]+48;
            }
            ans[++top] = 0;
            return ans;
        }
        else{
            for (int i=0;i<digitsSize;i++){
                if (mods[i]==0)
                    ans[++top] = digits[i]+48;
            }
            ans[++top] = 0;
            return ans;
        }
    }
    return ans;
}
```