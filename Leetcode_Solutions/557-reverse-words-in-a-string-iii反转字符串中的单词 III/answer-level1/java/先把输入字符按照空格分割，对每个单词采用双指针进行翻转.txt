![image.png](https://pic.leetcode-cn.com/be8ceced31bdf8c44fa20d6a934e30cd02b6ec77eebcab7fb4a9be2c29ed0231-image.png)

```
public  String reverseWords(String s) {
            if (s==null)
                return null;
            String[] strings = s.split(" ");
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i <strings.length ; i++) {
                stringBuilder.append(reverseEachWords(strings[i].toCharArray())).append(" ");
            }
            stringBuilder.delete(stringBuilder.length()-1,stringBuilder.length());
            String string = stringBuilder.toString();
            return string;
        }

        private  String reverseEachWords(char[] s) {
            if (s.length<2)
                return new String(s);
            int i=0,j=s.length-1;
            while (i<j){
                char temp = s[i];
                s[i] = s[j];
                s[j]= temp;
                i++;
                j--;
            }
            return new String(s);
        }
```
