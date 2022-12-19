### 解题思路
此处撰写解题思路
我的思路:
    **利用稀疏数组的技巧，将原来的字符串进行压缩放入到稀疏数组！**
怎么使用？
    我这里的稀疏数组用的是字符串数组，所以当我存入下标的时候也是转换成字符串放入的。
    先将原来的字符串进行字符串统计，只统计存在字符串的，统计它们的个数
    再将个数分配给稀疏数组当作行，我这里的列只用了2列，因为只是一维数组的下表和字符串而已
    再逐个对稀疏数组进行匹配，如果参数和稀疏数组里面的i行1列相匹配的字符串那么就直接将当前的i行0列中的值返回，跳出循环！


### 代码

```java
class Solution {
    public int findString(String[] words, String s) {
        
        int sum=0;
        for(int i=0;i<words.length;i++){
            if(words[i].equals("")==false){
                    sum++;
            }
        }

        String xishu[][]=new String[sum][2];
        int j=0;
         for(int i=0;i<words.length;i++){
            if(words[i].equals("")==false){
                    xishu[j][0]=String.valueOf(i);
                    xishu[j][1]=words[i];
                    j++;
            }
        }
        int z=0;
        for(int i=0;i<sum;i++){
                if(xishu[i][1].equals(s)){
                    z=Integer.parseInt(xishu[i][0]);
                    break;
                }else{
                    z=-1;
                }
        }
        return z;
    }
}
```