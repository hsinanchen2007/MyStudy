### 解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        //双指针  前指针指向单词头 后指针指向单词尾部
        int pre = 0;
        int back = 0;

        char[] str = s.toCharArray();
        
        //当back指针指到字符串尾部的时候进行最后一次循环
        while(back < str.length){
            //当back发现一个空格或者back指向字符串尾端时候开始反转处理
            if(str[back] == ' ' || back == str.length - 1){
                //当是指到字符串尾的时候调整back指针
                if(back == str.length -1)back++;
                //计算交换该单词所需要的次数
                int charLength = back - pre;
                //交换
                for(int i = 0; i < charLength/2; i++){
                    char temp = str[pre + i] ;
                    str[pre + i] = str[back - 1 -i];
                    str[back -1 -i] = temp;
                }
                //调整前后指针
                back++;
                pre = back;
            }else{
                back++;
            }
        }

         return new String(str);
    }
}
```