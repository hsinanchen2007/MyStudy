### 解题思路
递归生成所有可能的字符串，符合条件的字符串添加到list中

### 代码

```java
class Solution {
    private static List<String> list;
    public List<String> generateParenthesis(int n) {
        //new一个ArrayList
        list = new ArrayList<String>();
        //n*2是字符长度
        count("",n*2);
        return list;
    }

    //生成字符串的递归函数
    public void count(String str,int n){
        if(str.length()<n){//长度不够时继续递归
            count(str+"(",n);
            count(str+")",n);
        }else if(str.length()==n){//长度符合条件时判断字符串的括号是否匹配
            if(match(str)){//匹配则添加到list中
                list.add(str);
            }
        }
    }

    //判断字符串的括号是否匹配
    public boolean match(String str){
        String[] a=str.split("");
        int count=0;
        for(int i=0;i<a.length;i++){
            if(a[i].equals("(")){
                count++;
            }else{
                count--;
            }
            if(count<0){//匹配的字符串，计算过程中count不可能是负数
                return false;
            }
        }
        if(count==0){//最后count为0时，符号才是匹配的
            return true;
        }else{
            return false;
        }
    }
}
```