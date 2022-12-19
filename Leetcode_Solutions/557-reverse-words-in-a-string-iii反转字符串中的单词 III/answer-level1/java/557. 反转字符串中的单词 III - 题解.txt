##### 两种实现方式

#### 一. Java StringBuffer reverse()方法反转调用该方法的StringBuffer对象的值; 
1. 令n为旧字符序列的长度，即在执行反向方法之前字符串缓冲区中包含的字符序列。
2. 新字符序列中索引k处的字符等于旧字符序列中索引n-k-1处的字符
```
public static String reverseWords(String soure) {
        String target = "";
        //字符串拆分成数组
        String[] temp = soure.split(" ");
        for (int i = 0; i < temp.length; i++) {
            // 利用StringBuffer.reverse() 将字符逆序
            if (i == temp.length - 1) {
                target = target + new StringBuffer(temp[i]).reverse().toString();
            } else {
                target = target + new StringBuffer(temp[i]).reverse().append(" ").toString();
            }

        }
        return target;
    }
```
> 但是内存消耗比较大 (执行后可比较下)

#### 二. 利用数组双指针思想：
1. 划分子数组
2. 子数组双指针交换；
3. 生成字符串
```
public static String reverseWords(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }
        // 将字符串转化为数组
        char[] arr = s.toCharArray();
        int l = 0;
        int r = 0;
        //
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == ' ') {
                while (l < r) {
                    char t = arr[l];
                    arr[l] = arr[r];
                    arr[r] = t;
                    l++;
                    r--;
                }
                l = i + 1;
                r = i + 1;
            } else {
                r = i;
            }
        }
        while (l < r) {
            char t = arr[l];
            arr[l] = arr[r];
            arr[r] = t;
            l++;
            r--;
        }
        return new String(arr);
    }
```
![image.png](https://pic.leetcode-cn.com/eeb7526f5978b2ace33e29431a9196b02166e17fc69ce3b275d3000d01abdb3f-image.png)

两次的执行结果
![image.png](https://pic.leetcode-cn.com/3fcc4c44f259acff3cc493d55ddc136e93a6580b11c8408c96ab1363b4205940-image.png)





