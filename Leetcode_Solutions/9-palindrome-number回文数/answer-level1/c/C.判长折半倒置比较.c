### 解题思路
1.判断所给十进制数的长度
2.将十进制数劈成两半，后面一半倒置
3.前后比较，相等则返回true

### 代码

```c

bool isPalindrome(int x){
 if(x<0) return false;
 else if(!x) return true;
 int x1=x;int len=0;
 int num=0;int ten=1;
 while(x1!=0){
   len++;
   x1/=10;
 }
 x1=x;
 for(int i=0;i<len/2;i++){
   num=num*10+x1%10;
   x1/=10;
   ten*=10;
 }
  if(len%2==1) ten*=10;
  if(x/ten==num)
  return true;
  return false;
}

















```