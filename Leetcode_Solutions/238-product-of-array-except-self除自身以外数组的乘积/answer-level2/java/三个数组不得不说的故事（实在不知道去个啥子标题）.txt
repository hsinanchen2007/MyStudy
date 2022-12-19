提交结果：
执行用时 :2 ms, 在所有 Java 提交中击败了95.03% 的用户
内存消耗 :42.2 MB, 在所有 Java 提交中击败了96.20%的用户

思路：
     不让用除法属实有点搞，本来多简单的事啊。
     非得我想个法子，这个是就是灵机一动，觉得这样可行，就试了下，还真特么的可以  没啥好说的
     就是记录两个数组分别记录某个位置前的所有乘积和后的所有乘积，再两两相乘得到最终结果。
    

代码：
```
public int[] productExceptSelf(int[] nums) {
        int length = nums.length;
        int []res=new int[length];
        if (length==0)return res;
        int []forward=new int[length];//记录自身之前所有数的乘积
        int []backward=new int[length];//记录自身之后所有数的乘积
        forward[0]=1;//因为是乘法，第一个得设1才能进行
        backward[length -1]=1;//同理
        for (int i = 1; i < length; i++) {
            forward[i]=forward[i-1]*nums[i-1];//状态转移
            backward[length -1-i]=backward[length -i]*nums[length -i];//同理
        }
        for (int i = 0; i < length; i++) {
            res[i]=forward[i]*backward[i];
        }
        return res;
    }
```
