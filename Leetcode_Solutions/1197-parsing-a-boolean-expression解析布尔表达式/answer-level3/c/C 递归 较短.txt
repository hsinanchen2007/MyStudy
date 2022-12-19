```


bool isOP(char c)
{
    return c == '|' || c == '!' || c == '&';
}

bool getBool(char c)
{
    if(c == 't') return 1;
    return 0;
}

bool parseBoolExpr(char *expression){

    char *cur = expression;

    char op = *cur++;
    char buf[1000];
    memset(buf, 0, 1000);

    while(*cur)
    {
        if(isOP(*cur))
        {   // recursive
            (void)parseBoolExpr(cur);
        }
        else if(*cur == 't' || *cur == 'f')
        {
            buf[strlen(buf)] = *cur++;
        }
        else if(*cur == ')')
        {
            bool ret;

            if(op == '!')
            {
                ret = !getBool(buf[0]);
            }
            else if(op == '&' || op == '|')
            {
                char *curBuf = buf;
                ret = getBool(*curBuf++);

                while(*curBuf)
                {
                    if(op == '&')   ret &= getBool(*curBuf++);
                    else            ret |= getBool(*curBuf++);
                }
            }
            else assert(0);
            
            // modify the origin string with result
            if(ret)     *expression++ = 't';
            else        *expression++ = 'f';

            // fill the rest space with ',' which will be ignored
            while(expression <= cur)
                *expression++ = ',';

            return ret;
        }
        else
        {
            cur++;
        }
    }

    assert(0);
    return 1;
}

```
