一个C语言计算任何次幂的模板（多少都可以），把log（4）改一改就行

bool isPowerOfFour(int num)
{
    if(num==0)
        return false;
    double m=log(num)/log(4),b,c;
    c=m;
    if (c - (int)c >= 0.5)
		c = c + 1;
    b=m-(int)c;
    if(b<0)
        b=-b;
    if(b<0.0000000001)
        return true;
    return false;
}
