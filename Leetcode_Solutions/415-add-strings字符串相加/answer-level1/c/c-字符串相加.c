### 解题思路
此处撰写解题思路

### 代码

```c
char * addStrings(char * num1, char * num2){
int l1=strlen(num1),l2=strlen(num2);
int l=l1>l2?l1:l2,a,k,i=l1-1,j=l2-1;
char *ret=(char *)malloc(sizeof(char )*(l+10));
int lo=l;
//从l开始放，ret[0]先空着
for(k=0;k<=l;k++)ret[k]='0';
while(i>=0&&j>=0){
    a=(num1[i--]-'0')+(num2[j--]-'0')+(ret[l]-'0');
    ret[l]=(a%10)+'0';
    ret[l-1]=(a/10)+'0';
    l--;
}
while(i>=0){
    a=(num1[i--]-'0')+(ret[l]-'0');
     ret[l]=(a%10)+'0';
    ret[l-1]=(a/10)+'0';
    l--;
}
while(j>=0){
    a=(num2[j--]-'0')+(ret[l]-'0');
    ret[l]=(a%10)+'0';
    ret[l-1]=(a/10)+'0';
    l--;
}
ret[lo+1]='\0';
if(ret[0]=='0')return ret+1;
return ret;
}

```