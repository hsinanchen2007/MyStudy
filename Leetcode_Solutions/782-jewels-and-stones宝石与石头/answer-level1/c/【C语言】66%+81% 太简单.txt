### 解题思路
1.思路：太简单了，不赘述。
2.corner condition：
（1）.两个字符串是否为空的判断；
3.经验教训：太简单~~
4.耗时：10mins，还好，~~！~~
（1）本来可以6~7mins搞定的，但中间忘了取数组长度strlen(J)，哎~~，多花了1~2mins。------编码要集中精力，保证脑子里所想的都能写出来，别忘记。
![image.png](https://pic.leetcode-cn.com/ba1f02dec876f15faa3a83c4edafba3291479a7417f21d7ef22fcd2e8175bbca-image.png)


### 代码

```c
int numJewelsInStones(char * J, char * S){
    int i= 0;
    int j = 0;
    int lenJ = 0;
    int lenS = 0;
    int count = 0;
    if(J == NULL || S == NULL) {
        return 0;
    }
    lenJ = strlen(J);
    lenS = strlen(S);

    for(i = 0; i < lenS; i++) {
        for(j = 0; j < lenJ; j++) {
            if(S[i] == J[j]) {
                count++;
            }
        }
    }
    return count;
}
```