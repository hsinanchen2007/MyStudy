### 解题思路
不是多好的方法，内存消耗比较大，但还是想做个记录。
总体思路就是：①遍历address ②找到.所在的位置 ③生成结果字符串。
具体见代码注释。
### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        StringBuffer ans = new StringBuffer(); //ans作为结果字符集的存放
        char isdot = ' '; //在遍历address时,用来判断某个字符是否为.
        int last_set = 0; //记录上一个.的下一个字符下标
        //遍历adress，在遍历过程中生成结果字符串
        for(int tra = 0; tra < address.length(); ++tra) {
            isdot = address.charAt(tra); //取出tra位置的字符 
            if(isdot == '.') { //判断是否为.
                ans.append(address.substring(last_set,tra) + "[.]"); //截取上一个.后与这一个.之间的数字
                last_set = tra + 1; // 将这一个.的下一个字符下标 更新为 上一个.的下一个字符下标 
            }
        }
        //循环结束，此时将最后一个.后的数字添加至结果字符串
        ans.append(address.substring(last_set,address.length())); 
        
        address = ans.toString();  //将ans赋值给address
        return address;
    }
}
```