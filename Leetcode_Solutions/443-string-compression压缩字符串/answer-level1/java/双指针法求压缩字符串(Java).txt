### 前言
此题要求使用**原地算法**求解,即将压缩结果存在原chars[]数组中.

使用**双指针**即可求解此题.这里我们称由相同字符组成的字符串为**相同字符序列**.

**指针t**指示**已压缩的结果的末尾**,**指针i**指示**未压缩字符串的开头**.

遇到相同的字符,**指针i**便向后滑动,直到遇到不同字符.指针i**滑动的距离**即为**相同字符序列的长度**.

### 具体过程及解析如下:

```java
public int compress(char[] chars) {
        int t=0;//设置指针
        int i=0;
        while (i <chars.length && t<chars.length) {//遍历字符串
            chars[t++]=chars[i];//取相同字符序列的首字符存下
            int temp=i;//记录相同字符序列首元素位置
            while (i<chars.length &&chars[i]==chars[t-1])
                i++;//i指针滑动到相同字符序列末尾的下一个位置
            if(i-temp>1){//若相同字符序列长度大于1
                for(char c:String.valueOf(i-temp).toCharArray()){//向结果中加入相同字符序列的长度的字符形式
                    chars[t++]=c;
                }
            }
        }
        return t;//t即为已压缩的结果的长度
}
```