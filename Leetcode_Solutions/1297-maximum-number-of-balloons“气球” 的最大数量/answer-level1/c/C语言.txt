

int maxNumberOfBalloons(char * text){
    char *arr;
    arr = "balon";
    int tag[5]={0};
    int i;
    char *p = text;

    while(*p!=0)
    {   

        for (i=0; i<5 ; i++)
        {
            if (*(arr+i)==*p)
            {
                tag[i]++; 
            }
        }
        p++;
    }
    int temp = tag[0];
    for (i=0; i<5 ;i++)
    {
        if (temp>tag[i])
        {
            temp = tag[i]; 
        }
    }
    if (temp == 0)
        return 0;

    int temp1=tag[2];
    if (tag[2] > tag[3])
        temp1 = tag[3];
    if (temp1/temp >=2)
        return temp;
    return temp1/2;

}