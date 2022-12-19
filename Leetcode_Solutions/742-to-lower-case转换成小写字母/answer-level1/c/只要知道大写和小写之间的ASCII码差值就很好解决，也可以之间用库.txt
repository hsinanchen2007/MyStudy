char * toLowerCase(char * str)
{
    char* cur = str;
    while(*cur)
    {
        if(*cur >= 65 && *cur <= 90)
            *cur = *cur + 32;
          ++cur;
    }
   return str;
}