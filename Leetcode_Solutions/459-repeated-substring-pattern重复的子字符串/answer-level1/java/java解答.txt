```
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len=s.length();
       if(s==null||len<=1){
           return false;
       }
      for(int i=1;i<=len/2;i++){ //最大的子字符串为其一半
          if(len%i==0){
              int j=i;
              String str=s.substring(0,i);
              while(j<len&&s.substring(j,j+i).equals(str)){
                  j+=i;
              }
              if(j==len)
                  return true;
          }
      }
        return false;
    }
}
```

在浦发的机试中遇到了这个问题，写的差不多，通过率为0.最后好像发现是因为提交时得输出System.out.print("true"),
感觉真的太坑了，浪费了好多时间
