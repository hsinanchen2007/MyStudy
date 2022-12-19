### 解题思路
神奇的一道题，debug n次

@ps：           if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7))  
  官方的第二个判断条件中判断了pop的值，来判断是否越界，但是由于题目给定的是int型的数据，范围为-2147483648到2147483647，所以逆序输出的时候，当rev == INT_MAX，rev== INT_MIN，第十位的数字加入的即是原来的首位，pop只能在-2到2之间，就不会大于7或者小于-8，造成越界了。

所以在本题中省略了第二个判断条件，情况较为特殊，一般情况下还是要考虑第二个条件。

### 代码

```cpp
class Solution {
public:
   int reverse(long int x) {
    int  res=0;     //res表示结果

    while(x!=0)          
    {
        if(res>INT_MAX / 10) return 0;        //注意：看ps
        if(res<INT_MIN / 10) return 0;        //判断是否将要发生越界
        res*=10;          
        res=res+x%10;   
        x=x/10;         
    }
    return res;
    }
};
```