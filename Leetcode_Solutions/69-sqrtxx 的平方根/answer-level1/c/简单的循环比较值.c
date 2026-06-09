这种方法时间复杂度和空间复杂度都有点大，但是这种方法很容易理解。
在长整型不溢出的情况下，规定一个数求它的平方是否为x，若是则返回i
若不是比较是不是大于i的平方却小于（i+1）的平方若是则返回i。
这样既可。

int mySqrt(int x){
    for(long i=0;i<0x7fffffff;i++)
     {
        if(i*i==x)
            return i;
        if(i*i<x && x<(i+1)*(i+1))
            return i;
    }
    return 0;
}