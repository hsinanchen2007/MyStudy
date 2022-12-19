### 解题思路
先通过异或，将两个数中二进制位不同的一保留下来。然后通过右移，逐个将值为1的位进行计数。
做题耗时：36mins，有点长，正常发挥的话应该 < 20mins
![image.png](https://pic.leetcode-cn.com/1675ddb298f0b7a4ebd10425fc2a0749213e3a011b2290b4056408c4cdad432a-image.png)

### 代码

```c


int hammingDistance(int x, int y){
    int yihuo = x ^ y;
    int count = 0;
    int test = 0;
    printf("yihuo = %d\n",yihuo);
    while(yihuo) {
        test = yihuo & 0x01;
        //printf("yihuo = %x ， test = %x\n",yihuo , test);
        if(test) {
            count++;
        }
        yihuo = yihuo >> 1;
    }
    return count;
}
```