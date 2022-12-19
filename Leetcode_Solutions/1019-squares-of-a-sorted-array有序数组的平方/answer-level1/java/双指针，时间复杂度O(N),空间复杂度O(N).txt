class Solution {
    public int[] sortedSquares(int[] A) {
        int left=0;
        int right=A.length-1;
        //开辟数组空间
        int len=A.length;
        int[] target=new int[len];
        while(left<=right){
            //绝对值进行比较，哪个值大，哪个放在最后
            int aim=Math.abs(A[left])>Math.abs(A[right])?left++:right--;
            //从后往前给开辟的数组赋值
            target[--len]=A[aim]*A[aim];
        }
        return target;
    }
}