        
![$0RKSM)703(4MO``01H5@2Q.png](https://pic.leetcode-cn.com/1fe3413ab719949e1d5bfb38f8e30e89ee6201db90472e9ebf73f77f825eb1f6-$0RKSM\)703\(4MO%60%6001H5@2Q.png)

    //思路就是，通过split拆分字符串，然后找出所有的出错情况，剩下的就是答案
    public  String validIPAddress(String IP) {
        //判断长度，过滤
        if(IP == null || IP.length() == 0 ||IP.length() > 39){
            return "Neither";
        }
        //判断，防止split最后的符号影响length
        if(IP.endsWith(":")||IP.endsWith(".")) {
            return "Neither";
        }
        String[] fourArr = IP.split("\\.");
        if(4 == fourArr.length){
            for(int i=0;i<4;i++){
                char[] chars = fourArr[i].toCharArray();
                int sum = 0 ;
                if(chars.length>3){
                    return "Neither";
                }
                for(int j = 0;j<chars.length;j++){
                    //判断单个字符是否在[0-9]区间内，第一个字母是否为0
                    if(chars[j]<48 || chars[j] >57 || (0==j && 48==chars[j] && chars.length>1)){
                        return "Neither";
                    }
                    //取代Integer.parseInt()，但是并没提升性能...
                    int x = 100;
                    switch (j){
                        case 1:x=10;break;
                        case 2:x =1;break;
                        default:break;
                    }
                    sum  = sum + (chars[j]-48)*x;
                }
                //判断每个分隔符中间的值是否在[0-255]内
                if(sum<0 || sum>255 ){
                    return "Neither";
                }
            }
            return "IPv4";
        }else{
            String[] ipSixArr = IP.split(":");
            if(8 == ipSixArr.length){
                for(int i=0;i<8;i++){
                    char[] chars = ipSixArr[i].toCharArray();
                    //判断每个分隔符中间字符个数
                    if(chars.length < 1 || chars.length>4){
                        return "Neither";
                    }
                    //判断分隔符中间的字符如果只有一个，那么只能存在0或者f或者F（最后面大写的F的判断不写也能通过）
                    if(chars.length == 1 && (chars[0] !=48 && chars[0] != 102 && chars[0] != 70)){
                        return "Neither";
                    }
                    //判断字符是否在[0-9] [a-f] [A-F]区间内
                    for(int j = 0;j<chars.length;j++){
                        if( chars[j]<48 ||(chars[j] >57  && chars[j]<65) || (chars[j] > 70 && chars[j] <97) || chars[j] >102 ){
                            return "Neither";
                        }
                    }
                }
                return "IPv6";
            }else{
                return "Neither";
            }
        }
    }