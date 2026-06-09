### 解题思路
不算快速的方法，但很好理解：informtime为0的员工即使底层员工， 从他们开始一步步找他的上级，直到target==headID。比较这些时间中最长的即可。

### 代码

```c
// void MyDfs(int currID, int *manager, int managerSize, int *informTime, int clock,
//            int *max) {
//     return;
// }
//以上为被弃的大法师
//一下为从下而上的实现代码
int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize){
    if (n == 1)  return 0;
    int target;
    int clock, max = 0;
    for (int i = 0; i < managerSize; i++) {
        if (informTime[i] == 0) {
            target = manager[i];
            clock = 0;
            while (target != headID) {
                clock += informTime[target];
                target = manager[target];
            }
            clock += informTime[target];
            if (clock > max)  max = clock;
        }
    }
    return max;
}
```