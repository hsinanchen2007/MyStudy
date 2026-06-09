【思路】由于字母只为大写字母，我们用二维map记录当前字母在所有排位中出现的投票数，这里的一次排位长度就是团队数。再按照题给排序规则排序。
排位从前往后比较[1,2,…26]，由于字母都是不同的且都是大写字母，所以最多团队数目为26，我们最多比较26次排位。
- 如果第K排位中，A比B票数要多，那么A排在前面；B比A票数要多，那么B排在前面
- 如果第K次排位，A与B票数一样多，继续比较第K+1次排位的投票数情况
- 如果在所有排位中两者投票数都一样，那么直接按照团队名字母大小排序

```C
char * rankTeams(char ** votes, int votesSize){
    int i,j,k,top=0;
    int map[26][26];
    if(votes==NULL)return NULL;
    if(votesSize==0)return NULL;
    char *tmp=(char*)malloc(sizeof(char)*27),*tp;
    memset(map,0,sizeof(map));
    for(i=0;i<votesSize;i++){
        for(j=0;j<strlen(votes[i]);j++){
            map[votes[i][j]-'A'][j]++;//记录字母votes[i][j]的第j排位投票数
            if(i==0){
                tmp[top]=votes[i][j];top++;
            }
        }
    }
//tmp记录所有的团队，由于每一组投票都会出现一次，我们取一组即可，例如["ABC","ACB","ABC","ACB","ACB"]，我们记录tmp="ABC";至于最终排名按照map中记录的投票情况来
    tmp[top]='\0';
    int len=strlen(tmp);
    //排序
    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
            for(k=0;k<26;k++){
                if(map[tmp[i]-'A'][k]<map[tmp[j]-'A'][k]){
                    tp=tmp[i];
                    tmp[i]=tmp[j];
                    tmp[j]=tp;
                    break;
                }else if(map[tmp[i]-'A'][k]==map[tmp[j]-'A'][k]){
                    continue;
                }else
                {
                    break;
                }
            }
            if(k==26){
                if((tmp[i]-'A')>tmp[j]-'A'){
                    tp=tmp[i];
                    tmp[i]=tmp[j];
                    tmp[j]=tp;
                }
            }
        }
    }
    return tmp;
}
```
