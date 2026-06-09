### 解题思路
1.思路：
分为三层循环：
（1）第一层：对各层正方形做旋转。用m来遍历各层正形。
![image.png](https://pic.leetcode-cn.com/40b023773940cd74e6b462740e70b99c210dd563fb780b3f6899f2b238806b74-image.png)
（2）第二层：对正方形边上的各个点分别做旋转。从旋转的特点来看，只需要遍历一条边上的点即可完成整个正方形四条边上点的旋转。对应的时n遍历。
（3）第三层：
每个正方形的旋转需要进行“传递旋转”，示意图如下：
![image.png](https://pic.leetcode-cn.com/76bac10a53829cb80b326f74009ec3162bf01635c2c9f5a5c02a2dd92adb6d9e-image.png)
完成一个点的“传递旋转”需要4步，因此，step的限制为<5.
传递旋转的状态传递方程如下：matrix[i][j] = matrix[j][MAXi - i];

2.corner condition：
（1）.[[1]]；
3.知识点总结：
传递旋转的状态传递方程如下：matrix[i][j] = matrix[j][MAXi - i]。
4.耗时：60mins，虽然算法有点复杂，但我觉得应该在45mins能搞定~~。主要耗时点：
（1）算法的设计，最开始以为只是简单的做matrix[i][j]和matrix[j][MAXi - i]的交换，实际实现时发现，需要做状态传递-----算法设计；
（2）算法实现时，因为在第二层循环没有做step置0,和i=m，j=n，导致结果不对，花了一些时间排查------算法实现不缜密；
![image.png](https://pic.leetcode-cn.com/9354130f45e110ba1a5b4d996560927c4b587335f2c42245038d063ce7f5922b-image.png)


### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i = 0;
    int j = 0;
    int tempj = 0;
    int step = 0;
    int swap = 0;
    int source = 0;
    int m = 0;
    int M = 0;
    int n = 0;
    if(matrixSize == 1) {
        return;
    }
    if(matrixSize % 2 == 0) {
        M = matrixSize / 2 - 1;
    }
    else {
        M = (matrixSize - 1) / 2;
    }

    for(m = 0; m <= M; m++) {

    for(n = m; n < matrixSize - 1 - m; n++) {
        source = matrix[m][n];   
        i = m;
        j = n; 
        step = 0;
    while(step < 5) {
        swap = matrix[j][matrixSize - 1 - i];
        matrix[j][matrixSize - 1 - i] = source;
        source = swap;
        tempj = matrixSize - 1 - i;
        i = j;
        j = tempj;
        step++;
    }
    }
    }


    return;
}
```