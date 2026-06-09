```
char * countAndSay(int n){
    if(n==1) return "1";
    char temp[31][10000]={'\0'};
    temp[1][0]='1';
    for(int i=2;i<=n;i++){
        int j,pos=0;
        for(j=0;temp[i-1][j]!='\0';){
            int cnt=1,k;
            while(temp[i-1][j++]==temp[i-1][j]) cnt++;
            temp[i][pos++]='0'+cnt;
            temp[i][pos++]=temp[i-1][j-1];
        }
    }
    char *out=temp[n];
    return out;
}
```
（菜鸡）贴这个代码的最大原因在于：！！！！
第三行设置二维数组的时候temp[31][?] 我从500设置到了8k，其中29个过了，最后提到1w才过了最后一个测试点。
而且返回值也是一个痛，8说了，都是泪。
问题这样的空间使用也才50%，不知道其他大神空间使用得多狠。