![image.png](https://pic.leetcode-cn.com/a87daa4f547151313cd02c2a5cb43d1875daa7acd169346f450d86a027f989a1-image.png)

# 三种思路
- 实现函数 循环调用
- 双层循环 线搜
- 哈希展开后计算
# 两种循环
两种循环等效
- while循环
- for循环
# 两种优先
- 优先循环宝石集合J判断S中J[i]个数 (宝石存在)
- 优先循环石头集合S判断s[i]是否为J中元素 (宝石与否)

*不管怎么写实质上都包含两层循环嵌套，效率差异不明显，都是0~4ms 6.6~6.8MB的结果，实际结果根据天时地利人和存在微妙偏差，以下解法皆已确认跑出了0ms结果*

# 解法
根据上述分析共实现3×2×2=12种解法下面展示部分解法实现

## 提交1 函数调用 while循环 宝石与否
```c
int isJ(char *J,char* s){
    while(*J)if(*J++==s)return 1;
    return 0;
}
int numJewelsInStones(char * J, char * S){
    int count=0;
    while(*S)if(isJ(J,*S++))count++;
    return count;
}
```
## 提交2 函数调用 while循环 宝石存在
取巧调用了标准库的`strchr()`作为宝石存在函数
```c
int numJewelsInStones(char * J, char * S){
    int count=0;
    for(int i=0;S[i];i++)if(strchr(J,S[i]))count++;
    return count;
}
```
## 提交3 双层循环 while循环 宝石与否
```c
int numJewelsInStones(char * J, char * S){
    int count=0;
    char * Jp=J;
    while(*S){
        J=Jp;
        while(*J)if(*J++==*S){count++;break;}
        S++;
    }
    return count;
}
```
## 提交4 双层循环 while循环 宝石存在
```c
int numJewelsInStones(char * J, char * S){
    int count=0;
    char * Sp=S;
    while(*J){
        while(*S){
            if(*J==*S)count++;
            S++;
        }
        S=Sp;J++;
    }
    return count;
}
```
## 提交5 双层循环 for循环 宝石与否
```c
int numJewelsInStones(char * J, char * S){
    int count=0;
    for(int i=0;S[i]!=0;i++){
        for(int j=0;J[j]!=0;j++){
            if(J[j]==S[i]){count++;break;}
        }
    }
    return count;
}
```
## 提交6 双层循环 for循环 宝石存在
```c
int numJewelsInStones(char * J, char * S){
    int count=0;
    for(int i=0;J[i]!=0;i++){
        for(int j=0;S[j]!=0;j++){
            if(S[j]==J[i]){count++;}
        }
    }
    return count;
}
```
## 提交7 哈希散列 for循环 宝石与否
```c
int numJewelsInStones(char * J, char * S){
    char hash[58] = {0};
    int count=0;
    for (int i = 0; J[i]; i++)hash[J[i] - 'A'] = J[i];
    for (int i = 0; S[i]; i++)if (hash[S[i] - 'A'] == S[i])count++;
    return count;
}
```
## 提交8 哈希散列 for循环 宝石存在
```c
int numJewelsInStones(char * J, char * S){
    char hash[58] = {0};
    int count=0;
    for (int i = 0; S[i]; i++)hash[S[i] - 'A']++;
    for (int i = 0; J[i]; i++)count+=hash[J[i] - 'A'];
    return count;
}
```
### 其他
剩下四种是for循环和while循环等价情况，略