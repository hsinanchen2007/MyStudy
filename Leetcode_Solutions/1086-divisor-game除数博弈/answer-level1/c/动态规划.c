### 解题思路
因为两个玩家都以最佳状态参与游戏，所以他/她们每次选择的答案都已使对方选择`约数x`时失败为目标。
因此，N时，玩家想要获胜，那么选择的`约数x`必然使N-x时，会令玩家会失败。
基于以上结论，得出状态转移方程: x为N的一个约数。
    `result[N]=(result[N-x]==false)&&(i%j==0)`
### 代码

```c
bool divisorGame(int N){
    bool result[1001]={false};
    result[1]=false;
    result[2]=true;
    for(int i=3;i<=N;i++){
        for(int j=1;j<i;j++){
            if(result[i-j]==false && i%j==0){
                result[i]=true;
                break;                
            }
        }
    }
    return result[N];
}


```