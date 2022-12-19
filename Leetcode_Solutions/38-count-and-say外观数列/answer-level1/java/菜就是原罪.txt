### 解题思路
菜
### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String res=new String("11");
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        res=_Work(res,n-1);
        return res;
    }

    private String _Work(String res, int lever) {
        if(lever==1)
            return res;
        int number=0;
        char tmp=res.charAt(0);
        String res1="";
        for(int i=0;i<res.length();i++){
            if(tmp==res.charAt(i)){
                number++;
            }
            else {
                res1+=number;
                res1+=tmp;
                number=1;
                tmp=res.charAt(i);
            }
        }
        res1+=number;
        res1+=tmp;
        return _Work(res1,lever-1);
    }
}
```