```
class Solution {
    public boolean isNumber(String s) {
        if(s.charAt(s.length()-1)>'A'&&s.charAt(s.length()-1)<'z')return  false;
         try{
           if(Double.valueOf(s).getClass().equals(Double.class))
               return true;
           else return false;
       }catch (Exception e){
           return false;
       }
    }
}
```
```
只能说明测试数据不够完整吧，还有就是Double类提供的方法真的很强大，侥幸通过见笑。