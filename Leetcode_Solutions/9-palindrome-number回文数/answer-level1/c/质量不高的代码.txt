### 解题思路
我的代码写的比较复杂，只是因为需要进行将整型数字转换成字符串，然后再逐步进行比较每一个字符是否相等。

### 代码

```c
void int_char(int x,char *numchar)
{
    int temp=x;
    int i=0;
    while(temp)
    {
        numchar[i++]=(temp%10)+'0';
        temp=temp/10;
    }
}
void reverse_char(char *numchar,char *renumchar,int k)
{
    int j=k-1;
    for(int i=0;i<k&&j>=0;i++)
    {
        renumchar[i]=numchar[j--];
    }
}

bool isPalindrome(int x){
    if(x<0) return false;
    char numchar[100]="";
    int_char(x,numchar);
    int k=strlen(numchar);
    char renumchar[100]="";
    reverse_char(numchar,renumchar,k);
    int count = 0;
    for(int i=0;i<k;i++)
    {
        if(numchar[i]==renumchar[i]) count++;
    }
    if(count==k) return true;
    else return false;
    }
```