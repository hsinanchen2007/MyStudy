### 解题思路
此处撰写解题思路

### 代码
//一奇多偶
```c
int longestPalindrome(char * s){
    short counter[54]={0};//a-z 0b01100001-0b01111010	
                          //A-Z 0b01000001-0b01011010	
//与0b00100000知大小写
    short *lower_counter=counter+26;//大写字母
    while(*s!='\0'){
        if((*s)&0b00100000){//与0b00100000知大小写
            lower_counter[(*s)&0x1f]+=1;//and 0x1f取下标,小写字母1~26
        }else{
            counter[(*s)&0x1f]+=1;//大写字母27~53
        }
    s++;
    }
    int val=0;
    for(int i=1;i<54;i++){
        if(counter[i]&0x01){//遇到一次奇数，则后面的值都将最低比特变零
            for(;i<54;i++){
                val+=(counter[i]&(~1));
            }
            return val+1;//有一个奇可用，所以加一
        }else{
            val+=counter[i];
        }
    }
    return val;//全偶时从这返回

}
```