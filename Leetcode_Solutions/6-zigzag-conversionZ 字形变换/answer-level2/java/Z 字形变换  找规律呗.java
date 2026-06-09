

![image.png](https://pic.leetcode-cn.com/33874e291368bc6826202209d20960a00d3951df8ca7ffad7ed73d15ad3ac71c-image.png)

### 土方法 找规律呗   
    除了第一行和最后一行 之外的行规律不变都是按照  :（总列-1）x 2
    其他行的规律就是 ：
    第一个数（奇数） 到第二个数的 距离就是  （总列-当前行）x 2
    比如第二行的  2到8  z型要走过 3、4、5、6、7、8==>6   (5列 -当前第2行)*2==>6
    第二个数 （偶数） 到第三个数的 距离就是  （当前行-1 ）x 2
    比如第二行的  8到10 z型要走过 9，10 ==>2  (当前第2行-1)*2==>2
    
    算出当前行的奇偶 就必须减去 前面几行总个数。

这个方法执行耗时  4ms  

```
 public String convert(String s, int numRows) {
        if (numRows==1){
            return  s;
        }
        int curfloor = 1;
        int index = 0;
        int preCount =0;//前几行的数量
        //当前 i - preCount 为了得出当前行 当前位置是奇数还是偶数个
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char curChra = s.charAt(index);
            //单数+ (numRows-curfloor)*2;
            //双数+ (curfloor-1)*2;
            if (curfloor == numRows) {
                index = index + (numRows - 1) * 2;

            } else if (curfloor == 1|| (i-preCount) % 2 == 1 ) {
                index = index + (numRows - curfloor) * 2;
            }
            else if ((i-preCount) % 2 == 0) {
                //双数
                index = index + (curfloor - 1) * 2;
            }
            
            // 下一行的z型开始
            if (index >=s.length()) {
                curfloor++;
                index = curfloor - 1;
                preCount =i;
            }
            builder.append(curChra);
            // System.out.println(builder.toString());
        }

        return builder.toString();
    }
```







