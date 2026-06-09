### 解题思路
     * 思路1：
     *      暴力破解法
     *      将十进制转换陈二级制字符串，
     *      循环字符串的每一个字符
     *          前一个1的记录下标，下一次遇到是1的时候计算下表之间的距离，然后将前一个下表记录为当前下标
     *          下一次在遇到1的时候在记录下标计算差额，得到距离后和之前的距离比较取大值。
     *
     *  思路2：（未代码实现）
     *    使用栈
     *    当遇到1的时候开始入栈，等到第二次遇到1的时候计算栈的size为距离
     *    然后清空栈，在放入1如此反复获取最大的距离即可

    

### 代码

```java
class Solution {
    public int binaryGap(int N) {
       String str =  Integer.toBinaryString(N);

       int max = 0;
       int pre = -1;

       for (int i=0; i < str.length(); i++){
           int maxTemp;
           if(str.charAt(i) ==  '1') {
               // 表示第一次遇到
               if(pre == -1){
                   pre = i;
               } else {
                   maxTemp = i - pre;
                   if(maxTemp > max) {
                       max = maxTemp;
                   }
                   pre = i;
               }
           }
       }
       return max;
    }
}
```