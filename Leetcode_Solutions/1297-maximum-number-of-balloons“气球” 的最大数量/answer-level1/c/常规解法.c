### 解题思路
此处撰写解题思路

### 代码

```c
int maxNumberOfBalloons(char * text){
    int len=strlen(text);
    int sum[26]={0};
    for(int i=0;i<len;i++){
        sum[text[i]-97]++;
    }
    int min=sum[0];
    if(sum[1]<=min) min=sum[1];
    if(sum[11]<=min) min=sum[11];
    if(sum[13]<=min) min=sum[13];
    if(sum[14]<=min) min=sum[14];
    if(min==sum[11]||min==sum[14])  return (min/2);
    if(min==sum[0]||min==sum[1]||min==sum[13]) {
        if(sum[11]>=2*min&&sum[14]>=2*min) return min;
        else if(sum[11]<=sum[14]) return (sum[11]/2);
        else if(sum[14]<=sum[11]) return (sum[14]/2);
    }
    return ;
}
```