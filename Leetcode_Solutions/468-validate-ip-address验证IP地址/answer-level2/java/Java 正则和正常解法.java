### 解题思路
解一 正则

### 代码

```java
class Solution {
    public String validIPAddress(String IP) {
        if(IP.matches("((2[0-5][0-5]|1[0-9][0-9]|[1-9][0-9]|[0-9])\\.){3}(2[0-5][0-5]|1[0-9][0-9]|[1-9][0-9]|[1-9])")) return "IPv4";
        else if (IP.matches("(([0-9]|[a-f]|[A-F]){1,4}:){7}(([0-9]|[a-f]|[A-F]){1,4})")) return "IPv6"; 
        else return "Neither";
    }
}
```
解二。寻找边界正常解
class Solution {
    public String validIPAddress(String IP) {
        if(IP.startsWith(":") || IP.endsWith(":") || IP.startsWith(".") || IP.endsWith(".")){
            return "Neither";
        }
        String[] array = IP.split("\\.");
        int length = array.length;
        if(length == 4){
            int num = -1;
            for(int i=0;i<4;i++){
                    try{
                        num = Integer.parseInt(array[i]);
                }catch(Exception e){
                    return "Neither";
                }
                if(num<0 || num>255){
                    return "Neither";
                }
                if(array[i].length()>1 &&(array[i].startsWith("0")||array[i].startsWith("-"))){
                    return "Neither";
                }
            }
            return "IPv4";
        }else{
            array = IP.split(":");
            length = array.length;
            if(length ==8){
                int num =-1;
            
            for(int i =0;i<length;i++){
                if(array[i].length()>4||array[i].length()==0 ||array[i]==null){
                    return "Neither";
                }
                for(int j =0;j<array[i].length();j++){
                    char c = array[i].charAt(j);
                    if(!((c>='0'&&c<='9')||(c<='f'&& c>='a')||(c<='F'&&c>='A'))) return "Neither";
                }
            }
            return "IPv6";
            } else return "Neither";
        }
    }
}