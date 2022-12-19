
想了蛮久的，错了两次，第三次才做对


```c
int romanToInt(char * s)
{
    int integer=0, i;
    for ( i=0; ; i++)
    {
        if (s[i]=='\0')
        {
            break;
        }
        if (s[i]=='I')
        {
            if (s[i+1]=='V')
            {
                integer+=4;
                i++;
                continue;
            }
            else if (s[i+1]=='X')
            {
                integer+=9;
                i++;
                continue;
            }
            else
            {
                integer+=1;
            }
        }
        if (s[i]=='V')
        {
            integer+=5;
        }
        if (s[i]=='X')
        {
            if (s[i+1]=='L')
            {
                integer+=40;
                i++;
                continue;
            }
            else if (s[i+1]=='C')
            {
                integer+=90;
                i++;
                continue;
            }
            else
            {
                integer+=10;
            }
        }
        if (s[i]=='L')
        {
            integer+=50;
        }
        if (s[i]=='C')
        {
            if (s[i+1]=='D')
            {
                integer+=400;
                i++;
                continue;
            }
            else if (s[i+1]=='M')
            {
                integer+=900;
                i++;
                continue;
            }
            else
            {
                integer+=100;
            }
        }
        if (s[i]=='D')
        {
            integer+=500;
        }
        if (s[i]=='M')
        {
            integer+=1000;
        }
    }
    return integer;
}
```