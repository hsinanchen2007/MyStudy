![Snipaste_2020-04-08_17-18-16.jpg](https://pic.leetcode-cn.com/8d0e487b46bf9816ed9fb0e202d29a741a75e74f42dc2a42630d00a21a025d44-Snipaste_2020-04-08_17-18-16.jpg)


```
#include <string.h>
char * countAndSay(int n){
    int j,k;
    char std[5000] = {'\0'};
    char s[5000] = {'\0'};
    if(n == 1) return "1";
    if(n == 2) return "11";
    if(n == 3) return "21";
    std[0] = '1';
    std[1] = '1';
    int count;
    while(n-2){
       j = k = 0 ;
        while(std[j] != '\0'){
        	count = 1;
            while(std[j+1] != '\0'&&std[j+1] == std[j]){
            	j++;
            	count++;
			}          
            s[k++] = count+'0';
            s[k++] = std[j];
           j++;
            
        }
        strcpy(std,s);
        std[k] = '\0';
        n--;
    }
    char* st;
    int len = strlen(std);
    st = (char*)malloc(len+1);
    strcpy(st,std);
    st[len] = '\0';
    return st;
}
```
