**解法一：StringBuffer.reverse() 两行代码解决**
关于这道题，相信很多学 JAVA 的同学跟我一样第一次想到的是 StringBuffer 的 reverse() 方法，只需要两行代码就可以解决。
**思路：**
将数字转为字符串，反转后两个字符串一样则代表是回文数。
```
    public boolean isPalindrome(int x) {
       String rever = (new StringBuilder(x+"")).reverse().toString();
       return (x+"").equals(rever);
    }
```
**解法二：也是判断字符串**
**思路：**
上面的解法一，提交后发现，运行耗费时间居然20ms，内存占用 39.9M，这我能忍？不行我得优化。还是比较愚蠢。
首先，判断 x 是不是小于0. 如果 x < 0 则直接返回false。
其次将数字转换为字符串，再转换为 char[] 然后，一个指针从头开始，一个从尾部开始，依次比较，如果发现两者不一样就返回false。知道超过数组长度的一半。
比如`121`，无论对于奇数还是偶数都是适用的。
```
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        char[] array = (x+"").toCharArray();
        for(int i = 0; i< array.length/2;i++){
            if(array[i] != array[array.length-i-1]){
                return false;
            }
        }
        return true;
    }
```
**解法三：巧妙解法**
**思路：**
首先还是判断是不是负数如果是负数，返回`fasle`，还有如果是各位为0，并且它不是也返回`fasle`.
然后，既然上面字符可以判断，那么我们可不可以判断数字昵？将数字分为前后两半。如果前面和后面都一样那就是回文数。
对于数字 `1221`，如果执行 `1221 % 10`，我们将得到最后一位数字 `1`，要得到倒数第二位数字，我们可以先通过除以 `10` 把最后一位数字从 `1221` 中移除，`1221 / 10 = 122`，再求出上一步结果除以 `10` 的余数，`122 % 10 = 2`，就可以得到倒数第二位数字。如果我们把最后一位数字乘以 `10`，再加上倒数第二位数字，`1 * 10 + 2 = 12`，就得到了我们想要的反转后的数字。如果继续这个过程，我们将得到更多位数的反转数字。
```
    public boolean isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int revernumber = 0;
        while( x > revernumber){
            revernumber = revernumber*10 + x%10;
            x /= 10;
        }
       return (x == revernumber || x == revernumber/10);
    }
```
