思路：
1.算出array1的总和sum1，array2的总和sum2。target=两个数组的总和除以2，得到每个数组需要达到的和。
2.在遍历array2的时候用Hashset记录array2中的每个不同值
3.其中一个数组需要在进行交换后，即减去其中一个元素再加上array2中的一个元素后，使得sum1=target。所以我们遍历array1，依次减去每一个元素，再判断array2中是否有值等于*target-(sum1-i)*，因为sum1-i+*target-(sum1-i)*=target。
4.如果array2中有target-(sum1-i)，说明它们交换之后满足数组和等于target。而我们用HashSet记录了array2中的值，所以直接利用contains函数判断即可。

因为只用到了一次for循环，所以时间复杂度为O(n+m)
代码如下：
```
class Solution {
    public int[] findSwapValues(int[] array1, int[] array2) {
        int sum1=0,sum2=0;
        Set<Integer> set=new HashSet<>();
        for(int i:array1){
            sum1+=i;
        }
        for(int i:array2){
            sum2+=i;
            set.add(i);
        }
        int sum=sum1+sum2;
        if(sum%2!=0)
            return new int[0];
        int target=sum/2;
        for(int i:array1)
            if(set.contains(target-(sum1-i)))
                return new int[]{i,target-(sum1-i)};
        return new int[0];
    }
}
```
