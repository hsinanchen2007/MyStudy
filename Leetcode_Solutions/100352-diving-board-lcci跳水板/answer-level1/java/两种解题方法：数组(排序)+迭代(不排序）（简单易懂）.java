// ### 解题思路
// ##方法一##
// 思路：利用数组实现
// 　　　1.判断数组长度（经过组合发现结果比所给木板块数多１）
// 　　　//k=3
// 　　　//i=0  3 0
// 　　　//i=1  2 1
// 　　　//i=2  1 2
// 　　　//i=3  0 3
// 　　　2.利用循环将所有的结果存储在数组中
// 　　　3.利用sort()方法对数组排序
// 　　　4.返回数组

// ### 代码

// ```java
class Solution {
    public int[] divingBoard(int shorter, int longer, int k) {
        //k个木板 由shorter和longer组成
        if(k==0){
            return new int[0];
        }
        if(k==1){
            return new int[]{shorter,longer};
        }
        int res=k*shorter;
        if(shorter==longer){
            return new int[]{res};
        }
        int[] nums=new int[k+1];
        for(int i=0;i<=k;i++){
            //k=3 3 0
            //i=1 2 1
            //i=2 1 2
            //i=3 0 3
            int tmp=shorter*(k-i)+longer*(i);
            nums[i]=tmp;
        }
       Arrays.sort(nums);
       return nums;
    }
}
// ```
// ##方法二
// 思路：迭代
// 　　1.由于题目要求返回长度由小到大排序，通过测试发现前后长度之差恰好是longer-shorter
// 　　2.直接把长度值存储
// 优势：
// 　　1.不需要排序
// 　　2.时间复杂度低
// ##代码##
// ```java
    public int[] divingBoard(int shorter, int longer, int k) {
        //1+1+1 1+1+2 1+2+2 2+2+2 多了longer-shorter
        if(k==0){
            return new int[0];
        }
        if(k==1){
            return new int[]{shorter,longer};
        }
        int res=k*shorter;
        if(shorter==longer){
            return new int[]{res};
        }
        int[] nums=new int[k+1];
        int tmp=longer-shorter;
        nums[0]=res;
        for(int i=1;i<=k;i++){
            res+=tmp;
            nums[i]=res;
        }
        return nums;
    }
// ```

// 结语：如有不足请多指教😊