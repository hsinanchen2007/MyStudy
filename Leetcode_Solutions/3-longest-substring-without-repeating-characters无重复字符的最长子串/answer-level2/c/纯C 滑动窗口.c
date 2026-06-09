纯C
```
int lengthOfLongestSubstring(char * s){
    int maxValue = 0; // the max length of substring, to return
    int tempMaxValue = 0; // temp length 

    /* use sliding window */
    int slidingWindowHead = 0; 
    int slidingWindowRear = 0;
    int slidingWindowQueue[128] = {0}; // ASCII of X86

    int length = strlen(s);

    if(length == 0)
    {
        return 0; // null string
    }

    while(slidingWindowHead <= (length - 1))
    {
        if(slidingWindowQueue[ s[slidingWindowHead] ] != 0) // find the same char
        {
            if(slidingWindowQueue[ s[slidingWindowHead] ] > slidingWindowRear) // ignore outer substring 
            {
                slidingWindowRear = slidingWindowQueue[ s[slidingWindowHead] ]; // refresh rear of sliding window
            }
        }

        tempMaxValue = slidingWindowHead - slidingWindowRear + 1; // equal to sliding window length

        if(tempMaxValue > maxValue) // refresh max length
        {
            maxValue = tempMaxValue;
        }

        slidingWindowQueue[ s[slidingWindowHead] ] = slidingWindowHead + 1; // store the [string char <-> position] in queue
        slidingWindowHead++;
    }

    return maxValue;
}
```
