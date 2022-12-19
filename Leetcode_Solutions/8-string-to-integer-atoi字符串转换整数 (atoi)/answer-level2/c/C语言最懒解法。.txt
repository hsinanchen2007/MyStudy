
```
#include <stdio.h>
#include <limits.h>

int myAtoi(char * str){
    long long i = 0;
    int ret = sscanf(str, "%lld", &i);
    if (ret) {
        if (i > INT_MAX)
            i = INT_MAX;
        else if (i < INT_MIN)
            i = INT_MIN;
    }
    return (int)i;
}
```

