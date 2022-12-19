int numDecodings(char * s){
    int opt[strlen(s)];
    if(strlen(s) == 0){
        return 0;
    }
    char csTmp[4] = "";
    strncpy(csTmp, s, 1);
    if(atoi(csTmp) == 0){
        return 0;
    }
    if(strlen(s) == 1){
        return 1;
    }
    opt[0] = 1;
    
    int iTmp = 0;
    
    strncpy(csTmp, s, 2);
    iTmp = atoi(csTmp);
    if(10 < iTmp && 27 > iTmp && iTmp%10 !=0){  // two 
        opt[1] = 2;
    }
    else if(iTmp%10 ==0 && iTmp > 20) {
        return 0;   //more the 27 , zero 
    }
    else{
        opt[1] = 1;
    }

    for(int i = 2; i < strlen(s); i++){
        strncpy(csTmp, s+i-1, 2);
        iTmp = atoi(csTmp); 

        if(iTmp == 0 || (iTmp%10 ==0 && iTmp > 20)){
            return 0;
        }
        else if(10 < iTmp && 27 > iTmp && iTmp%10 != 0 ){  // two 
            opt[i] = opt[i - 1] + opt[i-2];
        }
        else if(iTmp%10 == 0) {
            opt[i] = opt[i - 2] ;
        }
        else{
            opt[i] = opt[i - 1];
        }
    }
    return opt[strlen(s)-1];
}