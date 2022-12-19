![微信图片_20200323214316.png](https://pic.leetcode-cn.com/0efce8fc4af63463a3354c26da73145c2cfd951a78020d0250192d2e5d8368b5-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200323214316.png)

1、将5张牌排序，5个数排序，且数字范围为0-13，所以用桶排序最快O(N) 
2、用int[14]容量的桶，桶排序的过程若某个数（非0）出现次数超过1次，表明不可能为顺子，即返回false 
3、桶排序结束即可知道0的个数 
4、将桶遍历输出到容量为5的数组S中 
5、遍历数组S，若相邻两数i,i+1之差超过1，则dif+=S[i+1]-S[i]-1； 
6、当0的个数num0不足以替代dif时，返回false。
```java
class Solution {
    public boolean isStraight(int[] nums) {
        //桶排序
        int[] bucket = new int[14];
        for(int i = 0; i < nums.length; i++) {
            bucket[nums[i]]++;
            //若出现相同数，返回false
            if (nums[i] != 0 && bucket[nums[i]] > 1) {
                return false;
            }
        }
        int[] res = new int[5];
        int index = 0;
        int j = 0;
        int num0 = bucket[0];
        //将桶转换为容量为5的数组
        while(index < 5 && j < 14) {
            if (bucket[j] != 0) {
                res[index++] = j;
                bucket[j]--;
            }
            j++;
        }
        int dif = 0;
        for (int i = 0; i < 5; i++) {
            if (res[i]!= 0 && i+1 < 5 ) {
                dif+=(res[i+1]-res[i]-1);
            }
        }
        return dif <= num0;
    }
}
```