c中100%
char * addStrings(char * num1, char * num2){
    int cf=0;
    int l1=0;
    int l2=0;
    int *st;
    char *ret;
    while(num1[l1]!='\0')l1++;
    while(num2[l2]!='\0')l2++;
    l1--;l2--;
    int l = (l1>l2)?l1:l2;
    st = (int*)malloc((l+2)*sizeof(int));
    int index = 0;
    while(l1>=0||l2>=0||cf>0){
        if(l1>=0){
            cf += num1[l1] - '0';
            l1--;
        }
        if(l2>=0){
            cf += num2[l2] - '0';
            l2--;
        }
        st[index]=cf%10;
        index++;
        cf/=10;
    }
    ret = (char*)malloc((index+1)*sizeof(char));
    ret[index]='\0';
    index--;
    int k=0;
    while(index>=0){
        ret[k]=st[index]+'0';
        index--;
        k++;
    }
    return ret;
}