### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public String defangIPaddr(String address) {
        String[] splits = address.split("\\.");//我们以.对这个字符进行分割
        StringBuffer stringBuffer = new StringBuffer();//建一个StringBuffer类主要用于后边的拼接
        for (String split : splits) {//循环的取出splits数组里的元素，然后在各元素后拼接上一个【。】
            stringBuffer.append(split + "[.]");
//出来的结果是这样的1【。】1【。】1【。】1【。】
        }
        return stringBuffer.toString().substring(0, stringBuffer.length() - 3);//我们这里把buffer转回字字符串后存用subString截取字符串，目的是把最后一个元素后的【。】去掉
    }
}
```