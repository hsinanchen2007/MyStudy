1.为了去重使用hashset
2.replaceAll去掉将'.'替换为空字符
3.substring截取+号前面的字符串
```
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set set = new HashSet();
        for (int i = 0; i < emails.length; i++){
            String[] address = emails[i].split("@");
            if(address[0].indexOf("+") < 0){
                set.add(address[0].replaceAll("\\.","") + "@" + address[1]);
            }else{
                set.add(address[0].substring(0,address[0].indexOf("+")).replaceAll("\\.","") + "@" + address[1]);
            }
        }
        return set.size();
    }
}
```
