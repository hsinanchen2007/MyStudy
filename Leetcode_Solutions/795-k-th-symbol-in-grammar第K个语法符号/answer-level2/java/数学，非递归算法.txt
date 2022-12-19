在草稿纸上进行观察就可以知道：第N层相当于是第 **N-1** 层的"二进制数" 链接上 其按位取反的结果。
所以第 **N** 层的 **K** 如果小于 **N-1** 层的个数，结果就等于第 **N** 层的 **K** 位数，
否则就是第 **N-1** 层的 **K - math.pow(N-2)** 位数数取反。
**所以设置一个监听变量 flag** ,记录 **K** 的变化次数。
最后 **N** 和 **K** 一定会落在 **第一行第一位(即0)** 上面。
所以只需要判断 **flag** 的奇偶性即可。
没有递归，没有真正对每一行数进行处理。
```
class Solution {
    public int kthGrammar(int N, int K) {
        if(K > Math.pow(2,N-1)){ //非法输入
            return -1;
        }
        int flag = 0;
   
        while(N > 1){    
            N = N-1;
            int pre = (int)Math.pow(2,N-1);
            if(K > pre){
                K = K - pre;
                flag++;
            }
        }
        
        if(flag % 2 == 0){
            return 0;
        }else{
            return 1;
        }
    }
}
```
