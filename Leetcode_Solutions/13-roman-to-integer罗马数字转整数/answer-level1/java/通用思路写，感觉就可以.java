### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

   

    private int getValue(char ch){
        if(ch=='V'){ return 5;}
        if(ch=='X'){ return 10;}
        if(ch=='L'){ return 50;}
        if(ch=='C'){ return 100;}
        if(ch=='D'){ return 500;}
        if(ch=='M'){ return 1000;}
        return 0;
    }    

    private int getReduceValue(char ch){
        if(ch=='V'){ return 1;}
        if(ch=='X'){ return 1;}
        if(ch=='L'){ return 10;}
        if(ch=='C'){ return 10;}
        if(ch=='D'){ return 100;}
        if(ch=='M'){ return 100;}
        return 0;
    }    
    public int romanToInt(String s) {
           if(s==null || s.trim().length()==0){return 0;} 
           int sum =0; 
            for(int i=s.length()-1;i >=0;i--){
                char ch = s.charAt(i);
                if(s.charAt(i)=='I'){sum=sum+1;continue;}  
                int value =  getValue(ch);
                if(i >0){
                    char be = s.charAt(i-1);
                   if((be=='I' && (ch=='V' || ch=='X'))
                       ||
                       (be=='X' && (ch=='L' || ch=='C'))
                       ||
                       (be=='C' && (ch=='D' || ch=='M'))
                    ){
                            value -= getReduceValue(ch);
                            i--;
                     }

                }
                sum +=value;
            }
           return sum;
    }
}
```