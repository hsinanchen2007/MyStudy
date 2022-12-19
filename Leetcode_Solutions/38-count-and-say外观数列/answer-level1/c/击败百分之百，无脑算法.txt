### 解题思路
每一次求解，将外观数列从头到尾遍历，记录某个数字连续出现的次数，
将次数和这个数字一并存入字符串t中。
### 代码

```c
char * countAndSay(int n){
    char *s = (char*)malloc(sizeof(char)*5000);
	s[0] = '1';
    s[1] = '\0';
    for(int j = 2;j <= n;j++){
        char *t = (char*)malloc(sizeof(char)*5000);
        int needle = 0,i = 0;
        while(s[i] != '\0'){
            int cnt = 1;
            while(s[i] == s[i+1]){
                cnt++;
                i++;
            }
            t[needle++] = cnt+'0';
            t[needle++] = s[i];
            i++; 
        }
        t[needle] = '\0';
        strcpy(s,t);
    }
    return s;
}
```