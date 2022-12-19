
``````c []
//第一次：4ms 73.13% 5.3M 100%
int longestPalindrome(char * s){
    int alphaCount[52]={};
    int i=0,j=0,maxLength=0;
    while(s[i]!='\0'){
        if(s[i]>='a'){
            alphaCount[26+s[i]-'a']++;
        }else{
            alphaCount[s[i]-'A']++;
        }
        i++;
    }
    for(j=0;j<52;j++){
        if(alphaCount[j]>1){
            maxLength+=alphaCount[j];
            if(alphaCount[j]&1)
                maxLength--;
        }
    }

    if(maxLength<i)
        maxLength++;

    return maxLength;
}

//第二次：4ms 73.13% 5.5M 100%
int longestPalindrome(char * s){
    int alphaCount[52]={};
    int i=0,j=0,maxLength=0;
    while(s[i]!='\0'){
        if(s[i]>='a'){
            alphaCount[26+s[i]-'a']++;
        }else{
            alphaCount[s[i]-'A']++;
        }
        i++;
    }

    for(j=0;j<52;j++){
        maxLength+=alphaCount[j]&(INT_MAX-1);
    }

    if(i>maxLength)
        maxLength++;

    return maxLength;
}

//第三次：0ms 100% 5.5M 100%
int longestPalindrome(char * s){
    int alphaCount[128]={};
    int i=0,j=0,maxLength=0;
    while(s[i]!='\0'){
        alphaCount[s[i]]++;
        i++;
    }

    for(j=0;j<128;j++){
        maxLength+=alphaCount[j]&(INT_MAX-1);
    }

    if(i>maxLength)
        maxLength++;

    return maxLength;
}
``````

