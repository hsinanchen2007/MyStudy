/**
 * 
 * author: zhaozhen
 * 
 * 解题思路：类似于暴力,主要检测当前十进制的二进制表示的1的个数
 * 
 * bitCount_jdk() //判断十进制的二进制表示的1的个数 jdk 源码
 * 
 */
```
    public List<String> readBinaryWatch(int num) {

        List<String> list = new ArrayList<>();
       for(int i = 0; i < 12;i++){
           int minute_one_num = num - Integer.bitCount(i);
           for(int j = 0;j < 60;j++){
                if(minute_one_num == Integer.bitCount(j)){
                    list.add(i + j>9?(""+j):("0"+j));
                }
           }
       }
       return list;
    }

    //二进制中1的个数
    public int bitCount_jdk(int i) {
        // HD, Figure 5-2
        i = i - ((i >>> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
        i = (i + (i >>> 4)) & 0x0f0f0f0f;
        i = i + (i >>> 8);
        i = i + (i >>> 16);
        return i & 0x3f;
    }
```