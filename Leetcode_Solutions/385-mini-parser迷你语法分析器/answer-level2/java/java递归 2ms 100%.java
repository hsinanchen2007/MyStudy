设定一个`getNest()`函数用于返回一个列表类型的NestedInteger。

重要的思想是通过类的全局字符数组和一个下标值让每次调用递归函数都知道要处理哪个位置。

```java
class Solution {
    //递归函数通过字符数组和cur下标确定要处理的位置
    char[] chars;
    int cur = 0;
    public NestedInteger deserialize(String s) {
        chars = s.toCharArray();
        //本身不是一个集合而是一个整数的情况
        if(chars[0]!='[') return new NestedInteger(Integer.valueOf(s));
        //调用递归函数返回根集合
        return getNest();
    }
    public NestedInteger getNest(){
        NestedInteger nest = new NestedInteger();
        int num = 0;//num用于缓存用逗号分割的整数类型的值
        boolean negative = false;//当前记录的整数是不是负数
        while(cur!=chars.length-1){
            cur ++;
            if(chars[cur]==',') continue;
            if(chars[cur]=='[') nest.add(getNest());//遇到[递归获取子集合
            else if(chars[cur]==']') return nest;
            else if(chars[cur]=='-') negative = true;
            else{//是数字的情况
                if(negative) num = 10*num - (chars[cur]-48);
                else num = 10*num + (chars[cur]-48);
                //如果下一个字符是,或者]说明当前数字已经记录完了，需要加入集合中
                if(chars[cur+1]==','||chars[cur+1]==']'){ 
                    nest.add(new NestedInteger(num));
                    num = 0;
                    negative = false;
                }
            }
        }
        return null;
    }
}
```