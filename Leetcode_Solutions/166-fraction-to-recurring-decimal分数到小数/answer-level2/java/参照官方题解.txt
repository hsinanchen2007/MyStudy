执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
87.54%
的用户
内存消耗 :
34.5 MB
, 在所有 Java 提交中击败了
81.87%
的用户
```
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        if(denominator==0)return "";
        
        StringBuffer sb = new StringBuffer();
        if(numerator<0^denominator<0)sb.append("-");
        long d1 = Math.abs((long)numerator);
        long d2 = Math.abs((long)denominator);
        if(d1%d2==0){
           sb.append(d1/d2);
           return sb.toString();
        }
        sb.append(d1/d2);
        sb.append(".");
        long k = d1%d2;
        Map<Long,Integer> map = new HashMap<Long,Integer>();
        while(k!=0){
            if(map.get(k)!=null){
                sb.insert(map.get(k),"(");
                sb.append(")");
                return sb.toString();
            }
            map.put(k,sb.length());
            k=k*10;
            sb.append(k/d2);
            k=k%d2;
        }
        
        
        return sb.toString();
    }
    
}
```
