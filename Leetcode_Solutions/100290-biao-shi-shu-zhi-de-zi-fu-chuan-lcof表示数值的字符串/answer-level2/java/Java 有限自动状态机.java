![AKF扩展立方体.jpg](https://pic.leetcode-cn.com/e72e3c0842a19eda472dd4569a041801f0e7c26d01fc1b54c726ad85b1ef6ef7-AKF%E6%89%A9%E5%B1%95%E7%AB%8B%E6%96%B9%E4%BD%93.jpg)

```
class Solution {
    public boolean isNumber(String s) {
        //初始状态
        int state = 0;
        
        //去除前后的空格
        int start = 0,end = s.length()-1;;
        while(start<=end &&  s.charAt(start) == ' '){
            start++;
        }
        while(start<=end && s.charAt(end) == ' '){
            end--;
        }
        s = s.substring(start,end+1);
        if(s.length() == 0){
            return false;
        }
        
        
        for(int i= 0 ; i<s.length() ; i++){
            char c = s.charAt(i);
            if(c == ' ' ){
                return false;
            }
            switch(state){
                case 0:{
                    if(c == '+' || c == '-'){
                        state = 1;
                    }else if(c>='0' && c<='9'){
                        state = 2;
                    }else if(c == '.'){
                        state = 7; 
                    }else{
                        return false;
                    }
                    break;
                }
               case 1:{
                    if(c>='0' && c<='9'){
                        state = 2;
                    }else if(c == '.'){
                        state = 7;
                    }else{
                        return false;
                    }
                    break;
                }     
               case 2:{
                   if(c>='0' && c<='9'){
                        
                    }else if(c == '.'){
                        state = 4;
                    }else if(c == 'e'){
                        state = 3;
                    }else{
                        return false;
                    }
                    break;
                }     
               case 3:{
                    if(c == '+' || c == '-'){
                        state = 6;
                    }else if(c>='0' && c<='9'){
                        state = 5;
                    }else{
                        return false;
                    }                    
                    break;
                }
               case 4:{
                    if(c>='0' && c<='9'){
                    }else if(c == 'e'){
                        state =3;
                    }else{
                        return false;
                    }
                    break;
                }      
               case 5:{
                    if(c>='0' && c<='9'){
                    }else{
                        return false;
                    }                    
                    break;
                }
               case 6:{
                    if(c>='0' && c<='9'){
                        state = 5;
                    }else{
                        return false;
                    }                          
                    break;
                }
                case 7:{
                    if(c>='0' && c<='9'){
                        state = 4;
                    }else{
                        return false;
                    }                          
                    break;
                }
               default: break;            
            }
        }
        //红色的三个是合法终止状态
        if(state == 2 || state == 4 || state == 5){
            return true;
        }else{
            return false;
        }
    }
}
```
