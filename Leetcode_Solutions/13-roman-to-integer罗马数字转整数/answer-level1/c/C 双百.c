### 解题思路
如下

### 代码

```c
int romanToInt(char * s){
    int ans=0,store=0,i=0;
    char c=s[i];
    while(c!='\0'){
        switch(c){
            case 'M':if(store<1000) ans-=store;else ans+=store;store=1000;break;
            case 'D':if(store<500) ans-=store;else ans+=store;store=500;break;
            case 'C':if(store<100) ans-=store;else ans+=store;store=100;break;
            case 'L':if(store<50) ans-=store;else ans+=store;store=50;break;
            case 'X':if(store<10) ans-=store;else ans+=store;store=10;break;
            case 'V':if(store<5) ans-=store;else ans+=store;store=5;break;
            case 'I':if(store<1) ans-=store;else ans+=store;store=1;
        }
        c=s[++i];
    }
    ans+=store;
    return ans;
}
```