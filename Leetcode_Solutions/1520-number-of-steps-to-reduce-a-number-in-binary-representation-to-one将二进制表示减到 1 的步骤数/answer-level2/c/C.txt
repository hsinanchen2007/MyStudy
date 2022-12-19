```
int numSteps(char *s)
{
       int length = strlen(s);
       int mark = 0, num = 0;
       for (int i = length - 1; i >= 0; i--)
       {
              if (i == 0 && s[i] == 49 && mark == 0)
                     num = num;
              else
              {
                     if (mark + s[i] -48 == 1)
                     {
                            mark = 1;
                            num += 2;
                     }
                     else if (mark + s[i] - 48 == 2)
                     {
                            mark = 1;
                            num++; 
                     }
                     else if(mark + s[i] -48 == 0)
                     {
                         mark = 0;
                         num++;
                     }
              }
       }
       return num;
}
```
