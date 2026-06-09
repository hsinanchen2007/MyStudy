```
bool checkInclusion(char * s1, char * s2){
    int len1=strlen(s1);
    int len2=strlen(s2);
    int flag[26]={0};
    for(int i=0;i<len1;i++){
        int idx=s1[i]-'a';
        flag[idx]++;
    }
    int start=0,end=0;
    int count[26]={0};
    int find=0;
    while(end<len2){
        int idx=s2[end]-'a';
        if(flag[idx]){
            count[idx]++;
            end++;
            while(count[idx]>flag[idx]){//去重，"hello"  "ooolleoooleh"，需要连续去重
                count[s2[start]-'a']--;
                start++;
            }
            if(end-start==len1){
                return true;
            }
        }else{
            memset(count,0,26*4);//只要出现一次不符合，count就重新计数。
            end++;
            start=end;//不符合的情况下，end应该等于start
        }
    }
    return false;
}
```
