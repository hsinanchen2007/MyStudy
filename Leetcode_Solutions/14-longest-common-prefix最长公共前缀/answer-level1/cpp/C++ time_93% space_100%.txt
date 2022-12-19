基本思想是同步指针，实际上就是对每个元素字符串共用一个索引，在这个指针的循环下每次都去循环字符串元素，用索引去访问字符是否同之前的相等，因为节约空间只用一个局部变量就可以了。
然后就是对一些边界条件进行考虑，比如空的vector和vector中有空串，这个可以提前就排除掉。
```
        int len=strs.size(),i=1,min_str_len=10000; 
        string res="";
        if(len==0) return res;
        for(int i=0;i<len;i++){
            if(strs[i].size()<min_str_len) min_str_len=strs[i].size();
        }
        if(min_str_len==0) return res;
        while(i<=min_str_len){
            char tmp;
            tmp=strs[0][i-1];
            for(int j=1;j<len;j++){  
                if(strs[j][i-1]!=tmp) return res;
            }
            res+=tmp;
            i++;
        }
        return res;
```
