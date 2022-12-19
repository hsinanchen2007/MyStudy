### 解题思路
分情况讨论：
例如，求百位出现1的数字的个数：
n=10022，那么百位数字为0，要使得百位数字为1并且比n小，那么百位左边的大位的数字
可以是[0,9]，然后百位右边的数字就任取即可，[00,99]都可，所以共10*100=高位*位置
n=10122，那么百位数字为1，要使得百位数字为1并且比n小，那么百位左边的大位的数字
可以是[0,10]，当取[0,9]时，仍然百位右边的数字就任取即可，[00,99]都可，共10*100种
当取10时，百位右边的数字取[00,22]都可，共23种，所以共10*100+23=高位*位置+低位+1
n=10222，那么那么百位数字为2，大于1，要使得百位数字为1并且比n小，那么百位左边的大位的数字
可以是[0,10]，百位右边的数字取[00,99]都可，共11*100=（高位+1）*位置

### 代码

```java
class Solution {
 public int countDigitOne(int n) {
        if(n<0)
            return 0;
        String num=String.valueOf(n);
        int cnt=0;
        //place表示位置，最低位时place=1
        for(int place=1;place<=num.length();place++){
            int p=(int) Math.pow(10,place-1);  //位置
            int cur=num.charAt(num.length()-place)-'0';  //位置上的数字
            int high=0;
            if(place!=num.length())
                high=Integer.parseInt(num.substring(0,num.length()-place));//高位
            int low=0;
            if(place!=1)
                low=Integer.parseInt(num.substring(num.length()+1-place));//低位
//            System.out.println("cur:"+cur);
//            System.out.println("p:"+p);
//            System.out.println("low:"+low);
//            System.out.println("high:"+high);
            if(cur==0){
                cnt+=high*p;
            }
            else if(cur==1){
                cnt+=high*p+low+1;
            }else if(cur>1) {
                cnt+=(high+1)*p;
            }
        }
        return cnt;
    }

}
```