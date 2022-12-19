### 解题思路
对gcd算法有更好的认识了，这是来自题解[遍历计数数组并求出最大公约数(Java)](https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/solution/qiu-jie-zui-da-gong-yue-shu-java-by-liweiwei1419/)中的一段话：
    **计算 gcd(a, b) 的时候，虽然我们在讨论的时候，总是假设 a > b ，但在 a < b 的时候，递归函数的第一层就把两个数的值交换了，这一点经过调试是看得很明显的；**
想想的确实这样的！


### 代码

```c
bool hasGroupsSizeX(int* deck, int deckSize){
    if(deckSize==1) return false;
    int gcd(int x,int y);
    int hash[10000];
    int i;
    memset(hash,0,sizeof(hash));
    //模拟了哈希表
    for(i=0;i<deckSize;i++) hash[deck[i]]++;
    int X=hash[0];
    for(i=0;i<10000;i++){
        if(hash[i]==1) return false;
        //X记录数组deck中所有数字出现次数的gcd
        X=gcd(X,hash[i]);
        if(X==1) return false;
    }
    return true;
}
//的确不用判断x与y的大小关系
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
```