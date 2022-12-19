
    public String convertToBase7(int num) {
        StringBuilder  res = new StringBuilder();
        if(num==0)
            return 0+"";
        int temp=Math.abs(num);
        while(temp!=0)    //一直除以7取余数加入到res中
        {
            int yushu = temp%7;
            res.append(yushu);
            temp=temp/7;
        }
        return num>=0?res.reverse().toString():res.append('-').reverse().toString();    %最后判断符号然后逆序得到结果
