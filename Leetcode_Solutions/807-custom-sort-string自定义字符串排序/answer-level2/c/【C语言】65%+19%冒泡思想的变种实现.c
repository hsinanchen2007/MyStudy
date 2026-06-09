### 解题思路
1.思路比较特别：根据S的顺序，利用冒泡算法，将字母按照S中字母的顺序往上冒泡。
2.corner condition：
没有什么特殊的corner condition需要考虑；
3.知识点总结：
数组中两个元素顺序交换的函数实现-------考察最简单的指针操作。更新：其实不是指针操作不对，是exchange的参数是int，而实际需要操作的是char。编译报错问题没有仔细定位清楚。
4.耗时：40mins，及格吧。主要耗时点：
（1）算法的设计与验证-----目前没有想到如何还能更快；
（2）交换的函数实现，编译报错，花了10+mins解决，没有解决了，将交换直接在主函数中实现------指针的基本使用不熟悉；
（3）orderd初始化的位置放在了j循环处，不合理。------算法实现细节没有考虑仔细；
![image.png](https://pic.leetcode-cn.com/d4d2c458bd664221f0aa0dc5e0a33603bd013e243592a435fbc976719e6f29e8-image.png)

......

### 代码

```c
#if 0
void exchange(int *a, int *b) {
    int temp = 0;
    if(a == b) {
        return;
    }
    temp = *a;
    *((int *)a) = ((int *)b);
    *b = temp;
    return;
}
#endif 
char * customSortString(char * S, char * T){
    int i = 0;
    int j = 0;
    int lenS = 0;
    int lenT = 0;
    int ordered = 0;
    int temp = 0;

    lenS = strlen(S);
    lenT = strlen(T);
    for(i = 0, ordered = 0; i <lenS; i++) {
        for(j = 0; j < lenT; j++) {
            if(S[i] == T[j]) {
                //exchange(&T[ordered], &T[j]);
                temp = T[ordered];
                T[ordered] = T[j];
                T[j] = temp;
                ordered++;        
            }
            //printf("%c orderd = %d : %s\n", S[i], ordered, T);
        }
    }
    return T;
}
```