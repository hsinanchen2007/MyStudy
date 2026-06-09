### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> restoreIpAddresses(String s) {
        int i0,i1,i2,i3;
        String s0="",s1="",s2="",s3="";
        List<String> lis = new ArrayList<>();
        for(i0=1;i0<4;i0++){
            for(i1=1;i1<4;i1++){
                for(i2=1;i2<4;i2++){
                    for(i3=1;i3<4;i3++){
                        if(i0+i1+i2+i3==s.length()){
                            s0=s.substring(0,i0);
                            s1=s.substring(i0,i0+i1);
                            s2=s.substring(i0+i1,i0+i1+i2);
                            s3=s.substring(i0+i1+i2,i0+i1+i2+i3);
                            if(valid(s0) && valid(s1) && valid(s2) && valid(s3)){
                                lis.add(s0+"."+s1+"."+s2+"."+s3);
                            }
                            break;
                        }
                    }
                }
            }
        }
        return lis ;
    }
    
    public boolean valid(String segment) {
    int m = segment.length();
    if (m > 3)
      return false;
    return (segment.charAt(0) != '0') ? (Integer.valueOf(segment) <= 255) : (m == 1);
  }

}
```