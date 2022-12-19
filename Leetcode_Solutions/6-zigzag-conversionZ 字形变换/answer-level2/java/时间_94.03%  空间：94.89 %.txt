### 解题思路
此处撰写解题思路
将字符串的下标与z型变换后的每一行的元素位置联系起来
如：变换后的情况：
i从0-numrows-1
第一行元素的下标为:i, i + 2 * numRows - 2，i + （2 * numRows - 2）*2，...如果有
第二行元素的下标为：(多一个斜元素)
i, 2 * numRows - 2 - i（斜元素），i + 2 * numRows - 2，...如果有
....下面几行类似
### 代码

```java
class Solution {
    public static String convert(String s, int numRows) {
        if(numRows==1||s.length()<numRows){
            return s;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            sb.append(s.charAt(i));

            if(i>0&&i<numRows-1){
                int index = 2 * numRows - 2 - i;
                while(index<s.length()){
                    sb.append(s.charAt(index));
                    if(index+i*2<s.length()){
                        sb.append(s.charAt(index+i*2));
                    }
                    index += 2 * numRows - 2;
                }
            }else{
                int index = i + 2 * numRows - 2;
                while(index<s.length()){
                    sb.append(s.charAt(index));
                    index += + 2 * numRows - 2;
                }
            }

        }
        return sb.toString();
    }

}

```