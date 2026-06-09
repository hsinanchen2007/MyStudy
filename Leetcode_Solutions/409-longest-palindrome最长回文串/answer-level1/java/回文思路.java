### 解题思路
此处撰写解题思路
先将字符串回归char数组，然后再将String s的对应的char数组的元素进行替换为空，然后比较这个字符串前后差值即得到重复个数，一个记录商，一个记录余数，若余数一直为0，则最大元素个数等于商的2倍，如果余数不全为0，则最大元素个数等于商的2倍加1
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        //将字符串回归为最大回文字符串
        //先将字符串转为char数组，在存入set集合
        char[] c=s.toCharArray();
        String s1=s.replace(String.valueOf(c[0]),"");
        int count=(s.length()-s1.length())/2;
        int cc=(s.length()-s1.length())%2;
        if(s1.length()==0){
            return s.length();
        }
        for(int i=1;i<s.length();i++) {
            int oldlength=s1.length();
            s1 = s1.replace(String.valueOf(c[i]), "");
            count += (oldlength-s1.length())/2;
            cc+=(oldlength-s1.length())%2;
            if(s1.length()==0){
                break;
            }
        }
        if(cc==0){
            return count*2;
        }
        return count*2+1;
    }
}
```