    public boolean isOneBitCharacter(int[] bits) {
        int i=0;
        for(;i<bits.length-1;)
        {
            if(bits[i]==0)
               i++;
            else 
               i+=2;
        }
        if(i>=bits.length )  //如果最后两位为一个字符，那么倒数第二位必为1，此时i+=2；数组越界。
           return false;
        else              
           return true;
    }