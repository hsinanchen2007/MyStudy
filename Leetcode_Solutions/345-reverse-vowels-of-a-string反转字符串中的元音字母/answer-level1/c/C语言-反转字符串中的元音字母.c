### 解题思路
双指针法

### 代码

```c
int judge(char t){
    if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u')return 1;
     if(t=='A'||t=='E'||t=='I'||t=='O'||t=='U')return 1;
    return 0;
}

char * reverseVowels(char * s){
 int i=0,j=strlen(s)-1;
 while(i<j){
     while(i<strlen(s)&&judge(s[i])==0)i++;
     while(j>=0&&judge(s[j])==0)j--;
     if(i<j){
         char temp;
         temp=s[i];
         s[i]=s[j];
         s[j]=temp;
         i++;
         j--;
     }
 }
return s;
}
```