```
//根据n的位数确定该位数的最大值，比如n==3,最大值就是10^3-1
//然后创建一个这么大的数组，往里面添加数据，记住，数据是从1开始的
int max = (int) (Math.pow(10, n)-1);
int[] arr = new int[max];
for (int i = 0; i < max; i++) {
    arr[i] = i+1;
}
return arr;
```
