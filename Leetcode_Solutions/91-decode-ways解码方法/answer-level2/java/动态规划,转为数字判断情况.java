执行结果：
通过
显示详情
执行用时 :
5 ms
, 在所有 Java 提交中击败了
39.64%
的用户
内存消耗 :
35.9 MB
, 在所有 Java 提交中击败了
31.71%
的用户
```
class Solution {
    public int numDecodings(String s) {
        int i1=1;
        int i2=1;
        int len = s.length();
        if(len==1){
            return Integer.parseInt(s)>0?1:0;
        }
        char ccc = s.charAt(0);
        if(ccc=='0'){return 0;}
        for(int i=1; i<len; i++){
            char c = s.charAt(i-1);
            char c2 = s.charAt(i);
            int val = Integer.parseInt(""+c+c2);
          
            if(val==0||c2=='0'&&c>'2'){
                return 0;
            }
              int temp=i1;
            if(val>=10&&val<27&&c2!='0'){
                i1=i1+i2;
            }
            else if(val==10||val==20){
                //maybe less in this case
                i1= i2;
            }
            i2=temp;
        }
        return i1;
    }
}
```
