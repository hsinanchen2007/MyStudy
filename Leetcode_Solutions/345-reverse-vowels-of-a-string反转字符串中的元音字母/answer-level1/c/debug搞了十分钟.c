### 解题思路
此处撰写解题思路

### 代码

```c
char * reverseVowels(char * s){
    if(s==NULL) return s;
    int len=strlen(s);
    int left=0, right=len-1, flagl, flagr;
    char temp;
    while(1){
        flagl=0;
        flagr=0;
        for(left;left<right;left++){
            if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u'||s[left]=='A'||s[left]=='E'||s[left]=='I'||s[left]=='O'||s[left]=='U'){
                flagl=1;
                break;
            }
        }
        for(right;right>left;right--){
            if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u'||s[right]=='A'||s[right]=='E'||s[right]=='I'||s[right]=='O'||s[right]=='U'){
                flagr=1;
                break;
            }
        }
        
        if(flagr==1 && flagl==1){
            temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            right--;
            left++;
        }
        else break;
    }
    return s;
}
```