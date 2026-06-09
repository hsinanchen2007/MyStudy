### 解题思路
此处撰写解题思路
我的思路:
    先用一个变量去统计一下原来数组中那些所有奇数的值，统计起来，方便我们创建一个这么大的值的数组
    数组创建完了以后，再变量原始数组的长度，从1 到 原始数组的总长度，然后根据判断i是否为奇数
    如果是奇数那么里面就循环这个奇数的次数，将原始数组当前i的值放入到新数组中，新数组每次都累加即可
    最后返回新数组，ok;
### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {

        int len=0;
        for(int i=1;i<=nums.length;i++){
            if(i%2==1){
                len=len+nums[i-1];
            }
        }




        int a[]=new int[len];
        int c=0;
        for(int i=1;i<=nums.length;i++){
            if(i%2==1){
                for(int j=1;j<=nums[i-1];j++){
                    a[c]=nums[i];
                    c++;
                }
            }
        }
        return a;
    }
}
```