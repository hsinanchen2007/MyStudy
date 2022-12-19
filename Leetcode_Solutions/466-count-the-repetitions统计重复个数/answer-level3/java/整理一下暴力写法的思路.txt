### 解题思路
此处撰写解题思路
1. 首先对n1,n2进行最大公约数化简 
例如 n1= 100 n2 = 10 那么最大公约数 divisor = 10 ==> 这样 n1= 10 n2= 1可以减少长度了。
2. **找到s1 和 s2的匹配规律**，即为 m * s1 = n * s2 (m >= 1, n>=1),就是m个s1可以转换为n个s2
3. 由于n1,n2的长度是有限的，因此在2中存在两种可能 :
  于是我们使用了一个标志位flag判断是否成功找到了m,n.
  同时在寻找过程中使用数组index 记录i个s1匹配了k个s2
    - 3-1**找到了这样的m,n**;
        count = ( (n1 / m) * n + index.get(n1 % m) ) / n2
    - 3-2**没找到这样的m,n**
        count = index.get(n1) / n2;
4. count 就是最后匹配的结果了
### 代码

```java
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if (n1 == 0 || n2 == 0) return 0;

        //1.找到n1,n2的最大公约数
        int divisor = getCommonDivisor(n1, n2);
        n1 /= divisor;
        n2 /= divisor;

        int len1 = s1.length(), len2 = s2.length();
        int i = 0, j = 0;
        boolean flag = false; //增加一个标志位
        List<Integer> index = new ArrayList<>(); //表示第i个位置匹配j
        index.add(0);
        //2.找到 m * s1 = n * s2
        while (i < len1 * n1) {
            if (s1.charAt(i % len1) == s2.charAt(j % len2)) {
                j++;
            }
            i++;
            //m * s1 = n * s2
            if (i % len1 == 0) {
                index.add(j);  //改为每 len1计数1次
                if (j % len2 == 0) {
                    i = i / len1;
                    j = j / len2;
                    flag = true;
                    break;
                }

            }
        }
        //此时 i * s1 = j * s2;
        //1.判断n1 = k * i;
        int count = 0;
        if (flag) {
            count += n1 / i * j;
            count += index.get(n1 % i) / len2;
            count /= n2;
        } else {
            //没有找到m，n
            count = index.get(n1) / len2;
            count /= n2;
        }

        return count;
    }

    //辗转相除法：获取两个数的最大公约数
    int getCommonDivisor(int m, int n) {
        if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }
        int a;
        // 辗转相除法的核心就是用较大的数n去除较小的数m，如果刚好能整除，则m与n的最大公约数为m，
        // 如果不能整除，则将m的值赋给n，余数r赋给m，再进行下一次的相除，以此循环，直到整除为止
        while ((a = n % m) != 0) {
            n = m;
            m = a;
        }
        return m;
    }
}
```