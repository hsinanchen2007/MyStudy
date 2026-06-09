### 解题思路
首先用j将n保护起来，不能使n被破坏数据；
count是代表n的位数；
让j除以10，因为除到最后一位是0，有余数，所以要使用++count，而不是count++；
选出每一位的数字：用n除以1再求10的余数，结果是个位数字，放入sum中，temp再*10，这样循环可以依次选出后面的数字；
将multiply-sum返回，得到答案。

### 代码

```c
int subtractProductAndSum(int n){
    int count = 0,a,b,i,j,multiply = 1,sum = 0,temp;
    j = n;
	while(j != 0)
    {
        j/=10;
        ++count;
    }
		for(i = 0,a = 0,b = 0,temp = 1;i < count;i++){
			a = n/temp;
            b = a%10;
            sum += b;
            temp *= 10;
        }
    
        for(i = 0,a = 0,b = 0,temp = 1;i < count;i++){

            a = n/temp;
            b = a%10;
            multiply *= b;
            temp *= 10;
        }
	return multiply-sum;
}
```