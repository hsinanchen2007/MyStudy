题目不难，用Java里面的split和Integer.parseInt()还是很容易解决的。IPv6一开始还想用双参数的parseInt做的，后来发现数字太大，超过了Int的范围，就作罢。现在写感想的时候想想就发现其实用双参数的Long.parseLong()不就好了吗，刚好64位。（改的代码见后面）

做题过程中就是一些细节没考虑到。大框架早早写好了，就是细节部分靠测试用例撞过去的……自己还是考虑各种边界条件考虑少了。 

执行用时 : 3 ms, 在Validate IP Address的Java提交中击败了94.20% 的用户

内存消耗 : 34.1 MB, 在Validate IP Address的Java提交中击败了96.08% 的用户

```java
class Solution {
    public String validIPAddress(String IP) {
        if(IP.startsWith(":")||IP.startsWith(".")
           ||IP.endsWith(":")||IP.endsWith(".")) return "Neither";//防止开头和结尾是“：”和“.”，会扰乱后面split的判断：52 / 79 "2001:0db8:85a3:0:0:8A2E:0370:7334:"
        String[] splitted = IP.split("\\.");
        if(splitted.length==4){
            int num=-1;
            for(int i=0;i<4;i++){
                try{
                    num=Integer.parseInt(splitted[i]);
                }catch(NumberFormatException e){
                    return "Neither";
                }
                if(num<0||num>255) return "Neither";
                if(splitted[i].length()>1
                   &&(splitted[i].startsWith("0")||splitted[i].startsWith("-")))
                    return "Neither";//防止IPv4中的0开头的情况：65 / 79 "01.01.01.01"；还有防止-0的情况：76 / 79 "15.16.-0.1"
            }
            return "IPv4";
        }else{
            splitted = IP.split(":");
            if(splitted.length==8){
                int num=-1;
                for(int i=0;i<8;i++){
                    int len = splitted[i].length();
                    if(splitted[i]==null
                       ||len>4
                       ||len==0) return "Neither";
                    for(int j=0;j<len;j++){
                        char c = splitted[i].charAt(j);
                        if(!((c>='0'&&c<='9')||(c>='a'&&c<='f')||(c>='A'&&c<='F'))) return "Neither";
                    }
                }
                return "IPv6";
            }else return "Neither";
        }
    }
}
```



写感想的时候发现双参数的Long.parseLong()可行就试了一试：

执行用时 : 3 ms, 在Validate IP Address的Java提交中击败了94.20% 的用户

内存消耗 : 34 MB, 在Validate IP Address的Java提交中击败了96.08% 的用户

```java
class Solution {
    public String validIPAddress(String IP) {
        if(IP.startsWith(":")||IP.startsWith(".")
           ||IP.endsWith(":")||IP.endsWith(".")) return "Neither";
        String[] splitted = IP.split("\\.");
        if(splitted.length==4){
            int num=-1;
            for(int i=0;i<4;i++){
                try{
                    num=Integer.parseInt(splitted[i]);
                }catch(NumberFormatException e){
                    return "Neither";
                }
                if(num<0||num>255) return "Neither";
                if(splitted[i].length()>1
                   &&(splitted[i].startsWith("0")||splitted[i].startsWith("-")))
                    return "Neither";
            }
            return "IPv4";
        }else{
            splitted = IP.split(":");
            if(splitted.length==8){
                long num=-1;
                for(int i=0;i<8;i++){
                    if(splitted[i].length()>4||splitted[i].startsWith("-")) return "Neither";
                    try{
                        num=Long.parseLong(splitted[i],16);
                    }catch(NumberFormatException e){
                        return "Neither";
                    }
                    if(num<0) return "Neither";
                }return "IPv6";
            }else return "Neither";
        }
    }
}
```

