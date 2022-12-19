### 解题思路
1. 没有使用巧妙的规律，使用动态规划的思想；
2. 获取每个数字的游戏次数，根据次数判断谁赢，爱丽丝先手，奇数次赢；
3. 每次游戏时都会先取N的约数，对于质数，则第一次只能取1，对于偶数需要获取所有约数，取不同的约数则游戏次数不同；
4. 我们只需在游戏次数为奇数次时返回即可，其他情况无需关注；
5. 想法：游戏时，不同的玩法中，只要有一次的游戏次数为奇数则爱丽丝赢，如果所有的次数都是偶数，则爱丽丝输。

### 代码

```c
/* 使用动态规划的方法  */
bool divisorGame(int N){
    
    /* 定义每个状态下游戏的次数 */
    int op[N+1];
    memset(op, 0, N+1);
    
    int prime[N + 1];
    memset(prime, 0, N + 1);
    
    int index;
    
    if (N == 1) {
        return false;
    }
    
    if (N == 2) {
        return true;
    }
    
    op[1] = 0;
    op[2] = 1;
    
    /* 根据规律可以看出，当前数字的游戏次数刚好是比它小一个数加一 */
    for (int i = 3; i <= N; i++) {
        for (int j = 2; j < i; j++) {
            index = 0;
            if(i % j == 0) {
                prime[index] = j;
                index++;
            }
        }
        
        if (index == 0) {
            op[i] = op[i - 1] + 1;
            continue;
        }
        
        /* 各种游戏方法中有一种爱丽丝赢，则退出 */
        for (int k = 0; k < index; k++) {
            op[i] = op[i - prime[k]] + 1;
            if (op[i] % 2 == 1) {
                break;
            }
        }
    }
    
    /* 爱丽丝先手，游戏次数为奇数，则爱丽丝赢 */
    if (op[N] % 2 == 0) {
        return false;
    }
    else {
        return true;
    }
}
```