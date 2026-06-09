**只要当前字母（第ｉ个）的权值大于等于下一个字母（第i+1）的权值，就加上当前字母的权值，否则就减去，最后结果即为所求。**

```c
char roman[7] = "IVXLCDM";
int num[7] = {1, 5, 10, 50, 100, 500, 1000};

inline int map(char c)
{
    for(int i = 0; i < 7; i++){
        if(roman[i] == c)
            return num[i];
    }
    return 0;
}

int romanToInt(char * s){
    int ans = 0;
    int i = 0;
    while(s[i+1] != '\0'){
        if(map(s[i]) >= map(s[i+1])){
            ans += map(s[i]);
        }
        else{
            ans -= map(s[i]);
        }
        i++;
    }
    ans += map(s[i]);
    return ans;
}
```