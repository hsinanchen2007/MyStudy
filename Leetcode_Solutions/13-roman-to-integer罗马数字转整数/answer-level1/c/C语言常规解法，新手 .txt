computecompute获取对应的值，然后比较该字符与后一个字符，若前大于后则直接计算两个的值，i多+1，否则正常加上

int compute(char a){
    int sum=0;
    switch(a){
        case 'I':  sum=1;  break;
        case 'V':  sum=5;  break;
        case 'X':  sum=10;  break;
        case 'L':  sum=50;  break;
        case 'C':  sum=100;  break;
        case 'D':  sum=500;  break;
        case 'M':  sum=1000;  break;
    }
    return sum;
}
int romanToInt(char * s){
    int i =0,left=0,right=0,count=0;
    while(*(s+i)!='\0'){
       left=compute(*(s+i));
       if(*(s+i+1)!='\0')
        right=compute(*(s+i+1));
       else 
        right=0;
       if(left>=right)
            count+=left;
        else {
            count+=(right-left);
            i++;
        }
        i++;
    }
    return count;
}