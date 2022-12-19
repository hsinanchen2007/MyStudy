### 解题思路
执行用时 :
2 ms
, 在所有 java 提交中击败了
62.39%
的用户
内存消耗 :
34.5 MB
, 在所有 java 提交中击败了
100.00%
的用户

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        String [] ipsplit=address.split("\\.");
        ArrayList<String> ipstrlist = new ArrayList<String>();
        for(String s:ipsplit){
            ipstrlist.add(s);
        }
        ipstrlist.add(1,"[.]");
         ipstrlist.add(3,"[.]");
        ipstrlist.add(5,"[.]");
        String result=new String();
        for(String s:ipstrlist){
        result+=s;
        }
        return result;
    }
}
```