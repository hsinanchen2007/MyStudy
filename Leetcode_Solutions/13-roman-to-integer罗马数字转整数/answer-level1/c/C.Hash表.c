### 解题思路
1.建立Hash表a，I对应a['I']=1，V对应a['V']=5，IV对应a['I'+'V']=4，以此类推
2.双符号(IV,IX等)判断
   (1) a[s[i]]>a[s[i-1]] (此项是要保证I在V左边，其他同理）
   (2) a[s[i]+s[i-1]]不为0  (此项用于判断是否为IV IX......)
3.满足以上两项就直接sum+=a[s[i]+s[i-1]]
4.否则就直接sum+=a[s[i]]

### 代码

```c
int romanToInt(char * s){
   int len=strlen(s);
   int sum=0;
   int a[200];
   for(int i=0;i<200;i++)a[i]=0;
   a['I']=1;
   a['V']=5;
   a['X']=10;
   a['L']=50;
   a['C']=100;
   a['D']=500;
   a['M']=1000;
   a['I'+'V']=4;
   a['I'+'X']=9;
   a['X'+'L']=40;
   a['X'+'C']=90;
   a['C'+'D']=400;
   a['C'+'M']=900;
    for(int i=len-1;i>=0;i--){
       if(i-1>=0&&a[s[i]]>a[s[i-1]]&&a[s[i]+s[i-1]]!=0) {
         sum+=a[s[i]+s[i-1]];
         i--;
       }
       else sum+=a[s[i]];
   }
return sum;
}











```