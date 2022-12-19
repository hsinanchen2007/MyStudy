bool isSubsequence(char * s, char * t){
    int i,j=0,m=0;
    int p[105];
    memset(p,-1,105*sizeof(int));//p[105]={-1};错误 
    for(i=0;s[i]!='\0';i++)
    {
        for(j=j;t[j]!='\0';j++)
        {
            if(t[j]==s[i]){
              p[i]=j;//存储位置
                t[j]='1';//避免重复查找
                break;
            } 
        }
        if(p[i]==-1) return false;//没找到一个字符直接false
    }
    while(p[m]!=-1&&p[m+1]!=-1)
     {
      if(p[m]>p[m+1]) return false;//即使全部找到前后顺序不同 false   
      m++;
     }
    return true;
}