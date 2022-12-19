这道题最简单的判断方法是n & (n - 1)== 0
最初写的代码如下
bool isPowerOfTwo(int n) {
  if((n & (n - 1)) == 0&&n > 0)	
    return true;
  else
    return false;
}
但是一直报错,后来才想起来C语言按照从上到下,从左往右的顺序执行,所以应该把if里面的条件改为if(n > 0&&(n & (n - 1)) == 0),先判断是正数,就成功了