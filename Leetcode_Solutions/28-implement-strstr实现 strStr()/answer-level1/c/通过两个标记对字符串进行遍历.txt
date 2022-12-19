进行边界处理之后，我们使用 k 进行角标标记，first 用于 拨正 i 循环的起点


```cpp
int strStr(char * haystack, char * needle) {

   ///！ 获取字符串长度
  int a = strlen(haystack);
  int b =  strlen(needle);
  //TODO:解答器说明，当  needle 为 空时，我们返回0
  if (b == 0) {
    return 0;
  } else if (a == 0) {
    return -1;
    
  }
  
  
  int k = 0;
  ///! 用于记录i的初始位置
  int first = 0;
  for (int i = 0; i < a;) {
    if (haystack[i] == needle[k]) {
      //! 当找出字符串时， 算出 当前i的位置，再往前推 b -1 的长度
      if ( k == b -1 ) {
        return  i -  b + 1;
      }
      k ++;
      i ++;
    } else {
      k = 0;
      first++;
      i = first;
    }
    
  }
  
  return -1;
}



```