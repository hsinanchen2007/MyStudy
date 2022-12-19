### 解题思路
从头到尾提取字符，从0开始设置子串的开头位置,遇到重复的就把头设置到之前头位置的下一个。每次提取字符都和子串中所有字符重新进行比较。


执行时间很波动,最好的时候只要4ms 一般8ms,最坏估计20ms,内存消耗5.5=4mb左右.
### 代码

```c
int lengthOfLongestSubstring(char * s){
            int NoRepeatNumber,MaxSubstringLength=0,SubStringFront=0,flag=0;   
                                        //NoRepeatNumber为当前子串长度
                                        //MaxSubstringLength为最大子串长度
                                        //SubStringFront为字串开头位置
                                        //flag用来记录当前字符串长度是否有效,0为有效
            char AtPresentChar;         //用来存储当前提取出的字符
            for(int i=0;s[i]!='\0';i++){
                AtPresentChar=s[i];
                NoRepeatNumber=i-SubStringFront+1;
                for(int j=i-1;j>=SubStringFront;j--){
                    if(AtPresentChar==s[j]){
                        NoRepeatNumber=1;
                        SubStringFront=j+1;
                        flag=1;
                        break;
                    }
                    else
                        flag=0; 
                }
                if(flag==0)
                    MaxSubstringLength=MaxSubstringLength>NoRepeatNumber?MaxSubstringLength:NoRepeatNumber;
            }
            return MaxSubstringLength;
}
```