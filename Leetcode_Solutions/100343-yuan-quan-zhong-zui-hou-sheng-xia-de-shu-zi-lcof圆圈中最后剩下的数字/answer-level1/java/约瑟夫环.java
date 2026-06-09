删掉一个数字，就从下一位重新算。这相当于删掉一个数字，就把下一个位置下标往前挪m位，再把数组长度减一。这个过程中，上次幸存数字的(index-m)%(n-1)就还是幸存的。但是对于一个n位数组，这个幸存数字正好是要求的。只能逆过来找。已知数组长度为1时，没有数字被删，所以数组从2开始算起,从2一直增到n，数组长度每次+1。
```
class Solution {
    public int lastRemaining(int n, int m) {
        int last=0;
        for(int i=2;i<=n;i++){
            last=(last+m)%i;
        }
        return last;
    }
}
```
