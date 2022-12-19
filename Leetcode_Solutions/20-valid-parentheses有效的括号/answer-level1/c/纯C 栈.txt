```
bool isValid(char * s){
    int cStackLength = strlen(s);

    if(0 == cStackLength)
    {
        return true;
    }

    if(1 == cStackLength)
    {
        return false;
    }

    char* cStack = (char*)malloc(sizeof(char) * cStackLength);
    int top = -1;
    int uIndex = 0;

    for(uIndex = 0; uIndex <= (cStackLength - 1); uIndex++)
    {
        if( ')' == *(s + uIndex) )
        {
            if( (-1 < top) && ('(' == *(cStack + top)) ) // peek
            {
                top--; // pop
            }
            else
            {
                free(cStack);
                return false;
            }
        }
        else if( ']' == *(s + uIndex) )
        {
            if( (-1 < top) && ('[' == *(cStack + top)) ) // peek
            {
                top--; // pop
            }
            else
            {
                free(cStack);
                return false;
            }
        }
        else if( '}' == *(s + uIndex) )
        {
            if( (-1 < top) && ('{' == *(cStack + top)) ) // peek
            {
                top--; // pop
            }
            else
            {
                free(cStack);
                return false;
            }
        }
        else // '(' 、 '[' 、'{'
        {
            cStack[++top] = s[uIndex]; // push
        }
    }

    free(cStack);

    if( -1 < top )
    {
        return false;
    }

    return true;
}

```
