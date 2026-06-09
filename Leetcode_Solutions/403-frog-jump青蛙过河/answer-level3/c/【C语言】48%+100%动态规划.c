### 解题思路
1.思路：此题用递归的方式，容易超时，因此得用动态规划来做。具体思路展开如下：
（1）按输入数组stones从头开始遍历stone[i], 0 <= i < stonesSize。
（2）如果从当前stone[i]跳跃x步,能够到下一块石头stone[j],即stone[i] + x == stone[j], kcollect[i][m - 1] <= x <=kcollect[i][m + 1];
其中，kcollect[i][m]表示i前面的石头能跳到第i块石头一共都有哪些x步。由于x可能取多个值，因此需要数组来表示，用m来遍历。（数组的第一位表示第i块石头。）
（3）依次遍历stones数组并记录下每一块石头能到达的步数。如果到达最后一块石头的步数大于0，说明可以到达最终重点，反之则不可以。
2.corner condition：
（1）.题目给的注意说明“第一个石子的位置永远是0”，容易引起误解”第一颗石头的值是0“，其实在我自己构建的用例[2,3]验证发现，这种情况也是对的。------在解题时，尽量构建corner condition很重要，能省去后面很多排错时间；
3.经验总结：
递归思路上容易想到，也容易实现，但时间复杂度比dp要弱。自己的习惯得改过来。
4.耗时：递归：49mins，dp：2h~~花的时间太长了，哎~~。主要耗时点：
（1）dp在实现的时候，脑子已经有点不转了，编码注意力不集中，有些小错误导致后面浪费了很多排错时间。后续可以中场休息5mins，上个厕所-----中场休息；
（2）用打印排错时，应该从结果反向一层一层的加，切忌一次加太深------逐层加打印排错。
![image.png](https://pic.leetcode-cn.com/c42e45c05886dad8065932913a8c1542a892cad6ca903bdf369101ec1c792ece-image.png)



### 代码

```c
#define KMAX 50

bool canCross(int* stones, int stonesSize){
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0;
    int x = 0;
    int base = 0;
    int top = 0;
    int ii = 0;
    int mm = 0;
    bool ret = false;
    int **kcollect = NULL;

    if(stones[1] - stones[0] > 1) {
        return ret;
    }
    kcollect = (int **)malloc(stonesSize * sizeof(int *));
    memset(kcollect, 0x00, stonesSize * sizeof(int *));
    for(i = 0; i <stonesSize; i++) {
        kcollect[i] = (int *)malloc(KMAX * sizeof(int));
        memset(kcollect[i], 0x00, KMAX * sizeof(int));
    }
    kcollect[1][0] = 1;

    for(i = 0; i < stonesSize; i++) {
        //m = 0;
        //printf("kcollect[%d] = %d : {",i, stones[i]);
        //    while(kcollect[i][m] != 0) {
        //        printf("%d,",kcollect[i][m]);
        //        m++;
        //    }
        //printf("}\n");  
        //m = 0;      
        n = 0;
        while(kcollect[i][n] != 0) {
            base = kcollect[i][n] - 1;
            top = kcollect[i][n] + 1;
            for(x = base; x < top + 1; x++) {
                //printf("k = %d:\n",x);
                for(j = i + 1; j < stonesSize; j++)  {
                    //printf("i = %d\n",i);
                    if(stones[i] + x == stones[j]) {
                        //printf("steps = %d can jump from %d to mins stone %d\n",x,stones[i], stones[j]);
                        m = 0;
                        while(kcollect[j][m] != 0) {
                            if(kcollect[j][m] == x) {
                                m = 0;
                                break;
                            }
                            m++;
                        }
                        if(kcollect[j][m] == 0) {
                            kcollect[j][m] = x;
                        }                        
                        m = 0;
                        break;                        
                    }
                    else if(stones[i] + x > stones[j]) {
                        continue;
                    }
                    else {
                        //printf("steps = %d CAN'T jump from %d to mins stone %d\n",x,stones[i], stones[j]);
                        break;
                    }
                }
            }
            n++;    
        }
        
        //for(ii = 0 ; ii < stonesSize; ii++) {
        //    mm = 0; 
        //    while(kcollect[ii][mm] != 0) {
        //        printf("at the end: kcollect[%d][%d] = %d\n",ii,mm,kcollect[ii][mm]);
        //        mm++;
        //    }
        //    mm = 0;
        //}
    }


    m = 0;
    while(kcollect[stonesSize - 1][m] != 0) {
        ret = true;
        m++;
    }
    return ret;
}
```