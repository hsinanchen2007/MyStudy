### 解题思路
左边的数小于右边的就进行减法运算，大于右边得就进行加法运算，最后一个数必然是加法运算。

### 代码（正确）

```c
int get(char c){
    switch(c){
        case 'I': return 1; break;
        case 'V': return 5; break;
        case 'X': return 10; break;
        case 'L': return 50; break;
        case 'C': return 100; break;
        case 'D':return 500;  break;
        case 'M':return 1000;  break;
    }
    return 0;
}
int romanToInt(char * s){
    int sum=0;
    for (int i=0;i<strlen(s)-1;i++){

      if(get(s[i])<get(s[i+1])){
          sum-=get(s[i]);
      }else{
          sum+=get(s[i]);
      }
     // printf("%d ",sum);
    }
    sum+=get(s[strlen(s)-1]);
    
    return sum;
}
```

