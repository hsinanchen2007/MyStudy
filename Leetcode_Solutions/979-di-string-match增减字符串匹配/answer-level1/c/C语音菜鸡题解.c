### 解题思路
先观察题目 找规律
我先发现数字间是有大小关系
一开始考虑的是根据左值决定右值 但看了几个实例后 发现数字是按序的 并且是指定一个区间内选择数字
于是我先取字符串的长度 得出了最大值 以及 最小值
此时我可以遍历数组 根据I 与 D 选取我可用的最大最小值 写入
最后返回数组即可

### 代码

```c
int* diStringMatch(char* S, int* returnSize){
    int char_size = strlen(S);
    int k = char_size;
    int j = 0;
    *returnSize = char_size + 1;
    int* ret = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize ; i ++){
        if(S[i]=='D'){
             ret[i] = k--;
        }else{
             ret[i] = j++;
        }
    }
    return ret;
}
```

```
int* diStringMatch(char* S, int* returnSize){
    int char_size = strlen(S);
    int k = char_size;
    *returnSize = char_size + 1;
    int* ret = malloc(sizeof(int) * (*returnSize));
    int* ret2 = malloc(sizeof(int) * (*returnSize));
    for(int i = *returnSize-1; i > 0  ; i --){
        ret[i] = char_size--;
    }
    ret[0] = 0;
    int j = 0;
    for(int i = 0; i < *returnSize ; i ++){
        if(S[i]=='D'){
             ret2[i] = ret[k--];
        }else{
             ret2[i] = ret[j++];
        }
    }
    return ret2;
}
```