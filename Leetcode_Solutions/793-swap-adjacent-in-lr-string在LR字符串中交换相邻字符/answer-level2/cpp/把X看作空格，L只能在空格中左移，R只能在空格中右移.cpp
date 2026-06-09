执行用时 :O(n)
12 ms, 在所有 C++ 提交中击败了79.78%的用户

内存消耗 :O(1)
9.7 MB, 在所有 C++ 提交中击败了97.78的用户

原理：在start中，L只能向左移动，R只能向右移动，只有在遇到X的时候可以移动
因此X相当于是个空格，遇到空格L可以向左移动，R可以向右移动，其他情况不能移动

判定start能否转为end,即

（1）都去除X后，start和end一致

（2）如果L配对成功还需满足 start的下标大于等于 end的下标

如果R配对成功还需满足 start的下标小于等于 end的下标


    bool canTransform(string start, string end) {
       
        int n1=start.size();
        int n2=end.size();
        //数量不等和都为1的情况
        if(n1!=n2)
            return false;
        if(n1<2)
            return start==end;
        
        //两者的L和R是否对应相等
        int c=0;
        int d=0;
        for(int i=0;i<n1;i++){
           if(start[i]=='L')
               c++;
           if((start[i]=='R'))
               d++;
        }
        int a=0;
        int b=0;
        for(int i=0;i<n1;i++){
            if(end[i]=='L')
                a++;
            if(end[i]=='R')
                b++;
        }
        if(a!=c || b!=d)
            return false;
        //对应L和R是否可以通过移动匹配
        int i=0;
        int j=0;
        while(i<n1 && j<n1){
            
            if(end[j]==start[i]){
                if(end[j]=='L' && i<j)
                    return false;
                if(end[j]=='R'&& i>j)
                    return false;
                i++;
                j++;
            }
            else if(end[j]=='X'){
                j++;
            }
            else if(start[i]=='X'){
                i++;
            }
            else
                return false;
        }
        return true;
    }
