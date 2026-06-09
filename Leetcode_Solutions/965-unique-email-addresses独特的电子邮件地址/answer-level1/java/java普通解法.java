```
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> all=new HashSet<String>();  //去重的集合（set）来存放结果
        for(String email :emails){  //遍历
            int i=email.indexOf("@");  //获取@符号的位置
            String local=email.substring(0,i); //以@符号为分界线， 前半部分为local
            String host=email.substring(i); // @到最后的字符串为host
            if(local.contains("+")){  //如果local中包含+号，那么就会进行替换， 把+号到@符号部分的内容全部忽略
                local=local.replace(local.substring(local.indexOf("+")),""); 
                //先获取"+"号的位置，把使用substring方法进行切片，切片完成以后的值作为replace的参数，全部替换成空字符串""，最后将                                                                               //前面一系列结果重新赋值给local，那么就不会有影响了。
            }
            local=local.replace(".",""); // 符号"."的替换比较简单，忽略就可以，所以一句话就可以
            all.add(local+host); // 字符串的拼接
        }
        return all.size(); //返回大小，也就是种类。
    }
}
```