![2020032201.PNG](https://pic.leetcode-cn.com/648cea2fa71273bb0cb6b472bef55a70cc9a24a0c57aae80b3d26004b4284c48-2020032201.PNG)

### 解题思路
第一想法就是声明一个计数数组对出现数字的个数进行计数
1. 声明数组和变量：
--1) 声明计数数组 num, 索引为出现的数字, num的值为索引对应数字出现的次数, 由于A[i]最大值为40000, 因此声明num的长度为40000;

--2) 声明out记录需要使数组A符合提议的最少操作次数;

--3) 声明cnt记录当前出现重复数字的总数;

--4) 声明max记录数组A中出现的最大数字;

2. 先遍历一遍数组A将每个数字出现的次数记录在数组num中;

3. 再遍历一遍数组num (注: 遍历数组num时, 遍历长度要根据数组A中出现的实际最大数max来设置):

--1) 若num[i] > 1, 说明该数字出现至少两次以上, cnt = num[i]-1, 并且 out += cnt;

--2) 若num[i] == 1, 说明该数字恰好出现一次, 不需要对cnt进行操作, out += cnt;

--3) 若num[i] ==0, 说明该数字没有出现在数组A中, 若cnt！=0, 则将一个重复出现的数字填进当前位置, cnt--(重复数字出现个数减1), out+=cnt;

4. 遍历num结束后, 再判断cnt是否小于2：

--1) 若cnt小于2, 则直接返回out;

--2) 若cnt大于等于2, 说明还有cnt 个重复数字需要操作, 最后out 加上 使cnt个重复数字符合条件的操作数即可.

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        int[] num = new int[40001];
        int out = 0;
        int cnt = 0;
        int max = -1;
        for(int i=0;i<A.length;i++){
            num[A[i]]++;
            if(A[i]>max){
                max = A[i];
            }
        }

        for(int i=0;i<=max;i++){
            if(num[i]>1){
                cnt += num[i]-1;
                out += cnt;
            }else if(num[i]==0){
                if(cnt>0){
                    cnt--;
                }
                out += cnt;
            }else if(num[i]==1){
                out += cnt;
            }
        }

        // if(cnt>1){
        //     out = out + cnt*(cnt-1)/2;
        // }
        //上面的求和公式与下面的while循环的功能相同
        while(cnt>1){
            cnt--;
            out+=cnt;
        }
        return out;
    }
}
```