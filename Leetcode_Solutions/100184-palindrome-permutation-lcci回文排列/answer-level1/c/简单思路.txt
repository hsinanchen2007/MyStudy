### 代码

```c
bool canPermutePalindrome(char* s){
     int chart[255]={0};
     int len=strlen(s);
     int cnt=0;
     for(int i=0;i<len;i++){
          chart[s[i]]++;
     }
     for(int i=0;i<255;i++){
        if(chart[i]%2==0) ;
        else if(chart[i]%2==1) cnt++;
        if(cnt==2) return 0;
     }
     return 1;
}
```