### 解题思路
写成注释形式,简单易懂,👇👇👇见下方代码(小白一个,大神勿喷)
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        char[] target = chars.toCharArray();
        //把系统给的String类型的chars转换成char数组存到变量taget中

        int[] temp = new int[26];
        //建立一个长度26的int数组,英文字母有26个,每个下标对应的是英文字母表顺序.
        //此temp数组用来存储对应下标字母在chars中出现几次,有几个

        int result = 0;
        //存最终结果,int类型

        for (char element : target){
        //定义一个字符遍历temp数组进行对应字符在chars中的数量计数

            temp[element-'a']++;
            //char与char相减可得int,注意这里的 'a'
	        //十六进制 对应字符 (ASCII编码表)
	        //  61	      a
	        //  64	      d
            //可以将这里的61看成0中心,所以减去它,=3 在temp数组中temp[3]正好是abc d,

        }
        for (String word : words){//遍历words数组

            char[] charString = word.toCharArray();
            //将words中每个单词(String类型元素word)转成字符数组

            int[] copyTemp = temp.clone();
            //clone()表示复制,连同数据以及地址一块复制

            int sum =0;//临时计数器

            for (char cS :charString){
                //将单词的每个字符遍历

                if (copyTemp[cS-'a']-->0) sum++;
                //如果某个元素的temp (copyTemp是复制的临时数据) 下标值大于0,也就是包含此值
                //给临时计数器sum进行+1,注意if里的细节, --  因为字符不能重复使用,所以用过就要减掉
            }
            if (sum==word.length()) result+=sum;
            //如果临时计数器等于了此次遍历的单词长度,说明chars中包含words[?]
            //根据题意,将此数据存到结果result中
        }
        return result;//结束
    }
}
```