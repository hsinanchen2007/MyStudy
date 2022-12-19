    int minAddToMakeValid(char * S){
    int leftCnt = 0, rightCnt = 0, rightConst = 0;
    while(*S)
    {
    if(*S == '(')
    {
    if(rightCnt > rightConst && rightCnt > 0)
    {
    rightCnt--;
    }else{
    leftCnt++;
    }
    }
    if(*S == ')')
    {
    if(leftCnt == 0)
    {
    rightConst++;
    rightCnt++;
    }else{
    leftCnt--;
    }
    }
    S++;
    }
    if(rightConst)
    {
    return (rightConst + leftCnt);
    }else{
    return (rightCnt + leftCnt);
    }
    }