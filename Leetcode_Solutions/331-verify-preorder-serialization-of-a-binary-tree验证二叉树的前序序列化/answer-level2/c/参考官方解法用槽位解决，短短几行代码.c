```
bool isValidSerialization(char * preorder){
    int len=strlen(preorder),i=0,slot=1;
    if(len==1&&preorder[i]=='#') return true;
    while(i<len)
    {
        slot--;
        if(slot<0) return false; //说明此时已经没有槽位了（如2，#，#，#这种情况）
        if(preorder[i]!='#') slot+=2;
        while(i<len&&preorder[i]!=',') i++;
        i++;
    }
    if(slot==0) return true;
    else return false;
}
```
