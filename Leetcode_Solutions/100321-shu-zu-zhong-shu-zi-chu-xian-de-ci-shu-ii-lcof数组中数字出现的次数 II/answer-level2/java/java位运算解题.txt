使用这个方法大概在20ms左右
![(_JU33AEUDG9PVKNICED8RJ.png](https://pic.leetcode-cn.com/10d8675fe37bbb574b40303690061a4143a11c2c989f4f6e3df29882eb2f5f41-\(_JU33AEUDG9PVKNICED8RJ.png)

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;

        for(int i = 0; i < 32; i++){
            int count = 0;
            for(int num : nums){
                if(((1 << i) & num) > 0){
                    count++;
                }
            }
            if(count % 3 == 1){
                ans += (1 << i);
            }
        }
        return ans;
    }
}

```
O(n)的算法，看到有人用这个算法，dubug了一下，才想明白这是个啥原理。其实很暴力。
int最大是32位，所以说遍历32次，这道题说必定3N+1个，比如说{3,7,7,7}
3:0000 0011
7:0000 0111
7:0000 0111
7:0000 0111
看出什么来没有？
第一位一共是4个1
第二位也是4个1
第三位是3个1
第一位加第二位为3
即count % 3 == 1，ant += 1 << i


利用hashmap保存然后遍历找到为1的值，大概在16ms左右，毕竟存取O(1)。
![05NQM1HTG3K$6L~QG8664\[T.png](https://pic.leetcode-cn.com/e65de01fdf4f028f9b84edde88c0704f14394bce84b70562c14d1e183b7840ca-05NQM1HTG3K$6L~QG8664%5BT.png)


```java
class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> temp = new HashMap<>();
        for(int num:nums){
            if(temp.get(num)==null){
                temp.put(num,1);
            }else{
                temp.put(num,temp.get(num)+1);
            }
        }
         for(int num:nums){
            if(temp.get(num)==1){
                return num;
            }
         }
        return -1;
    }
}

```
