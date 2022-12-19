```
class Solution {
public:   
/*
输入的字符串和原有的字符串进行比对。在相同的左右字符之间，输入字符的重复值必须要大于等于原有字符
*/
    bool isLongPressedName(string name, string typed) {
        int j,g;
        int h=0;
        int temp=1;       
        for( int i =0 ;i< name.size();i++){
           
            j=1;
            g=1;
            //判断该字符在name中是否重复，以及是多少位的重复；
            while(name[i]==name[i+j] && i+j < name.size() ){
                j++;
                              
            }
           
            if(  typed[h]==name[i]  ){
                

                //判断重复量是否相等   
                while(typed[h]==typed[h+g] && h+g < typed.size() ){
                    g++;

                }  

                if(g<j){
                    //name中的重复量>typed 不匹配
                    temp =0;
                    
                    break;

                }
                else{
                    if(g==1){
                        //单个字符相等，无重复。
                        h++;
                        continue;
                    }
                    else{
                        //单个字符，且typed重复量>name,调整name 和typed开始的位置
                        h += g;
                        i += j-1;

                    }
                }
               
                

                
            }
            else{
                temp=0;
               
                break;
            }
        
        
    }
   
    return temp;
    }
    
};
```
![image.png](https://pic.leetcode-cn.com/11bbb44463703430ac4c7955c6d7e5715aeeedb894d82e19ce92b03be9f91329-image.png)
