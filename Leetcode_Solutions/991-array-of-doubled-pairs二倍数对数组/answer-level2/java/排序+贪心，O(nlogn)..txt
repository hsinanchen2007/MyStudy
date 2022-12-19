分析题意：
&emsp;&emsp;就是要把所有的数都用上，并且满足后一个数是前一个数的2倍；
&emsp;&emsp;即：2 * A[0] == A[1], 2 * A[2] == A[3]，以此类推；
&emsp;&emsp;注意:A[1]和A[2]没要求.

贪心选择证明：
+ 1)只要每次选最小的，若为正数，再找到一个数为当前最小值的2倍即可，如找不到直接false;
     + 证明:因为我们选出了一个最小的数A，而所有的数都必须用上，只能是找另一个数B满足2 * A == B;若欲满足2 * B == A，那么A就不是最小值，矛盾。
* 2)若为负数A，就找数B满足 B == A/2即可。(若该负数A为奇数直接false)
* 3)0的话就再找一个0即可。


```
class Solution {
    final int N = 100000;   //N为题中每个数的最大值
    int[] cnt = new int [N * 2 + 10]; //cnt记录每个数出现的次数，因为有负数，cnt为N的2倍多
    public boolean canReorderDoubled(int[] A) {
        Arrays.sort(A);
        for(int k : A) cnt[k + N]++;    //统计A数组中每个数的次数
        int n = A.length;
        for(int i = 0, j = 0; i < (n >> 1); i++){
            while(cnt[A[j] + N] == 0) j++;  //j 从0开始找到当前存在的最小值
            int idx = 0;    //表示欲找的值的下标
            if(A[j] < 0){   //当前最小值为负数
                if(A[j] % 2 != 0) return false; //奇数直接false
                idx = binarySearch(A, 0, n - 1, A[j] >> 1);    //找当前最小值的一半
                if(A[j] != 2 * A[idx] || cnt[A[idx] + N] == 0) return false;    //判断是否找到，以及是否存在
            }else if(A[j] > 0){ //当前最小值为整数
                idx = binarySearch(A, 0, n - 1, A[j] << 1);     //找当前最小值的2倍
                if(2 * A[j] != A[idx] || cnt[A[idx] + N] == 0) return false;    //判断是否找到，以及是否存在
            }else if(cnt[A[j] + N] > 1) idx = j;    //当前最小值为0就判断是否存在2个0
            else return false;  //否则直接false
            //在cnt中把用过的值的次数减1
            cnt[A[j] + N]--;    
            cnt[A[idx] + N]--;
        }
        return true;
    }
    //二分搜索
    int binarySearch(int[] A, int l, int r, int x){
        while(l < r){
            int mid = l + r >> 1;
            if(x <= A[mid]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}
```
