本解法就是简单的用代码将推算的过程模拟出来
```
void cas(int n,char *s1, char *s2, char* s1head, char *s2head);
char * countAndSay(int n){
    char *s1=(char *)calloc(5000,sizeof(char));
    char *s2=(char *)calloc(5000,sizeof(char));
    char* s1head=s1,* s2head=s2;
    s1[0]='1';
    s1[1]='\0';
    if(n==1||n==0){        
        return s1;
    }
    cas(n,s1,s2,s1head,s2head);
    return s1;
}
void cas(int n,char *s1, char *s2, char* s1head, char *s2head){   
    if(n==1){
        return;
    }    
    while(*s1!='\0'){
        char temp=*s1;
        s1++;
        int i=1;
        while(*s1==temp){
          i++;
          s1++;            
        }
        *s2=(i+'0');
        s2++;
        *s2=temp;
        s2++;
    }
    *s2='\0';
    strcpy(s1head,s2head);
    cas(n-1,s1head,s2head,s1head,s2head);
}
```
![image.png](https://pic.leetcode-cn.com/20eb0e3e24c6fc031f709bbb79cd10de99d34fb63ed43f191cb26c1f1d446c40-image.png)
