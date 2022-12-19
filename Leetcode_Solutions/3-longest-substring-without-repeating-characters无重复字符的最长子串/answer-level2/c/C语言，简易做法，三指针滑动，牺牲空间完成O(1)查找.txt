```
int lengthOfLongestSubstring(char * s){
    int head=0,rear=0,run;
    bool repeat=false;
    int n=strlen(s);
    int count,max=0,hashset[128];
    for(int i=0;i<128;i++) hashset[i]=0;
    while(rear<n) {
        if(hashset[s[rear]%128]==0) hashset[s[rear]%128]=1;
        else repeat=true;
        if(repeat) {
            count=rear-head;
            if(count>max) max=count;
            for(run=head;run<rear;run++) if(s[run]==s[rear]) break;
            for(int i=head;i<run;i++) hashset[s[i]%128]=0;
            head=run+1;
            repeat=false;
        }
        rear++;
    }
    if(head==0) max=n;
    if(rear-head>max) max=rear-head;
    return max;
}
```
