
    unsigned char temp;
    unsigned int i = 0,j = 0,k = 0,repeat_time=0;
    char *t;
    char *cont = (char *)malloc(sizeof(char)*4500);
    char *say = (char *)malloc(sizeof(char)*4500);
    cont[0] = say[0] = '1';
    cont[1] = say[1] = '\0';

    for ( i = 1; i < n; i++)
    {
        k = 0;
        j = 0;
        t=cont;cont=say;say=t;
        temp = cont[j];
         while (temp!='\0')
        {
            if(temp==cont[j])
            {
                 j++;
                 repeat_time++;
            }
            else
            {
                say[k]='0'+repeat_time;
                say[k+1]=temp;
                k+=2;
                repeat_time=0;
                temp=cont[j];
            }
        }
        say[k]='\0';
    }
    if (strlen(cont)>strlen(say))
        return cont;
    else
        return say;
      
}

