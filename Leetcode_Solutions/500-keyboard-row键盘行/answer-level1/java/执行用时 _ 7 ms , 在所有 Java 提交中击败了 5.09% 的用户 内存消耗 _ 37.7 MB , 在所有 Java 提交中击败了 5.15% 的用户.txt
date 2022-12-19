### 解题思路
就是正常的思路，首先编写键盘每一行作为一个字符串，取给定的每一个字符串，逐个字符比较，如果全部遍历完毕都在该行键盘组成的字符串中，则可以输出，否则不输出。

### 代码

```java
class Solution {
    public String[] findWords(String[] words) {
        String s1 = "QWERTYUIOPqwertyuiop";
        String s2 = "ASDFGHJKLasdfghjkl";
        String s3 = "ZXCVBNMzxcvbnm";
        int count = 0;
        String[] arr = new String[words.length];
        for(String ss:words) {
            boolean flag = true;
            if(s1.contains(ss.charAt(0)+"")) {
                for(int i = 0;i<ss.length();i++) {
                    if(!s1.contains(ss.charAt(i)+"")) {
                        flag = false;
                        break;
                    }
                }
            if(flag) {
                arr[count++] = ss;
                flag = true;
            } 
        }

        if(s2.contains(ss.charAt(0)+"")) {
                for(int i = 0;i<ss.length();i++) {
                    if(!s2.contains(ss.charAt(i)+"")) {
                        flag = false;
                        break;
                    }
                }
            if(flag) {
                arr[count++] = ss;
                flag = true;
            } 
        }

        if(s3.contains(ss.charAt(0)+"")) {
                for(int i = 0;i<ss.length();i++) {
                    if(!s3.contains(ss.charAt(i)+"")) {
                        flag = false;
                        break;
                    }
                }
            if(flag) {
                arr[count++] = ss;
                flag = true;
            } 
            }

        }
        String[] brr = new String[count];
        for(int i = 0;i<count;i++) {
            brr[i] = arr[i];
        }
        return brr;
    }
}
```