```cpp
   string gcdOfStrings(string str1, string str2) {
        string res;
        if(str1.empty()||str2.empty()) return res;
        int leng1=str1.size();
        int leng2=str2.size();
        int index;
        for(int i=0;i<leng1&&i<leng2;++i){
            if(str1[i]!=str2[i]){
                index=i-1;
                break;
            }
            index=i;
        }
        if(index==-1) return res;
        bool flag1=true;
        bool flag2=true;
        while(!flag1||!flag2||index>0){
            flag1=true;
            flag2=true;
            for(;index!=-1&&(leng1%(index+1)!=0||leng2%(index+1)!=0);--index);
            if(index==-1) return res;
            for(int i=index+1;i<leng1;++i){
                if(str1[i]!=str1[i%(index+1)]){
                    flag1=false;
                    --index;
                    break;
                }
            }
            if(flag1){
                for(int i=index+1;i<leng2;++i){
                    if(str2[i]!=str2[i%(index+1)]){
                        flag2=false;
                        --index;
                        break;
                    }
                }
            }
            if(flag1&&flag2) return str1.substr(0,index+1);
        }
        return res;
    }
```
