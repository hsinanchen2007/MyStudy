```

        int length = s.length();
        int x = 0;
        for (int i=0; i<length;i++){
            if(s.charAt(i) == 'I'){
                if((length-i)>1 && s.charAt(i+1) == 'X'){
                    x+=9;
                    i++;
                    continue;
                }else if((length-i)>1 && s.charAt(i+1) == 'V'){
                    x+=4;
                    i++;
                    continue;
                }else {
                    x+=1;
                    continue;
                }
            }
            if(s.charAt(i) == 'V'){
                x+=5;
                continue;
            }
            if(s.charAt(i) == 'X'){
                if((length-i)>1 && s.charAt(i+1) == 'L'){
                    x+=40;
                    i++;
                    continue;
                }else if((length-i)>1 && s.charAt(i+1) == 'C'){
                    x+=90;
                    i++;
                    continue;
                }else {
                    x+=10;
                    continue;
                }
            }
            if(s.charAt(i) == 'L'){
                x+=50;
                continue;
            }
            if(s.charAt(i) == 'C'){
                if((length-i)>1 && s.charAt(i+1) == 'D'){
                    x+=400;
                    i++;
                    continue;
                }else if((length-i)>1 && s.charAt(i+1) == 'M'){
                    x+=900;
                    i++;
                    continue;
                }else {
                    x+=100;
                    continue;
                }
            }
            if(s.charAt(i) == 'D'){
                x+=500;
                continue;
            }
            if(s.charAt(i) == 'M'){
                x+=1000;
                continue;
            }
        }
        return x;
```
