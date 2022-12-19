### 解题思路
1、正确理解题意，汉明距离就是2个整数异或后二进制为1的位的个数。其中，二进制为1的个数可以通过求余2并移位来统计

### 代码

```c
int hammingDistance(int x, int y){
    int tmp;
    int num = 0;

    tmp = x^y;
    if(tmp==0){
        return 0;
    }

    while(tmp){
        if(tmp%2 == 1){
            num++;
        }
        tmp=tmp/2;
    }

    return num;
}
```