### 解题思路
![图片.png](https://pic.leetcode-cn.com/9ab016ec3c8064736c2f2d8765225931d666f74cad02e231371e3933a89c9a39-%E5%9B%BE%E7%89%87.png)

既然三部分都相等，所以只要求出平均数，就能知道这三部分的各自的和是多少。
然后再进行顺序遍历相加与这个和比较即可。
1、先求出平均数。如果是小数就排除了。三数之和必然整数
2、从左到右开始遍历，相加，如果sum1==ave就确定了一个分割点。可能有同学觉得第一个分割点可能会有其他的情况，或许在右一点的地方，大可不必担心。
假如求得了分割点为flag1,[0..flag1]的和为ave，正巧flag1的右边有个值flag1'让[0,falg1']的和也为ave,可得[flag1+1,flag1']的和为0。既然都是0了，加不加都没有影响，也不影响第二个分割点。
3、同上，找到第二个分割点。
4、如果到最后一个元素才找到第二个分割点，那就算了，false。
### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize<3){
        return false;
    }
    int sum=0;
    for(int i=0;i<ASize;i++){
        sum+=A[i];
    }
    float ave= (float)sum/3;
    if((int)ave!=sum/3){
        return false;
    }
    int sum1=0;int flag1;
    int j=0;
    for(;j<ASize;j++){
        sum1+=A[j];
        if(sum1==(int)ave){
            flag1=j;
            break;
        }
    }
    if(j==ASize-1||j==ASize){
        return false;
    }
    int sum2=0;int flag2;
    int m=flag1+1;
    for(;m<ASize;m++){
        sum2+=A[m];
        if(sum2==(int)ave){
            flag2=m;
            m++;
            break;
        }
    }
    if(m>=ASize){
        return false;
    }
    return true;
}
```