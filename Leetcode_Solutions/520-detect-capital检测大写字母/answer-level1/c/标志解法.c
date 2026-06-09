
题目描述中给出了三种情况，那我们就讨论三种情况
1、首先设置两个flag， flag1用来标志是否第一个字母是大写
                    flag2用来标志是否第二个字母是大写
2、首先查看第一个字母是大写还是小写，若为大写字母，记flag1=1
3、如果flag1 == 1 再查看第二个字母是否为大写字母，若是，记flag2 = 1；
4、再继续遍历整个数组，判断每个字母是否符合规定
    如果两个标记都为1，那么之后不允许出现小写字母
    如果第一个字母为1，第二个字母为0，那么之后不允许出现大写字母
    如果第一个字母为0，那么之后也不允许出现大写字母
    （这里可以将后两种情况放在一起判断）


            bool detectCapitalUse(char * word){
                int i = 0;
                int flag1 = 0;
                int flag2 = 0;
                
                while(word[i] != 0){
                    if(i == 0 && word[i] < 'a'){
                        flag1 = 1;
                        i++;
                        continue;
                    }
                        
                    if(flag1 && i == 1 && word[i] < 'a'){
                        flag2 = 1;
                        i++;
                        continue;
                    }
                    
                    //printf("flag1= %d, flag2 = %d\n", flag1, flag2);
                    
                    if(flag1 && flag2){  
                        //要求全部字母大写
                        if(word[i] >= 'a')
                            return false;
                    }else{
                        //仅仅首字母大写
                        if(word[i] < 'a')
                            return false;
                    }  
                    i++;
                }
                
                return true;
            }