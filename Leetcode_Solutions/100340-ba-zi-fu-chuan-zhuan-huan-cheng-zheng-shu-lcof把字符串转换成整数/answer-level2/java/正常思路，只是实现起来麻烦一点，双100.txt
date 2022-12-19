```
class Solution {
    public int strToInt(String str) {
        int len=str.length();
        char sign='+';
        char ch;
        int sum=0;
        int count_sign=0;
        for(int i=0;i<len;i++){
            ch=str.charAt(i);
            if(count_sign==1&&(ch<'0'||ch>'9'))return 0;//如果出现符号之后没出现数字，则返回0
            if(ch==' ')continue;
            if(ch=='+'){
                count_sign++;
                sign='+';
                continue;
            }
            if(ch=='-'){
                count_sign++;
                sign='-';
                continue;
            }
            //if(count_sign>1)return 0;//
            
            if('0'<=ch&&ch<='9'){
                sum+=(str.charAt(i)-'0');
                for(int j=i+1;j<len;j++){
                    int temp=str.charAt(j)-'0';
                    if(0<=temp&&temp<=9){
                        //判断是否溢出
                        if(sign=='+'){//若为正，判断是否溢出
                            if((sum<214748364)||(sum==214748364&&temp<=7)){
                                sum=sum*10+temp;
                            }else{
                                return Integer.MAX_VALUE;
                                //return sum;
                            }
                        }else{//若为负，判断是否溢出
                            if((sum<214748364)||(sum==214748364&&temp<=8)){
                                sum=sum*10+temp;
                            }else{
                                return Integer.MIN_VALUE;
                            }
                        }
                    }else{
                        break;
                    }
                }
                break;
            }
            if(ch<'0'||ch>'9') return 0;
        }
        if(sign=='-')return -sum;
        return sum;
    }
}
```
