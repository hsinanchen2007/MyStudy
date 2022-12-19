   int i;
    int num=strlen(moves);
    bool judge;
    int R=0,L=0,U=0,D=0;
    for(i=0;i<num;i++）
    {
        if(moves[i]=='R') R+=1;
        else if(moves[i]=='L') L+=1;
        else if(moves[i]=='U') U+=1;
        else D+=1;
    }
    
    if(R==L&&U==D)
        judge=true;
    else judge=false;
    
    return judge;