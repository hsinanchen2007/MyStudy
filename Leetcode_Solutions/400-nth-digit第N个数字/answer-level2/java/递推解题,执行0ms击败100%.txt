- 解题
    - 从1到n的数列中找到指定位置k的数字
    - 位置k的规则是从1到n的依次出现的数字计数。
- 思路
    1.暴力方法从前向后计数，直到找到k,时间复杂度O(k) 执行超时，但是在写代码时可以注意到计数规律
    2.递推，从暴力计数时可以发现，m位数的所有数字总数规律：
    **count=i*（pow（10，m）-pow（10，m-1））**
    规律： 
        - m=1，count=1*（10-1）=9
        - m=2，count=2*（100-10）
        - m=3  count=3*（1000-100）
    因此我们可以使用递推比较m位之前所有总数Countall和k的大小，并获取到k所在的是几位数，后面就是简单的查找到k在哪个数字中，并找到该数字了。
    - 时间复杂度：由于n<pow(2,31)，因此最多用到i=9，也就是9位数，只需要最多9次循环找到位数i，然后在确定的数字中查找具体数字。O(1)级别吧
    
- 方法
```java []
 /**
     * 暴力破解，会超时
     * @param n
     * @return
     */
    public int findNthDigit(int n) {
        int k=1;
        n--;
        while (n>0){
            n=n-getlength(k);
            k++;

        }

        if (n==0){
            return k/(int) Math.pow(10,getlength(k)-1);
        }else{
            int rtn=0;
            k=k-1;
            for (int i = n; i <0 ; i++) {
                rtn=k%10;
                k/=10;
            }
        return rtn;
        }
    }
    private int getlength(int i){
        int length=0;
        while(i!=0){
            length++;
            i/=10;
        }
        return length;
    }

    /**
     * 递推计算
     * @param n
     * @return
     */
    public int findNthDigit1(int n) {
        int maxi=0;
        int i=1;
        while(n>maxi+i*(Math.pow(10,i)-Math.pow(10,i-1))) {
            maxi+=i*(Math.pow(10,i)-Math.pow(10,i-1));
            i++;
        }
        n-=maxi;
        n--;
        int remain=n%i;
        int counter=n/i;
        int inwhich=(int) Math.pow(10,i-1)+counter;

            int rtn=0;

            for (int j = 0; j <i-remain ; j++) {
                rtn=inwhich%10;
                inwhich/=10;
            }
            return rtn;
        }
```